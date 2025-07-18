/*
Inversão de Vetor:
- Crie uma função que receba um vetor estático de inteiros e seu tamanho.
- Utilize ponteiros para inverter a ordem dos elementos dentro do próprio vetor.
- Não crie um novo vetor para armazenar o resultado.
- Após a chamada da função, imprima o vetor na tela
*/

#include <stdio.h>

int somaElementos(int *array, int tamanho) {
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += *(array + i);
    }
    
    return soma;
}

int main() {
    int array[100]; 
    int n;

    printf("Digite quantos elementos deseja inserir (max. 100): ");
    scanf("%d", &n);

    if (n > 100 || n <= 0) {
        printf("Número de elementos inválido. Deve ser entre 1 e 100.\n");
        return 1; 
    }

    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int resultado = somaElementos(array, n);

    printf("A soma dos elementos do array é: %d\n", resultado);

    return 0;
}
