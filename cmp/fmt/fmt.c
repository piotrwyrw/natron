//
// Created by Piotr Krzysztof Wyrwas on 20.08.23.
//

#include <stdlib.h>
#include <stdbool.h>

#include "fmt.h"
#include "../color.h"

static char lastC = 0;

static int reformat_next(struct CompilerEnv *env);

int reformat(struct CompilerEnv *env)
{
        sanity_check_env(env);

        for (; env->offset < env->len; env->offset++)
                if (reformat_next(env)) return EXIT_FAILURE;

        if (env->loop_ct != 0) {
                ERROR("There are unclosed loops left in the code.\n");
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
}

static int reformat_next(struct CompilerEnv *env)
{
        CURRENT_CHAR(c)

        static _Bool newline;
        static _Bool newline_long; /* A snapshot of `newline` from the beginning of the function. Occasionally useful */

        newline_long = newline;


        /* Check for comments */
        if (c != '#') {
                goto not_a_comment;
        }

        size_t skip = skip_comment(env);

        /* If the last character written to the output was a newline, we just have to write the indentation tabs */
        if (newline) {
                fprintf(env->out, "%s", repeat('\t', env->indent));
        } else {
                /* Or if a newline wasn't present, write a single space to visually separate the comment form the code */
                fprintf(env->out, " ");
        }

        /* If the comment occupies the entire line in the origin source code, let it do so here as well */
        if (!newline && is_comment_line(env) && lastC) {
                fprintf(env->out, "\n%s", repeat('\t', env->indent));
        }

        /* Just print the comment step-by-step */
        for (size_t i = env->offset; i < skip + env->offset; i++) {
                c = env->src[i];
                fprintf(env->out, "%c", c);
        }

        /* Since this is a line comment, we need to switch to a new line afterward to prevent commenting out code */
        fprintf(env->out, "\n");

        /* 'Jump over' the comment with the offset variable */
        env->offset += skip;

        newline = true;

        return EXIT_SUCCESS;

        not_a_comment:

        /* Non-brainfuck characters are not allowed in the source code - We have comments for that */
        if (is_illegal_op(c)) {
                FAIL_WRONG_OP(c) /* See `trans.h` */
        }

        /* If the last character is a loop character, we want to add */
        /* some fitting indentation */
        if (newline) {
                fprintf(env->out, "%s", repeat('\t', (c == ']') ? env->indent - 1 : env->indent));
                newline = false;
        }

        /* If the character is primitive (+-><.,) just print it as-is, as the condition above */
        /* will take care of the indentation */
        if (is_primitive(c)) {
                fprintf(env->out, "%c", c);
                goto exit_ok;
        }

        /* In case of a loop-opening symbol, go to the next line and increment the indentation step */
        if (c == '[') {
                if (is_primitive(lastC) && !newline_long)
                        fprintf(env->out, " ");
                fprintf(env->out, "[\n");
                newline = true;
                env->indent++;
                goto exit_ok;
        }

        /* Close the loop in a similarly visually appealing manner */
        if (c == ']') {
                if (lastC != '[' && !newline_long)
                        fprintf(env->out, "\n");
                fprintf(env->out, "]\n");
                env->indent--;
                newline = true;
                goto exit_ok;
        }

        exit_ok:
        lastC = c;
        return EXIT_SUCCESS;
}
