#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include <time.h>

#include "chooser.h"
#include "argument_parser.h"
#include "selection_methods.h"

void seed_random_number_generator() {
    srand((unsigned int) time(NULL));
}

int main(int argc, char *argv[]) {
    struct commandline_arguments input_args;
    char *result;

    seed_random_number_generator();
    parse_commandline_arguments(argc, argv, &input_args);
    result = choose_item_from_cmdargs(&input_args);
    printf("Result: %s\n", result);
}

