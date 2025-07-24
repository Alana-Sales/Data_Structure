/*
Declare um vetor de inteiro com no máximo 100 elementos;
    • pergunte ao usuário quantos elementos deseja inserir;
    • solicite ao usuário os elementos para compor o vetor;
    • pergunte ao usuário qual elemento deseja inserir e em qual posição?
    • imprima na tela o vetor resultante.
*/

#include <stdio.h>

int main() {
    int vetor[100]; 
    int n, i, elementoInserir, posicao;

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

    printf("Digite o elemento que deseja inserir: ");
    scanf("%d", &elementoInserir);
    printf("Digite a posição onde deseja inserir o elemento (1 a %d): ", n + 1);
    scanf("%d", &posicao);

    if (posicao < 1 || posicao > n + 1) {
        printf("Posição inválida.\n");
        return 1; 
    }

    for (i = n; i >= posicao; i--) {
        vetor[i] = vetor[i - 1];
    }

    vetor[posicao - 1] = elementoInserir;
    n++; 

    printf("Vetor resultante: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
