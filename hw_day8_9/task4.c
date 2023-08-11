#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

/*
Направете функции, които обработват масив от 32 битови маски - maskArr. 
nitems показва броя на елементите в масива, а bit, показва номера на бита, който да се обработи. 
При успех - функциите връщат 0. Ако има проблем, функциите връщат -1.

int clearBits(uint32_t* maskArr, size_t nitems, size_t bit_index);
За всички елементи на масива maskArr се задава стойността на бита с индекс bit_index да бъде 0.

int setBits(uint32_t* maskArr, size_t nitems, size_t bit_index);
За всички елементи на масива maskArr се задава стойността на бита с индекс bit_index да бъде 1.

int checkBits(uint32_t* maskArr, size_t len, size_t bit_index);
Връща 0 ако всички елементи на maskArr имат стойност 0 на бита с индекс bit_index
Връща 1 ако всички елементи на maskArr имат стойност 1 на бита с индекс bit_index
Ако бита с индекс bit_index има стойност 1 за някои елементи на maskArr и стойност 0 за други елементи на maskArr 
    - това се счита за неуспех и функцията връща -1.
*/

int clearBits(uint32_t* maskArr, size_t nitems, size_t bit_index){
    if(bit_index >= 32){
        return -1; 
    }

    for(size_t i = 0; i < nitems; i++){
        maskArr[i] &= ~(1u << bit_index);
    }

    return 0;
}

int setBits(uint32_t* maskArr, size_t nitems, size_t bit_index){
    if(bit_index >= 32){
        return -1;
    }
    for (size_t i = 0; i < nitems; i++) {
        maskArr[i] |= (1u << bit_index);
    }

}

int checkBits(uint32_t* maskArr, size_t len, size_t bit_index){
    if (bit_index >= 32) {
        return -1;
    }

    int all_zero = 1; 
    int all_ones = 1; 

    for (size_t i = 0; i < len; i++) {
        int bit_value = (maskArr[i] >> bit_index) & 1; 

        if(bit_value == 0){
            all_ones = 0; 
        } 
        else{
            all_zero = 0; 
        }

        if(!all_zero && !all_ones){
            return -1;
        }
    }

    return all_zero ? 0 : 1;
}

int main(int argc, char* argv[]){

}