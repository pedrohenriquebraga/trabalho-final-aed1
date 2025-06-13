#include "listaString.h"
#include "listaNumeros.h"
#include "geraNumeros.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    ListaNumeros *lista_sequencial = criaListaNumeros();
    ListaNumeros *lista_aleatoria = criaListaNumeros();

    ListaStrings *lista_nomes = criaListaStrings();

    int qtdElementos = 1000, numero;
    clock_t tempoInicio, tempoFim;

    double tempoGasto, trocasPorSec;
    
    unsigned int qtdTrocas;
    char * nome;

    FILE *arquivoNums = fopen("numeros.txt", "r");
    FILE *arquivoNomes = fopen("nomes.txt", "r");

    if (arquivoNums == NULL) {
        perror("Erro ao abrir o arquivo de numeros");
        return 1;
    }

    if (arquivoNomes == NULL) {
        perror("Erro ao abrir o arquivo de nomes");
        return 1;
    }

    while (fscanf(arquivoNomes, "%[^\n]%*c", nome) == 1) {
        insereStrInicio(lista_nomes, nome);
    }

    selectionSortLexDecresc(lista_nomes);
    imprimeListaStr(lista_nomes);

    // geraListaNumerosEmSequencia(qtdElementos);

    // while (fscanf(arquivoNums, "%d", &numero) == 1) {
    //     insereNumInicio(lista_sequencial, numero);
    // }

    // fclose(arquivoNums);

    // printf("\nA LISTA TESTADA CONTÉM %d ELEMENTOS INICIALMENTE ORDENADA\n", qtdElementos);
    
    // printf("==============================================================\n");
    // printf("TESTE ORDENACAO CRESCENTE EM SEQUENCIA:\n");

    // tempoInicio = clock();

    // qtdTrocas = selectionSortCresc(lista_sequencial);

    // tempoFim = clock();
    // tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    // trocasPorSec = qtdTrocas / tempoGasto;

    // printf("FORAM REALIZADAS %u TROCAS DE ELEMENTOS\n", qtdTrocas);
    // printf("O TEMPO DE EXECUÇÃO FOI DE %.3lfs PARA ESSA OPERAÇÃO\n", tempoGasto);
    // printf("FORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\n", trocasPorSec);
    // printf("==============================================================\n");
    // printf("TESTE ORDENACAO DECRESCENTE EM SEQUENCIA CRESCENTE:\n");

    // tempoInicio = clock();

    // qtdTrocas = selectionSortDecresc(lista_sequencial);

    // tempoFim = clock();
    // tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    // trocasPorSec = qtdTrocas / tempoGasto;

    // printf("FORAM REALIZADAS %u TROCAS DE ELEMENTOS\n", qtdTrocas);
    // printf("O TEMPO DE EXECUÇÃO FOI DE %.3lfs PARA ESSA OPERAÇÃO\n", tempoGasto);
    // printf("FORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\n", trocasPorSec);

    // printf("==============================================================\n");
    // printf("A LISTA TESTADA CONTÉM %d ELEMENTOS GERADOS ALEATORIAMENTE\n", qtdElementos);
    // printf("==============================================================\n");

    // geraListaNumerosAleatorios(qtdElementos);
    // arquivoNums = fopen("numeros.txt", "r");

    // while (fscanf(arquivoNums, "%d", &numero) == 1) {
    //     insereNumInicio(lista_aleatoria, numero);
    // }

    // fclose(arquivoNums);

    // printf("TESTE ORDENACAO CRESCENTE:\n");
    // tempoInicio = clock();

    // qtdTrocas = selectionSortDecresc(lista_aleatoria);

    // tempoFim = clock();
    // tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    // trocasPorSec = qtdTrocas / tempoGasto;

    // printf("FORAM REALIZADAS %u TROCAS DE ELEMENTOS\n", qtdTrocas);
    // printf("O TEMPO DE EXECUÇÃO FOI DE %.3lfs PARA ESSA OPERAÇÃO\n", tempoGasto);
    // printf("FORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\n", trocasPorSec);

    // printf("==============================================================\n");

    limpaListaNum(lista_sequencial);
    limpaListaNum(lista_aleatoria);
    limpaListaStr(lista_nomes);

    return 0;
}
