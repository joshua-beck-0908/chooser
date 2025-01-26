#ifndef HAS_CHOOSER_MAIN
#define HAS_CHOOSER_MAIN
#include <stdlib.h>
#include <argp.h>

#define MAXIMUM_OPTION_COUNT 10
struct commandline_arguments {
    char *list_of_options[MAXIMUM_OPTION_COUNT];
    int number_of_options;
};

int parse_commandline_arguments(int argc, char **argv, 
    struct commandline_arguments *outputs);
_Noreturn void fatal_error(char *error_message);
_Noreturn void fatal_error_and_help(char *error_message,
    struct argp_state *state);
static error_t option_parser(int argname, char *argvalue, struct argp_state *state);

#endif
