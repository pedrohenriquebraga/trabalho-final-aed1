#include "geraNumeros.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// @brief Gera números aleatórios entre 0 e 100 e coloca em um arquivo "numeros.txt"
/// @param qtd Quantidade de números a serem gerados
/// @return A função não retorna nada, mas escreve os números no arquivo "numeros.txt"

void geraListaNumerosAleatorios(unsigned int qtd) {
    srand(5);

    FILE *pFile;
    int i, valor;

    pFile = fopen("./numeros.txt", "w");
    if (pFile == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (i = 0; i < qtd; i++) {
        valor = (rand() % 200) - 100;
        fprintf(pFile, "%d\n", valor);
    }

    fclose(pFile);
    return;
}

void geraListaNumerosEmSequencia(unsigned int qtd) {

    FILE *pFile;
    int i, valor;

    pFile = fopen("./numeros.txt", "w");
    if (pFile == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (i = qtd; i >= 1; i--) {
        fprintf(pFile, "%d\n", i);
    }
    fclose(pFile);

    pFile = fopen("./numeros.txt", "r");
    if (pFile == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    fclose(pFile);

}
