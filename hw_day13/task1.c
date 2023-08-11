#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Deque{
    Node* front;
    Node* back;  
} Deque;

// Инициализация на празна опашка
Deque* createDeque(){
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (deque == NULL) {
        perror("Error while alloc memory");
        return NULL;
    }
    deque->front = NULL;
    deque->back = NULL;
    return deque;
}

// Добавяне на елемент в началото на опашката
void pushFront(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Error while alloc memory");
        return;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deque->front;

    if (deque->front == NULL) {
        deque->back = newNode;
    } else {
        deque->front->prev = newNode;
    }

    deque->front = newNode;
}

// Добавяне на елемент в края на опашката
void pushBack(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Error while alloc memory");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->back;

    if (deque->back == NULL) {
        deque->front = newNode;
    } else {
        deque->back->next = newNode;
    }

    deque->back = newNode;
}

// Премахване на елемент от началото на опашката
int popFront(Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty.\n");
        return -1; // Няма стандартен начин за показване на грешка
    }

    Node* frontNode = deque->front;
    int data = frontNode->data;
    
    deque->front = frontNode->next;
    if (deque->front == NULL) {
        deque->back = NULL;
    } else {
        deque->front->prev = NULL;
    }

    free(frontNode);
    return data;
}

// Премахване на елемент от края на опашката
int popBack(Deque* deque) {
    if (deque->back == NULL) {
        printf("Deque is empty.\n");
        return -1; // Няма стандартен начин за показване на грешка
    }

    Node* rearNode = deque->back;
    int data = rearNode->data;
    
    deque->back = rearNode->prev;
    if (deque->back == NULL) {
        deque->front = NULL;
    } else {
        deque->back->next = NULL;
    }

    free(rearNode);
    return data;
}

// Освобождаване на паметта, заета от опашката
void destroyDeque(Deque* deque) {
    while (deque->front != NULL) {
        Node* temp = deque->front;
        deque->front = deque->front->next;
        free(temp);
    }
    free(deque);
}

int main() {
    Deque* deque = createDeque();
    
    pushFront(deque, 10);
    pushBack(deque, 20);
    pushFront(deque, 5);
    pushBack(deque, 30);

    printf("Deque after pushes: ");
    Node* current = deque->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    int poppedFront = popFront(deque);
    printf("Popped from front: %d\n", poppedFront);

    int poppedBack = popBack(deque);
    printf("Popped from back: %d\n", poppedBack);

    printf("Deque after pops: ");
    current = deque->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    destroyDeque(deque);

    return 0;
}