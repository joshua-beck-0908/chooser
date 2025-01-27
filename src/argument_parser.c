#include <argp.h>

#include "argument_parser.h"
#include "errors.h"

const char *argp_program_version = "chooser 1.0";
const char *argp_program_bug_address = "<joshua.beck.0908@gmail.com>";
const char description[] = "A random decision marker.";
const char argument_description[] = "OPTION_1, OPTION_2, ...";

static struct argp_option commandline_options[] = {
    { "method", 'm', "VALUE", 0, "The randomization type to use.", 0 },
    { 0 }
};

struct argp argparser = {
    commandline_options,
    option_parser,
    argument_description,
    description,
    0,
    0,
    0
};

int parse_commandline_arguments(int argc, char **argv, 
    struct commandline_arguments *outputs) {

    argp_parse(&argparser, argc, argv, 0, 0, outputs);
    for (int i = 0; i < outputs->number_of_options; i++) {
        printf("Option %d: %s\n", i, outputs->list_of_options[i]);
    }
    return 0;
}

error_t 
option_parser(int argname, char *argvalue, struct argp_state *state) {
    struct commandline_arguments *outputs = state->input;
    switch (argname) {
        case ARGP_KEY_ARG:
            if (state->arg_num >= MAXIMUM_OPTION_COUNT) 
                fatal_error_and_help("Too many options given.", state);
            outputs->list_of_options[state->arg_num] = argvalue;
            outputs->number_of_options = state->arg_num + 1;
            break;
        case ARGP_KEY_END:
            if (state->arg_num < 2) 
                fatal_error_and_help("Not enough options!", state);
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}