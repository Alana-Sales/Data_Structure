#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

typedef struct {
    Produto produtos[MAX_PRODUTOS];
    int tamanho;
} Estoque;

void inserirProduto(Estoque *estoque, int id, const char *nome, float preco) {
    if (estoque->tamanho < MAX_PRODUTOS) {
        estoque->produtos[estoque->tamanho].id = id;
        strncpy(estoque->produtos[estoque->tamanho].nome, nome, sizeof(estoque->produtos[estoque->tamanho].nome) - 1);
        estoque->produtos[estoque->tamanho].preco = preco;
        estoque->tamanho++;
    } else {
        printf("Estoque cheio! Não é possível inserir mais produtos.\n");
    }
}

Produto* buscarProduto(Estoque *estoque, int id) {
    for (int i = 0; i < estoque->tamanho; i++) {
        if (estoque->produtos[i].id == id) {
            return &estoque->produtos[i];
        }
    }
    return NULL; 
}

void removerProduto(Estoque *estoque, int id) {
    for (int i = 0; i < estoque->tamanho; i++) {
        if (estoque->produtos[i].id == id) {
            for (int j = i; j < estoque->tamanho - 1; j++) {
                estoque->produtos[j] = estoque->produtos[j + 1];
            }
            estoque->tamanho--; 
            printf("Produto com ID %d removido.\n", id);
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

void exibirProdutos(Estoque *estoque) {
    printf("Produtos em estoque:\n");
    for (int i = 0; i < estoque->tamanho; i++) {
        printf("ID: %d, Nome: %s, Preço: %.2f\n", estoque->produtos[i].id, estoque->produtos[i].nome, estoque->produtos[i].preco);
    }
}

int retornarTamanho(Estoque *estoque) {
    return estoque->tamanho;
}

int main() {
    Estoque estoque = { .tamanho = 0 };

    inserirProduto(&estoque, 1, "Produto A", 10.50);
    inserirProduto(&estoque, 2, "Produto B", 20.75);
    inserirProduto(&estoque, 3, "Produto C", 15.30);

    exibirProdutos(&estoque);

    Produto *produto = buscarProduto(&estoque, 2);
    if (produto) {
        printf("Produto encontrado: ID: %d, Nome: %s, Preço: %.2f\n", produto->id, produto->nome, produto->preco);
    } else {
        printf("Produto não encontrado.\n");
    }

    removerProduto(&estoque, 1);
    exibirProdutos(&estoque);

    printf("Tamanho do estoque: %d\n", retornarTamanho(&estoque));

    return 0;
}
