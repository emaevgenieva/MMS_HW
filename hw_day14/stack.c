#include<stdlib.h>
#include "stack.h"


size_t capacity, cur_elem_count;
A *arr_begin;

void init_stack_array(size_t max_elem_count) {
    // Заделя масив с max_elem_count на брой елементи в динамичната памет
    capacity = max_elem_count;
    cur_elem_count = 0;
    arr_begin = calloc(max_elem_count, sizeof(A));
}

int my_push(A elem) {
    // Проверява дали има място в стека
    if(capacity == cur_elem_count) {
        return -1;
    }
    // Добавя елемент на първата свободна позиция
    arr_begin[cur_elem_count] = elem;
    cur_elem_count++;
    return 0;
}

int my_pop(A *res) {
    // Проверяваме дали стекът е празен
    if(cur_elem_count == 0) {
        return -1;
    }
    // Премахва последния елемент на стека и го предава чрез указателя res, само ако res != NULL
    if(res) {
        *res = arr_begin[cur_elem_count - 1];
    }
    cur_elem_count--;
    return 0;
}

void print_elems() {
    // Печата елементите на стека
    for(size_t i = 0; i < capacity; i++) {
        if(i < cur_elem_count) {
            printf("%3d ", arr_begin[i].data);
        } else {
            printf("___ ");
        }
    }
    printf("\n");
}

// int main() {
//     init_stack_array(10);
//     // A elem;
//     // elem.data = 1;
//     my_push((A){ .data = 1});
//     print_elems();
//     my_push((A){ .data = 2});
//     print_elems();
//     my_push((A){ .data = 3});
//     print_elems();
//     my_pop(NULL);
//     print_elems();
//     my_push((A){ .data = 4});
//     print_elems();
//     my_pop(NULL);
//     print_elems();
//     my_pop(NULL);
//     print_elems();
//     free(arr_begin);
//     init_stack_array(20);
//     return 0;
// }