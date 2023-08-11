#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

/*Направете функция, която разменя младшия и старшия байт на променлива от тип uint16_t.
*/

void swapBytes(uint16_t* word){
    uint8_t lowByte = *word & 0xFF;
    
    uint8_t highByte = (*word >> 8) & 0xFF;
    
    *word = (*word & 0xFF00) | lowByte;
    
    *word |= (uint16_t)highByte << 8;
}

int main(void){
    uint16_t number = 0xABCD;
    
    printf("Original number: 0x%X\n", number);
    
    swapBytes(&number);
    
    printf("Number after swapping bytes: %d\n", number);
    
    return 0;
}