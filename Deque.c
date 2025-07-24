/*
Desenvolva um programa usando a estrutura de dado deque que receba uma string como entrada e determine se ela é um palíndromo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque {
    Node *front;
    Node *rear;
} Deque;

void initDeque(Deque *deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

void addFront(Deque *deque, char value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = deque->front;
    newNode->prev = NULL;

    if (deque->front != NULL) {
        deque->front->prev = newNode;
    }
    if (deque->rear == NULL) {
        deque->rear = newNode;
    }
    deque->front = newNode;
}

void addRear(Deque *deque, char value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (deque->rear != NULL) {
        deque->rear->next = newNode;
    }
    if (deque->front == NULL) { 
        deque->front = newNode;
    }
    deque->rear = newNode;
}

char removeFront(Deque *deque) {
    if (deque->front == NULL) {
        return '\0'; 
    }
    Node *temp = deque->front;
    char value = temp->data;
    deque->front = deque->front->next;

    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL; 
    }
    free(temp);
    return value;
}

char removeRear(Deque *deque) {
    if (deque->rear == NULL) {
        return '\0'; 
    }
    Node *temp = deque->rear;
    char value = temp->data;
    deque->rear = deque->rear->prev;

    if (deque->rear != NULL) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL;
    }
    free(temp);
    return value;
}

int isPalindrome(const char *str) {
    Deque deque;
    initDeque(&deque);

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]); 
        if (isalnum(c)) { 
            addRear(&deque, c);
        }
    }

    while (deque.front != NULL) {
        char frontChar = removeFront(&deque);
        char rearChar = removeRear(&deque);
        
        if (frontChar != rearChar && rearChar != '\0') {
            return 0; 
        }
    }
    return 1;
}

int main() {
    char str[256];

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 

    if (isPalindrome(str)) {
        printf("A string é um palíndromo.\n");
    } else {
        printf("A string não é um palíndromo.\n");
    }

    return 0;
}
