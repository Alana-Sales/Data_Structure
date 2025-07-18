/*Implementar um gerenciador de tarefas que simule a adição e execução de tarefas usando uma pilha (implementação com vetor estático). Cada "tarefa" será representada por um número inteiro (ID).

Defina a estrutura da pilha;

Crie funções para inicializar a pilha, checar se está vazia, checar se está cheia, inserir uma tarefa, remover uma tarefa, visualizar a tarefa do topo, obter o tamanho da pilha

Na main():

Crie uma pilha;
Adicione 5 tarefas à pilha.
Exiba o número de tarefas e a tarefa do topo.
Simule a execução de 2 tarefas (remova-as da pilha).
Exiba o número de tarefas e a tarefa do topo.
Adicione mais 3 tarefas.
Exiba o número de tarefas e a tarefa do topo.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 

typedef struct Stack {
    int tarefas[MAX]; 
    int topo; 
} Stack;

void inicializarPilha(Stack *s) {
    s->topo = -1; 
}

int pilhaVazia(Stack *s) {
    return s->topo == -1; 
}

int pilhaCheia(Stack *s) {
    return s->topo == MAX - 1; 
}

void inserirTarefa(Stack *s, int tarefa) {
    if (pilhaCheia(s)) {
        printf("A pilha está cheia. Não é possível adicionar a tarefa %d.\n", tarefa);
        return;
    }
    s->tarefas[++(s->topo)] = tarefa; 
    printf("Tarefa %d adicionada à pilha.\n", tarefa);
}

int removerTarefa(Stack *s) {
    if (pilhaVazia(s)) {
        printf("A pilha está vazia. Não é possível remover uma tarefa.\n");
        return -1; 
    }
    return s->tarefas[(s->topo)--]; 
}

int tarefaTopo(Stack *s) {
    if (pilhaVazia(s)) {
        printf("A pilha está vazia. Não há tarefa no topo.\n");
        return -1; 
    }
    return s->tarefas[s->topo];
}

int tamanhoPilha(Stack *s) {
    return s->topo + 1; 
}

int main() {
    Stack pilha;
    inicializarPilha(&pilha);

    for (int i = 1; i <= 5; i++) {
        inserirTarefa(&pilha, i);
    }

    printf("Número de tarefas: %d\n", tamanhoPilha(&pilha));
    printf("Tarefa do topo: %d\n", tarefaTopo(&pilha));

    for (int i = 0; i < 2; i++) {
        int tarefaRemovida = removerTarefa(&pilha);
        if (tarefaRemovida != -1) {
            printf("Tarefa %d executada e removida da pilha.\n", tarefaRemovida);
        }
    }

    printf("Número de tarefas: %d\n", tamanhoPilha(&pilha));
    printf("Tarefa do topo: %d\n", tarefaTopo(&pilha));

    for (int i = 6; i <= 8; i++) {
        inserirTarefa(&pilha, i);
    }

    printf("Número de tarefas: %d\n", tamanhoPilha(&pilha));
    printf("Tarefa do topo: %d\n", tarefaTopo(&pilha));

    return 0;
}
