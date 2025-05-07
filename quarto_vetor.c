#include <stdio.h>

void inverterVetor(int *vetor, int tamanho) {
    int *inicio = vetor;           
    int *fim = vetor + tamanho - 1; 
    int temp;

    while (inicio < fim) {
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}

int main() {
    int vetor[100]; 
    int n, i;

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

    inverterVetor(vetor, n);

    printf("Vetor invertido: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
