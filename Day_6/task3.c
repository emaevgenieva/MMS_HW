#include <stdio.h>
#include <stdbool.h>

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t* dest_cnt){
    if (!dest) {
        return;
    }

    *dest_cnt = 0;

    for (size_t i = 0; i < n; ++i) {
        if (filter_f(arr[i])) {
            dest[*dest_cnt] = map_f(arr[i]);
            (*dest_cnt)++;
        }
    }
}

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

int is_even(int num){
    return num % 2 == 0;
}

int square(int num){
    return num * num;
}

int count_set_bits(int num) {
    int count = 0;
    
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    
    return count;
}

int main(void){
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t size = sizeof(nums) / sizeof(nums[0]);

    //=====4.1======
    int even_numbers[size];
    size_t even_numbers_size = 0;

    filter_and_map(nums, size, is_even, is_even, even_numbers, &even_numbers_size);

    printf("Even numbers: ");
    for (size_t i = 0; i < even_numbers_size; ++i) {
        printf("%d ", even_numbers[i]);
    }
    printf("\n");

    //=====4.2======
    int primes_squared[size];
    size_t primes_squared_size = 0;

    filter_and_map(nums, size, is_prime, square, primes_squared, &primes_squared_size);

    printf("Squared primes: ");
    for (size_t i = 0; i < primes_squared_size; ++i) {
        printf("%d ", primes_squared[i]);
    }
    printf("\n");

    //=====4.3========
    // int positive_bits[size];
    // size_t positive_bits_size = 0;

    // filter_and_map(nums, size, is_even, count_set_bits, positive_bits, &positive_bits_size);

    // printf("Positive set bits count: ");
    // for (size_t i = 0; i < positive_bits_size; ++i) {
    //     printf("%d ", positive_bits[i]);
    // }
    // printf("\n");

    return 0;
}
