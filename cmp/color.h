//
// Created by Piotr Krzysztof Wyrwas on 21.08.23.
//

#ifndef BFCMP_COLOR_H
#define BFCMP_COLOR_H

/**
 * Credit: https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
 */

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define CLR_PRINTF(clr, ...) {\
        printf("%s", clr);      \
        printf(__VA_ARGS__);  \
        printf("%s", ANSI_COLOR_RESET);\
}

#define ERROR(...) { \
        CLR_PRINTF(ANSI_COLOR_RED, "[ERR] ")             \
        CLR_PRINTF(ANSI_COLOR_RED, __VA_ARGS__) \
}

#define OK(...) { \
        CLR_PRINTF(ANSI_COLOR_GREEN, "[OK] ")          \
        CLR_PRINTF(ANSI_COLOR_GREEN, __VA_ARGS__) \
}

#endif //BFCMP_COLOR_H
