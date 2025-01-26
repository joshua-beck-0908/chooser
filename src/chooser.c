#include <stdio.h>
#include <stdlib.h>
#include <argp.h>

#include "chooser.h"

const char *argp_program_version = "chooser 1.0";
const char *argp_program_bug_address = "<joshua.beck.0908@gmail.com>";
const char description[] = "A random decision marker.";
const char argument_description[] = "OPTION_1, OPTION_2, ...";

static struct argp_option commandline_options[] = {
    { 0 }
};

static struct argp argparser = {
    commandline_options,
    option_parser,
    argument_description,
    description,
    0,
    0,
    0
};

int main(int argc, char *argv[]) {
    struct commandline_arguments input_args;

    parse_commandline_arguments(argc, argv, &input_args);
    //get_selection_method(&input_args);
    //get_list_of_options(&input_args);
    //choose_item_from_list();
    //display_results();
}

int parse_commandline_arguments(int argc, char **argv, 
    struct commandline_arguments *outputs) {

    argp_parse(&argparser, argc, argv, 0, 0, outputs);
    for (int i = 0; i < outputs->number_of_options; i++) {
        printf("Option %d: %s\n", i, outputs->list_of_options[i]);
    }
    return 0;
}

static error_t 
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