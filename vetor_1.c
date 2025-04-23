//Crie um algoritmo que pergunte ao usuário:
// • Quantos elementos deve conter em um vetor notas;
// • Quais as notas devem compor o vetor;
// • Imprima na tela os elementos do vetor;
// • Faça a média das notas e por fim imprima o resultado na tela

#include <stdio.h>

int main () {
    int n, i;
    float media, soma = 0.0;
    printf("Digite quantos elementos devem compor o vetor de notas: ");
    scanf("%d", &n);
    float notas[n];
    for(i = 0; i < n; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }
    printf("\nAs notas são:\n");
    for(i = 0; i < n; i++) {
        printf("%.2f ", notas[i]);
    }
    media = soma / n;
    printf("\n\nA media das notas é: %.2f\n", media);
    
    return 0;
}
