#include <stdio.h>

int main() {
    int vetor[100];
    int n, i, valorRemover;

    printf("Digite quantos elementos deseja inserir (max. 100): ");
    scanf("%d", &n);

    if (n > 100 || n <= 0) {
        printf("Número de elementos inválido. Deve ser entre 1 e 100.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Digite o valor que deseja remover: ");
    scanf("%d", &valorRemover);

    int j = 0; 
    for (i = 0; i < n; i++) {
        if (vetor[i] != valorRemover) {
            vetor[j] = vetor[i];
            j++;
        }
    }

    n = j;

    printf("Vetor resultante: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
