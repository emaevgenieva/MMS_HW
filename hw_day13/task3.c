#include <stdio.h>

#define MAX(x, y, z) ((x) > (y) ? ((x) > (z) ? (x) : (z)) : ((y) > (z) ? (y) : (z)))
#define MIN(x, y, z) ((x) < (y) ? ((x) < (z) ? (x) : (z)) : ((y) < (z) ? (y) : (z)))
#define SETBIT(mask, bit) ((mask) |= (1 << (bit)))
#define CLEARBIT(mask, bit) ((mask) &= ~(1 << (bit)))
#define INVERSEBIT(mask, bit) ((mask) ^= (1 << (bit)))
#define CHECKBIT(mask, bit) (((mask) & (1 << (bit))) ? 1 : 0)
#define SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while (0)

int main() {
    int a = 5, b = 10, c = 3;
    int max_value = MAX(a, b, c);
    int min_value = MIN(a, b, c);

    printf("The maximum value is: %d\n", max_value);
    printf("The minimum value is: %d\n", min_value);

    printf("====\n");
    unsigned int mask = 0x00;
    int bit_to_set = 3;
    SETBIT(mask, bit_to_set);
    printf("Mask after setting bit %d: 0x%02X\n", bit_to_set, mask);

    printf("====\n");
    unsigned int mask1 = 0xFF;
    int bit_to_clear = 3;
    CLEARBIT(mask1, bit_to_clear);
    printf("Mask after clearing bit %d: 0x%02X\n", bit_to_clear, mask1);

    printf("====\n");
    unsigned int mask2 = 0x0F;
    int bit_to_inverse = 2;
    INVERSEBIT(mask2, bit_to_inverse);
    printf("Mask after inverting bit %d: 0x%02X\n", bit_to_inverse, mask2);

    printf("====\n");
    unsigned int mask3 = 0x0A;
    int bit_to_check = 3;
    int bit_state = CHECKBIT(mask3, bit_to_check);
    printf("Bit %d state in mask: %d\n", bit_to_check, bit_state);

    printf("====\n");
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    SWAP(x, y);
    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}

