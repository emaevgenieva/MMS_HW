#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int printf_time(const char *format, ...) {
    time_t raw_time;
    struct tm *time_info;
    char time_str[30];

    time(&raw_time);
    time_info = localtime(&raw_time);
    strftime(time_str, sizeof(time_str), "[%d.%m.%Y – %H:%M:%S]", time_info);

    printf("%s ", time_str);

    va_list args;
    va_start(args, format);
    int result = vprintf(format, args);
    va_end(args);

    return result;
}

int main() {
    printf_time("%d %d", 10, 20);

    return 0;
}