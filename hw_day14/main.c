#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    init_stack_array(10);

    my_push((A){ .data = 1 });
    print_elems();

    my_push((A){ .data = 2 });
    print_elems();

    my_push((A){ .data = 3 });
    print_elems();

    my_pop(NULL);
    print_elems();

    my_push((A){ .data = 4 });
    print_elems();

    my_pop(NULL);
    print_elems();

    my_pop(NULL);
    print_elems();

    free(arr_begin);
    init_stack_array(20);

    return 0;
}