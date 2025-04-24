/*Declare um vetor de inteiro com no máximo 100 elementos;
   • Pergunte ao usuários quantos elementos deseja digitar;
   • Solicite ao usuário inserir os números;
   • Pergunte qual posição do elemento que deseja remover;
   • Remova o elemento;
   • Imprima na tela o vetor resultante.*/

#include <stdio.h>

int main() {
    int vetor[100]; 
    int n, i, posicao;
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

    printf("Digite a posição do elemento que deseja remover (1 a %d): ", n);
    scanf("%d", &posicao);

    if (posicao < 1 || posicao > n) {
        printf("Posição inválida.\n");
        return 1; 
    }

    for (i = posicao - 1; i < n - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    n--;

    printf("Vetor resultante: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
