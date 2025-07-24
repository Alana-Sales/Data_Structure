/*
Fila Prioritária para Vacinação
implementar uma fila de prioridade em C que simule o gerenciamento de atendimento por prioridade em um hospital:

A fila de prioridade deve ser implementada utilizando uma lista encadeada simples.

Cada nó da lista (representando um paciente) deve armazenar:
- informações do paciente
- int prioridade: Nível de prioridade do atendimento (um número inteiro, onde quanto menor o número, maior a prioridade). Ex: 1 (Emergência), 2 (Muito Urgente), 3 (Urgente), 4 (Pouco Urgente), 5 (Não Urgente)

Deve conter as seguintes funções:
- Adicionar paciente conforme a prioridade
- remover paciente por ordem de prioridade
- verificar o proximo a ser atendido
- verificar se a fila está vazia
- liberar a fila
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    char nome[100];
    int prioridade;
    struct Paciente *proximo; 
} Paciente;

typedef struct FilaPrioritaria {
    Paciente *frente; 
} FilaPrioritaria;

void inicializarFila(FilaPrioritaria *fila) {
    fila->frente = NULL; 
}

int filaVazia(FilaPrioritaria *fila) {
    return fila->frente == NULL;
}

void adicionarPaciente(FilaPrioritaria *fila, const char *nome, int prioridade) {
    Paciente *novoPaciente = (Paciente *)malloc(sizeof(Paciente));
    strncpy(novoPaciente->nome, nome, sizeof(novoPaciente->nome) - 1);
    novoPaciente->nome[sizeof(novoPaciente->nome) - 1] = '\0'; 
    novoPaciente->prioridade = prioridade;
    novoPaciente->proximo = NULL;

    if (filaVazia(fila)) {
        fila->frente = novoPaciente;
    } else {
        Paciente *atual = fila->frente;
        Paciente *anterior = NULL;

        while (atual != NULL && atual->prioridade <= prioridade) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == NULL) {
            novoPaciente->proximo = fila->frente;
            fila->frente = novoPaciente;
        } else {

            anterior->proximo = novoPaciente;
            novoPaciente->proximo = atual;
        }
    }
    printf("Paciente '%s' com prioridade %d adicionado à fila.\n", nome, prioridade);
}

char* removerPaciente(FilaPrioritaria *fila) {
    if (filaVazia(fila)) {
        printf("Não há pacientes na fila.\n");
        return NULL; 
    }

    Paciente *pacienteRemovido = fila->frente; 
    fila->frente = fila->frente->proximo;
    char *nomeRemovido = strdup(pacienteRemovido->nome);
    free(pacienteRemovido); 
    printf("Paciente '%s' atendido(a) e removido(a) da fila.\n", nomeRemovido);
    return nomeRemovido; 
}

void verificarProximoPaciente(FilaPrioritaria *fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia. Não há pacientes para atender.\n");
        return;
    }
    printf("Próximo paciente a ser atendido(a): '%s' com prioridade %d.\n",
           fila->frente->nome, fila->frente->prioridade);
}

void liberarFila(FilaPrioritaria *fila) {
    while (!filaVazia(fila)) {
        removerPaciente(fila);
    }
}

int main() {
    FilaPrioritaria fila;
    inicializarFila(&fila);

    adicionarPaciente(&fila, "Martenier", 3);
    adicionarPaciente(&fila, "Alana", 1);
    adicionarPaciente(&fila, "Kelly", 2);
    adicionarPaciente(&fila, "Soraia", 4);

    verificarProximoPaciente(&fila);

    removerPaciente(&fila);
    verificarProximoPaciente(&fila);

    liberarFila(&fila);
    return 0;
}
