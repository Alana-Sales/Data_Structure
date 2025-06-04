#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    float *temperaturas = NULL; 
    char continuar;

    printf("Quantas leituras de temperatura você deseja inserir? ");
    scanf("%d", &n);

    temperaturas = (float *)malloc(n * sizeof(float));
    if (temperaturas == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1; 
    }

    for (i = 0; i < n; i++) {
        printf("Digite a temperatura do sensor %d: ", i + 1);
        scanf("%f", &temperaturas[i]);
    }

    printf("Você gostaria de adicionar mais sensores? (s/n): ");
    scanf(" %c", &continuar);

    while (continuar == 's' || continuar == 'S') {
        int novoQuantidade;
        printf("Quantos novos sensores você deseja adicionar? ");
        scanf("%d", &novoQuantidade);

        temperaturas = (float *)realloc(temperaturas, (n + novoQuantidade) * sizeof(float));
        if (temperaturas == NULL) {
            printf("Erro ao realocar memória!\n");
            return 1; 
        }

        for (i = n; i < n + novoQuantidade; i++) {
            printf("Digite a temperatura do sensor %d: ", i + 1);
            scanf("%f", &temperaturas[i]);
        }

        n += novoQuantidade;

        printf("Você gostaria de adicionar mais sensores? (s/n): ");
        scanf(" %c", &continuar);
    }

    printf("Temperaturas registradas:\n");
    for (i = 0; i < n; i++) {
        printf("Sensor %d: %.2f\n", i + 1, temperaturas[i]);
    }

    free(temperaturas);

    return 0;
}
