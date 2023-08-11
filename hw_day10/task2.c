#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
/*Реализирайте функция, която печата битовете на число с плаваща запетая от тип double. (прочетете за double precision floating point format)
Реализирайте функция, която печата стойностите на знаковия бит, експонентата и мантисата на число с плаваща запетая от тип double.
 Стойностите да се изпечатат в десетична бройна система все едно са интерпретирани от двоичен прав код*/

void printDoubleBits(double num) {
    uint8_t* ptr = (uint8_t*)&num; 
    size_t size = sizeof(double);

    printf("Binary representation of double: ");

    for (size_t i = 0; i < size; i++) {
        for (int j = 7; j >= 0; j--) {
            uint8_t bit = (ptr[i] >> j) & 1;
            printf("%u", bit);
        }

        printf(" ");
    }

    printf("\n");
}

void printDoubleComponents(double num) {
    uint64_t* ptr = (uint64_t*)&num; 
    uint64_t bits = *ptr;

    int sign = (bits >> 63) & 1; 
    int exponent = (bits >> 52) & 0x7FF;
    uint64_t mantissa = bits & 0xFFFFFFFFFFFFF; 

    printf("Sign: %d\n", sign);
    printf("Exponent: %d\n", exponent);
    printf("Mantissa: %llu\n", mantissa);
}

int main() {
    double number = -123.456;

    printf("Original number: %lf\n", number);
    printDoubleBits(number);
    printf("Components of the double number:\n");
    printDoubleComponents(number);

    return 0;
}