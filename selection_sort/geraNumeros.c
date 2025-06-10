#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *pFile;
    int i, valor;

    // Parte 1: Gera números aleatórios e escreve no arquivo
    pFile = fopen("./numeros.txt", "w");
    if (pFile == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return 1;
    }

    srand(time(NULL));
    for (i = 0; i < 1000000; i++) {
        valor = rand() % 10;
        fprintf(pFile, "%d\n", valor);
    }
    fclose(pFile);

    pFile = fopen("./numeros.txt", "r");
    if (pFile == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return 1;
    }

    while (fscanf(pFile, "%d", &valor) == 1) {
        valor += rand() % 5 + 1;
    }

    fclose(pFile);
    return 0;
}
