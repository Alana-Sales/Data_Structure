/*
Desenvolva um sistema de gerenciamento de "torres de livros" virtuais usando uma pilha dinâmica encadeada.
Implemente as seguintes funcionalidades:
- adicionar livro no topo da torre
- pegar o livro do topo da torre. Se a torre estiver vazia, deve informar que não há livros para pegar. Retorne as informações do livro pego.
- Mostra o título do livro que está atualmente no topo da torre, sem removê-lo. Se a torre estiver vazia, informe.
- Retornar o número total de livros na torre.
- Verificar se a torre de livros está vazia.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
    char titulo[100];
    struct Livro *proximo; 
} Livro;

typedef struct TorreLivros {
    Livro *topo; 
} TorreLivros;

void inicializarTorre(TorreLivros *torre) {
    torre->topo = NULL; 
}

int torreVazia(TorreLivros *torre) {
    return torre->topo == NULL; 
}

void adicionarLivro(TorreLivros *torre, const char *titulo) {
    Livro *novoLivro = (Livro *)malloc(sizeof(Livro));
    strncpy(novoLivro->titulo, titulo, sizeof(novoLivro->titulo) - 1);
    novoLivro->titulo[sizeof(novoLivro->titulo) - 1] = '\0'; 
    novoLivro->proximo = torre->topo; 
    torre->topo = novoLivro; 
    printf("Livro '%s' adicionado à torre.\n", titulo);
}

Livro* pegarLivro(TorreLivros *torre) {
    if (torreVazia(torre)) {
        printf("Não há livros para pegar.\n");
        return NULL; 
    }
    Livro *livroRemovido = torre->topo;
    torre->topo = torre->topo->proximo; 
    printf("Livro '%s' pego da torre.\n", livroRemovido->titulo);
    return livroRemovido; 
}

void mostrarLivroTopo(TorreLivros *torre) {
    if (torreVazia(torre)) {
        printf("A torre está vazia. Não há livro no topo.\n");
        return;
    }
    printf("Livro no topo: '%s'\n", torre->topo->titulo);
}

int numeroTotalLivros(TorreLivros *torre) {
    int count = 0;
    Livro *atual = torre->topo;
    while (atual != NULL) {
        count++; 
        atual = atual->proximo;
    }
    return count;
}

int main() {
    TorreLivros torre;
    inicializarTorre(&torre);

    adicionarLivro(&torre, "Espumas flutuantes");
    adicionarLivro(&torre, "Cordel de trancoso");
    adicionarLivro(&torre, "A nudez da verdade");
    adicionarLivro(&torre, "Quinta avenida, n°1");
    adicionarLivro(&torre, "A divina comédia");

    printf("Total de livros na torre: %d\n", numeroTotalLivros(&torre));
    mostrarLivroTopo(&torre);

    Livro *livro1 = pegarLivro(&torre);
    if (livro1 != NULL) {
        free(livro1); 
    }

    Livro *livro2 = pegarLivro(&torre);
    if (livro2 != NULL) {
        free(livro2); 
    }

    printf("Total de livros na torre: %d\n", numeroTotalLivros(&torre));
    mostrarLivroTopo(&torre);

    while (!torreVazia(&torre)) {
        Livro *livroRemovido = pegarLivro(&torre);
        if (livroRemovido != NULL) {
            free(livroRemovido); 
        }
    }

    return 0;
}
