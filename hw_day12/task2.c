#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    printf("Please enter N: ");
    int n;
    scanf("%d", &n);

    double* array = (double*)malloc(n * sizeof(double));

    double A = 0.0, B = 1.0;

    //srand(time(NULL));
    for (int i = 0; i < n; i++) {
        double random_value = A + ((double)rand() / RAND_MAX) * (B - A);
        array[i] = random_value;
    }

    for (int i = 0; i < n; i++) {
        printf("%lf ", array[i]);
    }
    
    printf("\n");
    printf("Please enter M: ");
    int m;
    scanf("%d", &m);

    array = (double*)realloc(array, (n + m) * sizeof(double));
    double C = 1.0, D = 2.0;

    for (int i = n; i < n + m; i++) {
        double random_value = C + ((double)rand() / RAND_MAX) * (D - C);
        array[i] = random_value;
    }
    printf("\n");
    printf("Old array with new M elements:\n");
    for (int i = 0; i < n + m; i++) {
        printf("%lf ", array[i]);
    }
    printf("\n");

    printf("Please enter P: ");
    int p;
    scanf("%d", &p);

    array = (double*)realloc(array,(n+m+p)*sizeof(double));
    double E = 2.0, F = 3.0;
    for(int i=0; i<n+m+p; i++){
        double random_value = E + ((double)rand()/ RAND_MAX) * ( F - E);
        array[i] = random_value;
    }

    printf("\n");
    for(int i = 0; i < n + m + p; i++){
        printf("%lf ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}

  