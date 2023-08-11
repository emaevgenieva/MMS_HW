#include <stdio.h>

double my_abs(double x) {
    return x < 0 ? -x : x;
}

double my_cbrt(double x) {
    double eps =  0.000001; 
    double guess = x; 
    double prev_guess;

    do{
        prev_guess = guess;
        guess = (2 * prev_guess + x / (prev_guess * prev_guess)) / 3;
    }while (my_abs(guess - prev_guess) >= eps);

    return guess;
}

int main() {
    double number;

    printf("Enter a number: ");
    scanf("%lf", &number);

    double result = my_cbrt(number);
    printf("Cube root of %.2f is approximately %.6f\n", number, result);

    return 0;
}
