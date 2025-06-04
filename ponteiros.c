#include <stdio.h>

int contarVogais(const char *texto) {
    int contagem = 0;
    char vogais[] = "aeiouAEIOU";

    while (*texto) {
        for (int i = 0; i < 10; i++) {
            if (*texto == vogais[i]) {
                contagem++;
                break; 
            }
        }
        texto++; 
    }

    return contagem;
}

int main() {
    char texto[100];

    printf("Digite um texto: ");
    fgets(texto, sizeof(texto), stdin); 

    int resultado = contarVogais(texto);

    printf("O texto contém %d vogais.\n", resultado);

    return 0;
}
