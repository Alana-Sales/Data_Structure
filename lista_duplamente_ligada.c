#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carta {
    char simbolo;
    struct Carta* ant;
    struct Carta* prox;
} Carta;

Carta* criarCarta(char simbolo) {
    Carta* nova = (Carta*)malloc(sizeof(Carta));
    nova->simbolo = simbolo;
    nova->ant = NULL;
    nova->prox = NULL;
    return nova;
}

void inserirInicio(Carta** head, char simbolo) {
    Carta* nova = criarCarta(simbolo);
    if (*head != NULL) {
        nova->prox = *head;
        (*head)->ant = nova;
    }
    *head = nova;
}

void inserirFim(Carta** head, char simbolo) {
    Carta* nova = criarCarta(simbolo);
    if (*head == NULL) {
        *head = nova;
        return;
    }
    Carta* temp = *head;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = nova;
    nova->ant = temp;
}

void inserirPosicao(Carta** head, char simbolo, int pos) {
    if (pos <= 0 || *head == NULL) {
        inserirInicio(head, simbolo);
        return;
    }
    Carta* temp = *head;
    int i = 0;
    while (temp != NULL && i < pos - 1) {
        temp = temp->prox;
        i++;
    }
    if (temp == NULL || temp->prox == NULL) {
        inserirFim(head, simbolo);
    } else {
        Carta* nova = criarCarta(simbolo);
        nova->prox = temp->prox;
        nova->ant = temp;
        temp->prox->ant = nova;
        temp->prox = nova;
    }
}

void removerParesConsecutivos(Carta** head) {
    Carta* atual = *head;
    while (atual != NULL && atual->prox != NULL) {
        if (atual->simbolo == atual->prox->simbolo) {
            Carta* primeiro = atual;
            Carta* segundo = atual->prox;

            atual = segundo->prox;
            if (primeiro->ant)
                primeiro->ant->prox = atual;
            else
                *head = atual;

            if (atual)
                atual->ant = primeiro->ant;

            free(primeiro);
            free(segundo);
        } else {
            atual = atual->prox;
        }
    }
}

void exibirFrente(Carta* head) {
    printf("Frente: ");
    while (head != NULL) {
        printf("[%c] ", head->simbolo);
        if (head->prox == NULL) break;
        head = head->prox;
    }
    printf("\n");
}

void exibirReverso(Carta* tail) {
    printf("Reverso: ");
    while (tail != NULL) {
        printf("[%c] ", tail->simbolo);
        tail = tail->ant;
    }
    printf("\n");
}

Carta* encontrarFim(Carta* head) {
    while (head && head->prox)
        head = head->prox;
    return head;
}

int main() {
    Carta* baralho = NULL;

    inserirFim(&baralho, 'A');
    inserirFim(&baralho, 'B');
    inserirFim(&baralho, 'B');
    inserirFim(&baralho, 'C');
    inserirFim(&baralho, 'D');
    inserirFim(&baralho, 'D');
    inserirFim(&baralho, 'E');

    exibirFrente(baralho);
    exibirReverso(encontrarFim(baralho));

    printf("\nRemovendo pares consecutivos...\n");
    removerParesConsecutivos(&baralho);

    exibirFrente(baralho);
    exibirReverso(encontrarFim(baralho));

    printf("\nInserindo 'Z' na posição 2...\n");
    inserirPosicao(&baralho, 'Z', 2);
    exibirFrente(baralho);
    exibirReverso(encontrarFim(baralho));

    return 0;
}
