/*
Elabore a implementação de uma lista encadeada circular (exemplo que você desejar)
- criar as funções de inserção (início e fim), remoção (início e fim), Busca, Imprimir e liberar a lista
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct CircularLinkedList {
    Node *head; 
} CircularLinkedList;

void inicializarLista(CircularLinkedList *list) {
    list->head = NULL;
}

void inserirInicio(CircularLinkedList *list, int data) {
    Node *novoNode = (Node *)malloc(sizeof(Node));
    novoNode->data = data;

    if (list->head == NULL) {
        list->head = novoNode;
        novoNode->next = novoNode;
    } else {
        Node *tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next;
        }
        novoNode->next = list->head;
        tail->next = novoNode; 
        list->head = novoNode; 
    }
}

void inserirFim(CircularLinkedList *list, int data) {
    Node *novoNode = (Node *)malloc(sizeof(Node));
    novoNode->data = data;

    if (list->head == NULL) {
        list->head = novoNode;
        novoNode->next = novoNode;
    } else {
        Node *tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next;
        }
        tail->next = novoNode; 
        novoNode->next = list->head;
    }
}

void removerInicio(CircularLinkedList *list) {
    if (list->head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node *temp = list->head;

    if (temp->next == list->head) {
        free(temp);
        list->head = NULL;
    } else {
        Node *tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next; 
        }
        list->head = temp->next;
        tail->next = list->head;
        free(temp);
    }
}

void removerFim(CircularLinkedList *list) {
    if (list->head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node *tail = list->head;
    Node *prev = NULL;

    if (tail->next == list->head) {
        free(tail);
        list->head = NULL;
        return;
    }

    while (tail->next != list->head) {
        prev = tail;
        tail = tail->next;
    }

    prev->next = list->head;
    free(tail);
}

Node* buscar(CircularLinkedList *list, int data) {
    if (list->head == NULL) {
        return NULL; 
    }

    Node *temp = list->head;

    do {
        if (temp->data == data) {
            return temp; 
        }
        temp = temp->next;
    } while (temp != list->head);

    return NULL; 
}

void imprimir(CircularLinkedList *list) {
    if (list->head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node *temp = list->head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);

    printf("(Volta ao início)\n");
}

void liberar(CircularLinkedList *list) {
    if (list->head == NULL) {
        return; // Lista vazia
    }

    Node *temp = list->head;
    Node *toDelete;

    do {
        toDelete = temp;
        temp = temp->next;
        free(toDelete);
    } while (temp != list->head);

    list->head = NULL;
}

int main() {
    CircularLinkedList lista;
    inicializarLista(&lista);

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirFim(&lista, 30);
    inserirFim(&lista, 40);

    printf("Lista após inserção:\n");
    imprimir(&lista);

    printf("Removendo o início:\n");
    removerInicio(&lista);
    imprimir(&lista);

    printf("Removendo o fim:\n");
    removerFim(&lista);
    imprimir(&lista);

    printf("Buscando o nó com valor 30:\n");
    Node *busca = buscar(&lista, 30);
    if (busca) {
        printf("Nó encontrado: %d\n", busca->data);
    } else {
        printf("Nó não encontrado.\n");
    }

    printf("Destruindo a lista...\n");
    liberar(&lista);
    imprimir(&lista); 

    return 0;
}
