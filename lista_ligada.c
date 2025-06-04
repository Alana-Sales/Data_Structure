#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pista {
    int codigo;
    char mensagem[100];
    struct Pista *proxima;
} Pista;

void adicionarPista(Pista **inicio, int codigo, const char *mensagem) {
    Pista *novaPista = (Pista *)malloc(sizeof(Pista));
    novaPista->codigo = codigo;
    strncpy(novaPista->mensagem, mensagem, sizeof(novaPista->mensagem) - 1);
    novaPista->mensagem[sizeof(novaPista->mensagem) - 1] = '\0'; 
    novaPista->proxima = NULL;

    if (*inicio == NULL) {
        *inicio = novaPista; 
    } else {
        Pista *atual = *inicio;
        while (atual->proxima != NULL) {
            atual = atual->proxima;
        }
        atual->proxima = novaPista; 
    }
}

void removerPista(Pista **inicio, int codigo) {
    Pista *atual = *inicio;
    Pista *anterior = NULL;

    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->proxima;
    }

    if (atual == NULL) {
        printf("Pista com código %d não encontrada.\n", codigo);
        return; 
    }

    if (anterior == NULL) {
        *inicio = atual->proxima;
    } else {
        anterior->proxima = atual->proxima; 
    }

    free(atual); 
    printf("Pista com código %d removida.\n", codigo);
}

void exibirTrilha(Pista *inicio) {
    Pista *atual = inicio;
    while (atual != NULL) {
        printf("Código: %d, Mensagem: %s\n", atual->codigo, atual->mensagem);
        atual = atual->proxima;
    }
    printf("Tesouro encontrado!\n");
}

void buscarPista(Pista *inicio, int codigo) {
    Pista *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            printf("Pista encontrada: %s\n", atual->mensagem);
            return;
        }
        atual = atual->proxima;
    }
    printf("Pista com código %d não encontrada.\n", codigo);
}

int main() {
    Pista *trilha = NULL;
    int opcao, codigo;
    char mensagem[100];

    do {
        printf("\n1. Adicionar Pista\n");
        printf("2. Remover Pista\n");
        printf("3. Exibir Trilha\n");
        printf("4. Buscar Pista\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o código da pista: ");
                scanf("%d", &codigo);
                printf("Digite a mensagem da pista: ");
                getchar(); 
                fgets(mensagem, sizeof(mensagem), stdin);
                mensagem[strcspn(mensagem, "\n")] = 0;
                adicionarPista(&trilha, codigo, mensagem);
                break;
            case 2:
                printf("Digite o código da pista a remover: ");
                scanf("%d", &codigo);
                removerPista(&trilha, codigo);
                break;
            case 3:
                exibirTrilha(trilha);
                break;
            case 4:
                printf("Digite o código da pista a buscar: ");
                scanf("%d", &codigo);
                buscarPista(trilha, codigo);
                break;
            case 5:
                printf("Saindo do jogo.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    while (trilha != NULL) {
        Pista *temp = trilha;
        trilha = trilha->proxima;
        free(temp);
    }

    return 0;
}
