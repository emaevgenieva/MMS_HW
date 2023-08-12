#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 10

typedef struct Book {
    char title[21];
    char author[21];
    int pageCount;
    double price;
}Book;

char* generateRandomString(int minLength, int maxLength) {
    int length = minLength + rand() % (maxLength - minLength + 1);
    char* result = (char*)malloc(length + 1);
    for (int i = 0; i < length; ++i) {
        result[i] = 'a' + rand() % 26;
    }
    result[length] = '\0';
    return result;
}

int compareTitles(const void* a, const void* b) {
    return strcmp(((struct Book*)a)->title, ((struct Book*)b)->title);
}

int compareAuthors(const void* a, const void* b) {
    return strcmp(((struct Book*)a)->author, ((struct Book*)b)->author);
}

int comparePageCount(const void* a, const void* b) {
    return ((struct Book*)a)->pageCount - ((struct Book*)b)->pageCount;
}

int comparePrice(const void* a, const void* b) {
    return ((struct Book*)a)->price < ((struct Book*)b)->price ? -1 : (((struct Book*)a)->price > ((struct Book*)b)->price ? 1 : 0);
}

void printBooks(struct Book* books, int count) {
    for (int i = 0; i < count; ++i) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Page Count: %d\n", books[i].pageCount);
        printf("Price: $%.2f\n\n", books[i].price);
    }
}

int main() {

    struct Book books[COUNT];

    for (int i = 0; i < COUNT; ++i) {
        strcpy(books[i].title, generateRandomString(10, 20));
        strcpy(books[i].author, generateRandomString(10, 20));
        books[i].pageCount = rand() % 1996 + 5;
        books[i].price = -1.0 + (double)(rand() % 100100) / 100.0;
    }

    printf("Original Order:\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(struct Book), compareTitles);
    printf("\nSorted by Title (Ascending):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(struct Book), compareAuthors);
    printf("\nSorted by Author (Ascending):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(struct Book), comparePageCount);
    printf("\nSorted by Page Count (Ascending):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(struct Book), comparePrice);
    printf("\nSorted by Price (Ascending):\n");
    printBooks(books, COUNT);

    return 0;
}
