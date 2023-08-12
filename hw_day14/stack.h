#ifndef STACK_H
#define STACK_H
#include <stdio.h>

typedef struct A{
    int data;
} A;

size_t capacity, cur_elem_count;
A *arr_begin;

// Инициализация на стека с максимален брой елементи
void init_stack_array(size_t max_elem_count);

// Поставяне на елемент в стека
int my_push(A elem);

// Изваждане на елемент от стека
int my_pop(A *res);

// Извеждане на елементите на стека
void print_elems();

#endif