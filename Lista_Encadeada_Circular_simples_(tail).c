#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct CircularLinkedList {
    Node *tail; 
} CircularLinkedList;

void inicializarLista(CircularLinkedList *list) {
    list->tail = NULL;
}

void inserir(CircularLinkedList *list, int data) {
    Node *novoNode = (Node *)malloc(sizeof(Node));
    novoNode->data = data;

    if (list->tail == NULL) {
        list->tail = novoNode;
        novoNode->next = novoNode;
    } else {
        novoNode->next = list->tail->next;
        list->tail->next = novoNode; 
        list->tail = novoNode; 
    }
}

void remover(CircularLinkedList *list, int data) {
    if (list->tail == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node *temp = list->tail->next; 
    Node *prev = list->tail;

    if (temp->data == data) {
        if (temp == list->tail) {
            free(temp);
            list->tail = NULL;
            return;
        } else {
            prev->next = temp->next;
            free(temp);
            return;
        }
    }

    while (temp != list->tail && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == list->tail) {
        printf("Nó com valor %d não encontrado.\n", data);
        return;
    }

    prev->next = temp->next; 
    free(temp);

    if (prev == list->tail) {
        list->tail = prev; 
    }
}

Node* buscar(CircularLinkedList *list, int data) {
    if (list->tail == NULL) {
        return NULL; 
    }

    Node *temp = list->tail->next; 

    do {
        if (temp->data == data) {
            return temp; 
        }
        temp = temp->next;
    } while (temp != list->tail->next); 

    return NULL; 
}

void imprimir(CircularLinkedList *list) {
    if (list->tail == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node *temp = list->tail->next; 

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->tail->next);

    printf("(Volta ao início)\n");
}

void liberar(CircularLinkedList *list) {
    if (list->tail == NULL) {
        return; 
    }

    Node *temp = list->tail->next; 
    Node *toDelete;

    do {
        toDelete = temp;
        temp = temp->next;
        free(toDelete);
    } while (temp != list->tail->next);

    list->tail = NULL;
}

int main() {
    CircularLinkedList lista;
    inicializarLista(&lista);

    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);
    inserir(&lista, 40);

    printf("Lista após inserção:\n");
    imprimir(&lista);

    printf("Removendo o nó com valor 20:\n");
    remover(&lista, 20);
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
