//
// Created by Piotr Krzysztof Wyrwas on 22.08.23.
//

#include <stdio.h>

static const char *help_page = "natron\n"
                               "    --source file_name    | Source file   } The purpose of these files remains the same,\n"
                               "    --output file_name    | Output file   } no matter the mode of operation.\n"
                               "\n"
                               "    --compile             | Default mode of operation. Compile to C.\n"
                               "    --reformat            | Reformat the brainfuck source code";

void show_help() {
        printf("%s\n", help_page);
}
