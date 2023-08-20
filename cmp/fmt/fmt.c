//
// Created by Piotr Krzysztof Wyrwas on 20.08.23.
//

#include <stdlib.h>
#include <stdbool.h>

#include "fmt.h"

static char lastC = 0;

int reformat(struct CompilerEnv *env)
{
        sanity_check_env(env);

        for (; env->offset < env->len; env->offset++)
                if (_reformat_next(env)) return EXIT_FAILURE;

        if (env->loop_ct != 0) {
                printf("[ERR] There are unclosed loops left in the code.\n");
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
}

int _reformat_next(struct CompilerEnv *env)
{
        ENV_CURR(c)

        static _Bool newline;
        static _Bool newline_long;

        newline_long = newline;

        // We don't care about any non-brainfuck characters
        if (!IS_PRIMITIVE(c) && c != '[' && c != ']')
                return EXIT_SUCCESS;

        // If the last character is a loop character, we want to add
        // some fitting indentation
        if (newline) {
                fprintf(env->out, "%s", repeat('\t', (c == ']') ? env->indent - 1 : env->indent));
                newline = false;
        }

        // If the character is primitive (+-><.,) just print it as-is, since the above conditional
        // will take care of the indentation
        if (IS_PRIMITIVE(c)) {
                fprintf(env->out, "%c", c);
                goto exit_ok;
        }

        // In case of a loop-opening symbol, go to the next line and increment the indentation step
        if (c == '[') {
                if (IS_PRIMITIVE(lastC))
                        fprintf(env->out, " ");
                fprintf(env->out, "[\n");
                newline = true;
                env->indent++;
                goto exit_ok;
        }

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
