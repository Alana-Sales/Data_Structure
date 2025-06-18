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

void inserir(CircularLinkedList *list, int data) {
    Node *novoNode = (Node *)malloc(sizeof(Node));
    novoNode->data = data;

    if (list->head == NULL) {
        list->head = novoNode;
        novoNode->next = novoNode;
    } else {
        Node *temp = list->head;

        while (temp->next != list->head) {
            temp = temp->next;
        }
        temp->next = novoNode; 
        novoNode->next = list->head; 
    }
}

void remover(CircularLinkedList *list, int data) {
    if (list->head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node *temp = list->head;
    Node *prev = NULL;

    if (temp->data == data) {
        if (temp->next == list->head) {
            free(temp);
            list->head = NULL;
            return;
        } else {
            while (temp->next != list->head) {
                temp = temp->next;
            }
            Node *toDelete = list->head;
            temp->next = list->head->next; 
            list->head = list->head->next; 
            free(toDelete);
            return;
        }
    }

    while (temp->next != list->head && temp->next->data != data) {
        temp = temp->next;
    }

    if (temp->next == list->head) {
        printf("Nó com valor %d não encontrado.\n", data);
        return;
    }

    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
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

void destruir(CircularLinkedList *list) {
    if (list->head == NULL) {
        return; 
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

    inserir(&lista, 1);
    inserir(&lista, 2);
    inserir(&lista, 3);
    inserir(&lista, 4);

    printf("Lista após inserção:\n");
    imprimir(&lista);

    printf("Removendo o nó com valor 2:\n");
    remover(&lista, 2);
    imprimir(&lista);

    printf("Buscando o nó com valor 3:\n");
    Node *busca = buscar(&lista, 3);
    if (busca) {
        printf("Nó encontrado: %d\n", busca->data);
    } else {
        printf("Nó não encontrado.\n");
    }

    printf("Destruindo a lista...\n");
    destruir(&lista);
    imprimir(&lista); 

    return 0;
}
