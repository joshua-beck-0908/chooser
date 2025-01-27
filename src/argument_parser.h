#ifndef HAS_ARGPARSER_H
#define HAS_ARGPARSER_H

#include <argp.h>

enum selection_method {
    SELECTION_METHOD_FAIR_SPLIT,
    SELECTION_METHOD_DICE,
};

#define MAXIMUM_OPTION_COUNT 10
struct commandline_arguments {
    char *list_of_options[MAXIMUM_OPTION_COUNT + 1];
    int number_of_options;
    enum selection_method method;
};

int parse_commandline_arguments(int argc, char **argv, 
    struct commandline_arguments *outputs);

error_t option_parser(int argname, char *argvalue, struct argp_state *state);

#endif