/*
Simulação de Tráfego - elabore uma fila com lista encadeada
Cada carro que chega a uma ponte de pista única entra em uma fila de espera para atravessar.
- Implemente a fila com número da placa como identificador;
- Insira um carro;
- Quando o carro atravessa, ele é removido da fila;
- Mostre o próximo carro a atravessar;
- mostre se a fila de carros está vazia;
- Mostre quantos carros estão na fila
- Se um carro leva 1 min para atravessar a ponte quanto tempo levará para esvaziar a fila?
- crie função de destruição
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carro {
    char placa[8]; 
    struct Carro *proximo; 
} Carro;

typedef struct Fila {
    Carro *frente; 
    Carro *tras;  
    int tamanho;
} Fila;

void inicializarFila(Fila *fila) {
    fila->frente = NULL;
    fila->tras = NULL;
    fila->tamanho = 0; 
}

int filaVazia(Fila *fila) {
    return fila->tamanho == 0;
}

void inserirCarro(Fila *fila, const char *placa) {
    Carro *novoCarro = (Carro *)malloc(sizeof(Carro));
    strncpy(novoCarro->placa, placa, sizeof(novoCarro->placa) - 1);
    novoCarro->placa[sizeof(novoCarro->placa) - 1] = '\0'; 
    novoCarro->proximo = NULL; 

    if (filaVazia(fila)) {
        fila->frente = novoCarro; 
    } else {
        fila->tras->proximo = novoCarro;
    }
    fila->tras = novoCarro; 
    fila->tamanho++; 
    printf("Carro com placa %s adicionado à fila.\n", placa);
}

char* atenderCarro(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Não há carros na fila.\n");
        return NULL; 
    }
    Carro *carroRemovido = fila->frente; 
    fila->frente = fila->frente->proximo;
    if (fila->frente == NULL) {
        fila->tras = NULL; 
    }
    fila->tamanho--;
    printf("Carro com placa %s atravessou a ponte.\n", carroRemovido->placa);
    char *placaRemovida = strdup(carroRemovido->placa); 
    free(carroRemovido); 
    return placaRemovida; 
}

void mostrarProximoCarro(Fila *fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia. Não há carros para atravessar.\n");
        return;
    }
    printf("Próximo carro a atravessar: placa %s\n", fila->frente->placa);
}

int quantosCarrosNaFila(Fila *fila) {
    return fila->tamanho; 
}

int calcularTempoParaEsvaziar(Fila *fila) {
    return fila->tamanho; 
}

void destruirFila(Fila *fila) {
    while (!filaVazia(fila)) {
        atenderCarro(fila); 
    }
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    inserirCarro(&fila, "ABC1234");
    inserirCarro(&fila, "XYZ5678");
    inserirCarro(&fila, "LMN9101");

    mostrarProximoCarro(&fila);
    printf("Total de carros na fila: %d\n", quantosCarrosNaFila(&fila));

    atenderCarro(&fila);
    mostrarProximoCarro(&fila);
    printf("Total de carros na fila: %d\n", quantosCarrosNaFila(&fila));

    printf("Tempo para esvaziar a fila: %d minutos\n", calcularTempoParaEsvaziar(&fila));

    while (!filaVazia(&fila)) {
        atenderCarro(&fila);
    }

    destruirFila(&fila);
    return 0;
}
