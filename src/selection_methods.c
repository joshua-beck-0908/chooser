#include <stdlib.h>

#include "selection_methods.h"

enum selection_method get_selection_method(
struct commandline_arguments *args) {
    (void)args;
    return SELECTION_METHOD_FAIR_SPLIT;
}

int get_random_number_between_min_and_max(int min, int max) {
    int n = rand();
    n = n % (max - min) + min;
    return n;
}

char *choose_item_from_cmdargs(
struct commandline_arguments *cmdargs) {
    int option;
    enum selection_method selector;
    
    selector = get_selection_method(cmdargs);
    switch (selector) {
        case SELECTION_METHOD_FAIR_SPLIT:
            option = get_random_number_between_min_and_max(0,
                cmdargs->number_of_options);
            printf("Random value was %d\n", option);
            return cmdargs->list_of_options[option];
            
        default:
            return "";
    }
}
            

            