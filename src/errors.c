#include <stdio.h>
#include <stdlib.h>
#include "errors.h"


_Noreturn void fatal_error(char *error_message) {
    fprintf(stderr, "Error: %s\n", error_message);
    exit(EXIT_FAILURE);
}

_Noreturn void fatal_error_and_help(char *error_message,
    struct argp_state *state) {
        
    fprintf(stderr, "Error: %s\n", error_message);
    argp_usage(state);
    exit(EXIT_FAILURE);
}

