#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define COUNT 5 

typedef struct Book {
    char title[151];
    char author[101];
    int numPages;
    double price;
    struct Book* next;
}Book;

void generateRandomName(char *name){
    int nameLength = rand() % 11 + 10;

    for(int i = 0; i < nameLength; i++){
        char ch;
        do{
            ch = 'A' + rand() % 26; 
            if (rand() % 2 == 0) {
                ch = tolower(ch);
            }
        }while (ch < 'a' || ch > 'z'); 
        name[i] = ch;
    }
    name[nameLength] = '\0'; 
}

int generateRandomNumPages(){
    return rand() % 1996 + 5;
}

double generateRandomPrice(){
    return ((rand() % 100100) - 100) / 100.0; 
}

void insertBookByTitle(Book** sortedList, Book* newBook) {
    if (*sortedList == NULL || strcmp((*sortedList)->title, newBook->title) > 0) {
        newBook->next = *sortedList;
        *sortedList = newBook;
    } else {
        Book* current = *sortedList;
        while (current->next != NULL && strcmp(current->next->title, newBook->title) <= 0) {
            current = current->next;
        }
        newBook->next = current->next;
        current->next = newBook;
    }
}


void sortBooksByTitle(Book** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    Book* sortedList = NULL;
    Book* current = *head;

    while (current != NULL) {
        Book* next = current->next;
        insertBookByTitle(&sortedList, current);
        current = next;
    }

    *head = sortedList;
}


void freeBookList(Book* head) {
    while (head != NULL) {
        Book* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    srand(time(NULL)); 
    Book* head = (Book*)malloc(sizeof(Book));
    if (head == NULL) {
        perror("Error while memory alocation.");
        return 1;
    }

    generateRandomName(head->title);
    generateRandomName(head->author);
    head->numPages = generateRandomNumPages();
    head->price = generateRandomPrice();
    head->next = NULL;

    Book* current = head;
    for (int i = 1; i < COUNT; i++) {
        current->next = (Book*)malloc(sizeof(Book));
        if (current->next == NULL) {
            perror("Error while memory alocation.");
            freeBookList(head);
            return 1;
        }

        current = current->next;

        generateRandomName(current->title);
        generateRandomName(current->author);
        current->numPages = generateRandomNumPages();
        current->price = generateRandomPrice();
        current->next = NULL;
    }

    sortBooksByTitle(&head);

    current = head;
    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("Author: %s\n", current->author);
        printf("Number of Pages: %d\n", current->numPages);
        printf("Price: %.2f\n", current->price);
        printf("\n");
        current = current->next;
    }

    freeBookList(head);

    return 0;
}