#ifndef HAS_ERRORS_H
#define HAS_ERRORS_H

#include <argp.h>

_Noreturn void fatal_error(char *error_message);
_Noreturn void fatal_error_and_help(char *error_message,
    struct argp_state *state);

#endif