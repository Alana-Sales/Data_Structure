/*
Fila de Atendimento Bancário
Implemente uma fila circular estática para simular o atendimento em um banco. Cada pessoa é identificada por um número de senha.

Crie funções para:

Inserir uma nova pessoa na fila;
Atender (remover) a próxima pessoa
Mostrar a próxima pessoa a ser atendida.
Verificar se a fila está vazia
Verificar se a fila está cheia
Indicar quantas pessoas ainda faltam ser atendidas
A fila deve ter no máximo 10 pessoas.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 

typedef struct Fila {
    int senhas[MAX]; 
    int frente; 
    int tras;   
    int tamanho;
} Fila;

void inicializarFila(Fila *fila) {
    fila->frente = 0;
    fila->tras = -1;
    fila->tamanho = 0;
}

int filaVazia(Fila *fila) {
    return fila->tamanho == 0;
}

int filaCheia(Fila *fila) {
    return fila->tamanho == MAX;
}

void inserirPessoa(Fila *fila, int senha) {
    if (filaCheia(fila)) {
        printf("A fila está cheia. Não é possível adicionar mais pessoas.\n");
        return;
    }
    fila->tras = (fila->tras + 1) % MAX; 
    fila->senhas[fila->tras] = senha;
    fila->tamanho++;
    printf("Pessoa com senha %d adicionada à fila.\n", senha);
}

int atenderPessoa(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Não há pessoas para atender.\n");
        return -1; 
    }
    int senhaAtendida = fila->senhas[fila->frente];
    fila->frente = (fila->frente + 1) % MAX; 
    fila->tamanho--; 
    printf("Pessoa com senha %d atendida.\n", senhaAtendida);
    return senhaAtendida; 
}

void mostrarProximaPessoa(Fila *fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia. Não há pessoas para atender.\n");
        return;
    }
    printf("Próxima pessoa a ser atendida: senha %d\n", fila->senhas[fila->frente]);
}

int pessoasFaltando(Fila *fila) {
    return fila->tamanho; 
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    for (int i = 1; i <= 5; i++) {
        inserirPessoa(&fila, i);
    }

    mostrarProximaPessoa(&fila);
    printf("Total de pessoas na fila: %d\n", pessoasFaltando(&fila));

    atenderPessoa(&fila);
    atenderPessoa(&fila);

    mostrarProximaPessoa(&fila);
    printf("Total de pessoas na fila: %d\n", pessoasFaltando(&fila));

    for (int i = 6; i <= 10; i++) {
        inserirPessoa(&fila, i);
    }

    inserirPessoa(&fila, 11);

    printf("Total de pessoas na fila: %d\n", pessoasFaltando(&fila));

    return 0;
}
