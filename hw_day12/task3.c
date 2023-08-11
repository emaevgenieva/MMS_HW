#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int chars_written = 0;
    int i = 0;
    while(fmt[i] != '\0'){
        if(fmt[i] == '%'){//ne chetem "%" za specifikatora
            i++;

            switch(fmt[i]){
                case 'd':{
                    int num = va_arg(args, int);
                    chars_written += printf("%d", num);
                    break;
                }
                case 'f':{
                    double num = va_arg(args, double);
                    chars_written += printf("%f", num);
                    break;
                }
                case 'c':{
                    int c = va_arg(args, int);
                    putc(c, stdout);
                    chars_written++;
                    break;
                }
                default:
                    putc(fmt[i], stdout);
                    chars_written++;
                    break;
            }
        } 
        else{
            putc(fmt[i], stdout);
            chars_written++;
        }

        i++;
    }

    va_end(args);
    return chars_written;
}

int main(){
    int d = 13;
    double f = 8.14;
    char c = 'E';

    int result = my_printf("Integer: %d, Float: %f, Character: %c\n", d, f, c);
    printf("Total characters written: %d\n", result);
    return 0;
}