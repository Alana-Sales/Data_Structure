#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador {
    int id; 
    char nome[31];
    int pontos;
    struct Jogador *esquerda; 
    struct Jogador *direita; 
} Jogador;

typedef struct Arvore {
    Jogador *raiz; 
} Arvore;

Jogador* criarJogador(int id, const char *nome, int pontos) {
    Jogador *novoJogador = (Jogador *)malloc(sizeof(Jogador));
    novoJogador->id = id;
    strncpy(novoJogador->nome, nome, sizeof(novoJogador->nome) - 1);
    novoJogador->nome[sizeof(novoJogador->nome) - 1] = '\0'; 
    novoJogador->pontos = pontos;
    novoJogador->esquerda = NULL;
    novoJogador->direita = NULL;
    return novoJogador;
}

void inicializarArvore(Arvore *arvore) {
    arvore->raiz = NULL;
}

void inserirJogador(Arvore *arvore, int id, const char *nome, int pontos) {
    Jogador *novoJogador = criarJogador(id, nome, pontos);

    if (arvore->raiz == NULL) {
        arvore->raiz = novoJogador; 
        return;
    }

    Jogador *atual = arvore->raiz;
    Jogador *anterior = NULL;

    while (atual != NULL) {
        anterior = atual;

        if (pontos < atual->pontos || (pontos == atual->pontos && id < atual->id)) {
            atual = atual->esquerda; 
        } else if (pontos > atual->pontos || (pontos == atual->pontos && id > atual->id)) {
            atual = atual->direita; 
        } else {
            printf("Erro: ID %d já existe.\n", id);
            free(novoJogador); 
            return;
        }
    }

    if (pontos < anterior->pontos || (pontos == anterior->pontos && id < anterior->id)) {
        anterior->esquerda = novoJogador;
    } else {
        anterior->direita = novoJogador;
    }
}

Jogador* buscarJogador(Jogador *raiz, int id) {
    if (raiz == NULL || raiz->id == id) {
        return raiz; 
    }
    if (id < raiz->id) {
        return buscarJogador(raiz->esquerda, id); 
    } else {
        return buscarJogador(raiz->direita, id);
    }
}

void atualizarPontuacao(Jogador *raiz, int id, int novaPontuacao) {
    Jogador *jogador = buscarJogador(raiz, id);
    if (jogador != NULL) {
        jogador->pontos = novaPontuacao;
    } else {
        printf("Jogador com ID %d não encontrado.\n", id);
    }
}

int contarJogadores(Jogador *raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarJogadores(raiz->esquerda) + contarJogadores(raiz->direita);
}

Jogador* encontrarMenorPontuacao(Jogador *raiz) {
    if (raiz == NULL) return NULL;
    if (raiz->esquerda == NULL) return raiz; 
    return encontrarMenorPontuacao(raiz->esquerda);
}

Jogador* removerJogador(Jogador *raiz, int id) {
    if (raiz == NULL) return NULL;

    if (id < raiz->id) {
        raiz->esquerda = removerJogador(raiz->esquerda, id); 
    } else if (id > raiz->id) {
        raiz->direita = removerJogador(raiz->direita, id); 
    } else {
        if (raiz->esquerda == NULL) {
            Jogador *temp = raiz->direita;
            free(raiz);
            return temp; 
        } else if (raiz->direita == NULL) {
            Jogador *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        Jogador *temp = encontrarMenorPontuacao(raiz->direita);
        raiz->id = temp->id;
        strncpy(raiz->nome, temp->nome, sizeof(raiz->nome) - 1);
        raiz->pontos = temp->pontos;
        raiz->direita = removerJogador(raiz->direita, temp->id); 
    }
    return raiz;
}

void removerMenorPontuacao(Arvore *arvore) {
    Jogador *menorJogador = encontrarMenorPontuacao(arvore->raiz);
    if (menorJogador != NULL) {
        printf("Removendo jogador com ID %d e pontuação %d.\n", menorJogador->id, menorJogador->pontos);
        arvore->raiz = removerJogador(arvore->raiz, menorJogador->id);
    }
}

void exibirPreOrdem(Jogador *raiz) {
    if (raiz != NULL) {
        printf("ID: %d, Nome: %s, Pontos: %d\n", raiz->id, raiz->nome, raiz->pontos);
        exibirPreOrdem(raiz->esquerda);
        exibirPreOrdem(raiz->direita);
    }
}

void exibirEmOrdem(Jogador *raiz) {
    if (raiz != NULL) {
        exibirEmOrdem(raiz->esquerda);
        printf("ID: %d, Nome: %s, Pontos: %d\n", raiz->id, raiz->nome, raiz->pontos);
        exibirEmOrdem(raiz->direita);
    }
}

void exibirPosOrdem(Jogador *raiz) {
    if (raiz != NULL) {
        exibirPosOrdem(raiz->esquerda);
        exibirPosOrdem(raiz->direita);
        printf("ID: %d, Nome: %s, Pontos: %d\n", raiz->id, raiz->nome, raiz->pontos);
    }
}

void exibirEmOrdemParaTop(Jogador *raiz, Jogador **fila, int *index);

void exibirTop3(Jogador *raiz) {
    if (raiz == NULL) return;

    Jogador *top[3] = {NULL, NULL, NULL};
    Jogador *fila[100]; 
    int index = 0;

    exibirEmOrdemParaTop(raiz, fila, &index);

    for (int i = 0; i < index; i++) {
        if (top[0] == NULL || fila[i]->pontos > top[0]->pontos) {
            top[2] = top[1];
            top[1] = top[0];
            top[0] = fila[i];
        } else if (top[1] == NULL || fila[i]->pontos > top[1]->pontos) {
            top[2] = top[1];
            top[1] = fila[i];
        } else if (top[2] == NULL || fila[i]->pontos > top[2]->pontos) {
            top[2] = fila[i];
        }
    }

    printf("Top 3 Jogadores:\n");
    for (int i = 0; i < 3; i++) {
        if (top[i] != NULL) {
            printf("ID: %d, Nome: %s, Pontos: %d\n", top[i]->id, top[i]->nome, top[i]->pontos);
        }
    }
}

void exibirEmOrdemParaTop(Jogador *raiz, Jogador **fila, int *index) {
    if (raiz != NULL) {
        exibirEmOrdemParaTop(raiz->esquerda, fila, index);
        fila[*index] = raiz;
        (*index)++;
        exibirEmOrdemParaTop(raiz->direita, fila, index);
    }
}

int main() {
    Arvore ranking;
    inicializarArvore(&ranking);

    inserirJogador(&ranking, 1, "Jogador1", 150);
    inserirJogador(&ranking, 2, "Jogador2", 200);
    inserirJogador(&ranking, 3, "Jogador3", 100);
    inserirJogador(&ranking, 4, "Jogador4", 200);
    inserirJogador(&ranking, 5, "Jogador5", 250);

    printf("Ranking em ordem:\n");
    exibirEmOrdem(ranking.raiz);
    
    printf("\nTop 3 Jogadores:\n");
    exibirTop3(ranking.raiz);

    printf("\nRemovendo jogador com ID 2:\n");
    removerJogador(ranking.raiz, 2);
    exibirEmOrdem(ranking.raiz);

    printf("\nRemovendo jogador com menor pontuação:\n");
    removerMenorPontuacao(&ranking);
    exibirEmOrdem(ranking.raiz);

    printf("\nAtualizando pontuação do jogador com ID 1:\n");
    atualizarPontuacao(ranking.raiz, 1, 300);
    exibirEmOrdem(ranking.raiz);

    return 0;
}
