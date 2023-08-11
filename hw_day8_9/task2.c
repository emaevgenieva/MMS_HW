#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
/*Създайте функция, която намира максималния елемент в масив:
void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*));

Функцията трябва да може да намира максималния елемент в масиви от всякакъв тип:
void* arr - адресът на първия елемент в масива
size_t n - броя на елементите в масива
size_t elem_s - размерът на един елемент в байтове
int (*cmp)(const void*, const void*) - указател към функция, която приема адресите на 2 елемента от масива arr. Функцията сравнява елементите и:
връща 0 ако са еднакви
връща -1 ако първия аргумент е “по-голям”
връща 1 ако втория аргумент е “по-голям”

Като резултат функцията връща адреса на елемента, който е “най-голям”. Наредбата на елементите е определена от сравняващата функция cmp.

Функцията трябва да може да намира максималния елемент на масиви от всякакви типове. 
Примерно извикване
int cmpInt(void* a, void* b) {
	return *(int*)a > *(int*)b ? -1 : 1;
}
int main() {
	int arr[] = {1,2,-1,3,5,11,12,13,2,100,22};
	int* max = findMax(arr, sizeof(arr)/sizeof(int), sizeof(int), cmpInt);
	printf("%d", *max);	// should print 100
	return 0;
}
*/
void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*)){
    if(n == 0){
        return NULL;
    }
    void *max_elem = arr;//max elem is the first(arr[0]) elem fo the arr
    for(size_t i=1; i<n; ++i){
        void* current_elem = (char*)arr + i * elem_s;
        if (cmp(current_elem, max_elem) > 0) {
            max_elem = current_elem;
        }
    }
    return max_elem;
}

int cmp_int(const void* a, const void* b){
    const int* x = (int*)a;
    const int* y = (int*)b;
    if(*x == *y){
        return 0;
    }
    return (*x < *y) ? -1 : 1;

}


int main(int argc, char* argv[]){
    int arr[] = {7, 3, 10, 5, 2};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    int* max_elem = (int*)findMax(arr, n, sizeof(int), cmp_int);

    if(max_elem != NULL){
        printf("Max element from the array is: %d\n", *max_elem);
    } 
    else{
        printf("The array is empty.\n");
    }

    return 0;

}