#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define ID_LEN 10

typedef struct Person {
    char name[100];
    char id[ID_LEN];
    uint16_t birthYear;
    uint8_t birthMonth;
    uint8_t birthDay;
    char gender;
};

void* initArray(size_t capacity) {
    size_t personSize = sizeof(struct Person);
    void* array = malloc(capacity * personSize);

    if(array == NULL){
        printf("Memory allocation failed!\n");
        return NULL;
    }
    return array;
}

int addPerson(void* array, size_t capacity, const char* name, uint16_t birthYear, uint8_t birthMonth, uint8_t birthDay, char gender){
    //cast-ваме от void* към struct PErson*
    struct Person* persons = (struct Person*)array;

    if(array == NULL){
        printf("Invalid array!\n");
        return -1;
    }

    if(capacity == 0){
        printf("Array capacity is zero!\n");
        return -1;
    }

    size_t index = 0;
    for(index = 0; index < capacity; index++){
        if(persons[index].id[0] == '\0'){
            break;
        }
    }

    if(index == capacity){
        printf("Array is full!\n");
        return -1;
    }

    strncpy(persons[index].name, name, 100);
    snprintf(persons[index].id, ID_LEN, "ID %lu", index);
    persons[index].birthYear = birthYear;
    persons[index].birthMonth = birthMonth;
    persons[index].birthDay = birthDay;
    persons[index].gender = gender;

    return 0;
}
int removePerson(char* id, void* array, size_t capacity) {
    if (array == NULL) {
        printf("Invalid array!\n");
        return -1;
    }

    for (size_t index = 0; index < capacity; index++) {
        struct Person* person = ((struct Person*)array) + index;

        if (strncmp(person->id, id, ID_LEN) == 0) {
            person->id[0] = '\0';
            return 0;
        }
    }

    printf("Person with ID %s not found!\n", id);
    return -1; 
}

void readPerson(struct Person* array, size_t capacity) {
    if (array == NULL) {
        printf("Invalid array!\n");
        return;
    }

    for (size_t index = 0; index < capacity; index++) {
        if (array[index].id[0] == '\0') {
            printf("Enter person's name: ");
            scanf("%99s", array[index].name);

            printf("Enter person's birth year: ");
            scanf("%lu", &array[index].birthYear);

            printf("Enter person's birth month: ");
            scanf("%lu", &array[index].birthMonth);

            printf("Enter person's birth day: ");
            scanf("%lu" , &array[index].birthDay);

            printf("Enter person's gender (M/F): ");
            scanf(" %c", &array[index].gender);

            snprintf(array[index].id, ID_LEN, "ID %lu", index);

            printf("Person successfully added!\n");
            return;
        }
    }

    printf("Array is full, cannot add person!\n");
}

int printPerson(char* id, void* array, size_t capacity) {
    if (array == NULL) {
        printf("Invalid array!\n");
        return -1;
    }

    for (size_t index = 0; index < capacity; index++) {
        struct Person* person = ((struct Person*)array) + index;

        if (strncmp(person->id, id, ID_LEN) == 0) {
            printf("Name: %s\n", person->name);
            printf("ID: %s\n", person->id);
            printf("Birth Year: %lu\n", person->birthYear);
            printf("Birth Month: %lu\n", person->birthMonth);
            printf("Birth Day: %lu\n", person->birthDay);
            printf("Gender: %c\n", person->gender);
            return 0;
        }
    }

    printf("Person with ID %s not found!\n", id);
    return -1;
}
