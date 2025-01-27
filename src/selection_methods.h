#ifndef HAS_SELECTION_METHOD_H
#define HAS_SELECTION_METHOD_H

#include <argp.h>

#include "argument_parser.h"

enum selection_method get_selection_method(
    struct commandline_arguments *args);

char *choose_item_from_cmdargs(
    struct commandline_arguments *cmdargs);

#endif

