#include <stdio.h>
#include <inttypes.h>

#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8 5
#define TUINT16 6
#define TUINT32 7
#define TUINT64 8

void printValue(const void* valuePtr, uint8_t flag) {
    switch (flag) {
        case TINT:
            printf("%d\n", *((int*)valuePtr));
            break;
        case TCHAR:
            printf("%c\n", *((char*)valuePtr));
            break;
        case TDOUBLE:
            printf("%lf\n", *((double*)valuePtr));
            break;
        case TFLOAT:
            printf("%f\n", *((float*)valuePtr));
            break;
        case TUINT8:
            printf("%lu\n", *((uint8_t*)valuePtr));
            break;
        case TUINT16:
            printf("%lu\n", *((uint16_t*)valuePtr));
            break;
        case TUINT32:
            printf("%lu\n", *((uint32_t*)valuePtr));
            break;
        case TUINT64:
            printf("%lu\n", *((uint64_t*)valuePtr));
            break;
        default:
            printf("Unknown type flag.\n");
            break;
    }
}

int main() {
    int intValue = 42;
    printValue(&intValue, TINT);

    char charValue = 'A';
    printValue(&charValue, TCHAR);

    double doubleValue = 3.14159;
    printValue(&doubleValue, TDOUBLE);

    float floatValue = 2.71828;
    printValue(&floatValue, TFLOAT);

    uint8_t uint8Value = 255;
    printValue(&uint8Value, TUINT8);

    uint16_t uint16Value = 65535;
    printValue(&uint16Value, TUINT16);

    uint32_t uint32Value = 4294967295;
    printValue(&uint32Value, TUINT32);

    uint64_t uint64Value = 18446744073709551615ULL;
    printValue(&uint64Value, TUINT64);

    return 0;
}