#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

/*
    Използвайте функцията findMax с подходящи comparator функции:
    
    1) За да намерите най-големия елемент в масив от тип uint64_t.

    2) За да намерите точката, която е на най-голямо (евклидово) разстояние от (0, 0, 0) в масив от тип Point. 

    3) За да намерите човека с най-нисък Body Mass Index в масив от тип Human.
        Body Mass Index = weight_kg / (height_meter*height_meters)

    4) За да намерите числото с най-много битове в двоичното представяне, които са 1, в масив от тип float.
*/
// ---------part 1 -----------
void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*)){
    if(n == 0){
        return NULL;
    }
    void *max_elem = arr;//max elem is the first(arr[0]) elem fo the arr
    for(size_t i=1; i<n; ++i){
        void* current_elem = (char*)arr + i * elem_s;
        if (cmp(current_elem, max_elem) > 0) {
            max_elem = current_elem;
        }
    }
    return max_elem;
}

int cmp_uint_64(const void* a, const void* b){
    const uint64_t* x = (const uint64_t*)a;
    const uint64_t* y = (const uint64_t*)b;
    if(*x == *y){
        return 0;
    }

    return (*x < *y) ? -1 : 1;
}

typedef struct Point {
    double x;
    double y;
    double z;
} Point;

double distance_from_center(const Point* p){
    return sqrt((p->x*p->x) + (p->y * p->y)+(p->z * p->z));
}

int cmp_points(const void* a, const void* b){
    const Point* point_a = (const Point*)a;
    const Point* point_b = (const Point*)b;

    double distance_a = distance_from_center(point_a);
    double distance_b = distance_from_center(point_b);

    if(distance_a == distance_b){
        return 0;
    }

    return (distance_a < distance_b) ? -1 : 1;
}

// ---------part 2 -----------
typedef struct Human {
    double weight_kg;
    uint16_t height_cm;
} Human;

// ---------part 3 -----------

double calculate_bmi(const Human* human){
    double height_m = (double)human->height_cm / 100.0;
    return human->weight_kg / (height_m * height_m);
}

int cmp_people(const void* a, const void* b){
    const Human* human_1 = (const Human*)a;
    const Human* human_2 = (const Human*)b;

    double idx_a = calculate_bmi(human_1);
    double idx_b = calculate_bmi(human_2);

    if(idx_a == idx_b){
        return 0;
    }

    return (idx_a < idx_b) ? -1 : 1;
}

// ---------part 4 -----------

int count_ones_in_float_binary(float f) {
    uint32_t binary_representation;
    memcpy(&binary_representation, &f, sizeof(float));

    int count = 0;
    while (binary_representation != 0) {
        count += binary_representation & 1;
        binary_representation >>= 1;
    }

    return count;
}

int cmp_float(const void* a, const void* b) {
    float float_a = *(const float*)a;
    float float_b = *(const float*)b;

    int ones_a = count_ones_in_float_binary(float_a);
    int ones_b = count_ones_in_float_binary(float_b);

    if (ones_a == ones_b) return 0;
    return (ones_a > ones_b) ? -1 : 1;
}

int main(int argc, char* argv[]){
    uint64_t arr_uint64[] = {100, 20, 300, 50, 40};
    size_t n = sizeof(arr_uint64) / sizeof(arr_uint64[0]);

    uint64_t* max_elem = (uint64_t*)findMax(arr_uint64, n, sizeof(uint64_t), cmp_uint_64);

    if(max_elem != NULL){
        printf("Max elem is: %lu""\n", *max_elem);
    } 
    else{
        printf("Empty array (uint_64).\n");
    }

    Point points[] = {{1.0, 2.0, 3.0},
                   {4.0, 5.0, 6.0},
                   {-2.0, -1.0, 2.0}};
    size_t n = sizeof(points) / sizeof(points[0]);

    Point* max_point = (Point*)findMax(points, n, sizeof(Point), cmp_points);

    if (max_point != NULL) {
        printf("Distance from the beginning is: (%lf, %lf, %lf)\n", max_point->x, max_point->y, max_point->z);
    } 
    else {
        printf("Empty array!!!!.\n");
    }

    Human people[] = {{70.0, 170},    
                    {62.5, 165},   
                    {80.0, 180},   
                    {55.0, 160}};  
    size_t n = sizeof(people) / sizeof(people[0]);

    Human* min_bmi_human = (Human*)findMax(people, n, sizeof(Human), cmp_people);

    if (min_bmi_human != NULL) {
        printf("The person with the ""smallest"" BMI is with weight  %.1lf kg and height %d cm.\n",
               min_bmi_human->weight_kg, min_bmi_human->height_cm);
    } else {
        printf("Empty array\n");
    }

    float arr[] = {3.5f, 2.25f, 6.75f, 1.0f, 10.125f};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    
    float* max_ones_float = (float*)findMax(arr, n, sizeof(float), cmp_float);

    if (max_ones_float != NULL) {
        printf("The number with the most bits, ""1"", in binary is: %.2f\n", *max_ones_float);
    } else {
        printf("Empty array.\n");
    }

    return 0;
}