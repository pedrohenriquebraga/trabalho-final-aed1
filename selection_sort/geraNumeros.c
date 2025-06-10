#include "geraNumeros.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// @brief Gera números aleatórios entre 0 e 100 e coloca em um arquivo "numeros.txt"
/// @param qtd Quantidade de números a serem gerados
/// @return A função não retorna nada, mas escreve os números no arquivo "numeros.txt"
void geraListaNumeros(int qtd) {
    FILE *pFile;
    int i, valor;

    // Parte 1: Gera números aleatórios e escreve no arquivo
    pFile = fopen("./numeros.txt", "w");
    if (pFile == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    srand(time(NULL));
    for (i = 0; i < qtd; i++) {
        valor = rand() % 100;
        fprintf(pFile, "%d\n", valor);
    }
    fclose(pFile);

    pFile = fopen("./numeros.txt", "r");
    if (pFile == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    while (fscanf(pFile, "%d", &valor) == 1) {
        valor += rand() % 5 + 1;
    }

    fclose(pFile);
}
