#include "listaString.h"
#include "listaNumeros.h"
#include "geraNumeros.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    system("clear");
    setlocale(LC_ALL, "pt_BR.UTF-8");
    ListaNumeros *lista_sequencial = criaListaNumeros();
    ListaNumeros *lista_aleatoria = criaListaNumeros();

    ListaStrings *lista_nomes = criaListaStrings();

    int qtdElementos = 50000, qtdNomes = 0, numero;
    clock_t tempoInicio, tempoFim;

    double tempoGasto, trocasPorSec;
    
    unsigned int qtdTrocas;
    char nome[TAM_MAX];

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
        qtdNomes++;
        insereStrInicio(lista_nomes, nome);
    }

    geraListaNumerosEmSequencia(qtdElementos);

    while (fscanf(arquivoNums, "%d", &numero) == 1) {
        insereNumInicio(lista_sequencial, numero);
    }

    fclose(arquivoNums);
    fclose(arquivoNomes);

    printf("\nA LISTA TESTADA CONTEM %d ELEMENTOS INICIALMENTE ORDENADA\n", qtdElementos);
    
    printf("==============================================================\n");
    printf("TESTE ORDENACAO CRESCENTE EM SEQUENCIA:\n");

    tempoInicio = clock();

    qtdTrocas = selectionSortCresc(lista_sequencial);

    tempoFim = clock();
    tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    trocasPorSec = qtdTrocas / tempoGasto;

    printf("FORAM REALIZADAS %u TROCAS DE ELEMENTOS\n", qtdTrocas);
    printf("O TEMPO DE EXECUCAO FOI DE %.3lfs PARA ESSA OPERACAO\n", tempoGasto);
    printf("FORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\n", trocasPorSec);
    printf("==============================================================\n");
    printf("TESTE ORDENACAO DECRESCENTE EM SEQUENCIA CRESCENTE:\n");

    tempoInicio = clock();

    qtdTrocas = selectionSortDecresc(lista_sequencial);

    tempoFim = clock();
    tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    trocasPorSec = qtdTrocas / tempoGasto;

    printf("FORAM REALIZADAS %u TROCAS DE ELEMENTOS\n", qtdTrocas);
    printf("O TEMPO DE EXECUCAO FOI DE %.3lfs PARA ESSA OPERACAO\n", tempoGasto);
    printf("FORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\n", trocasPorSec);

    printf("==============================================================\n");
    printf("A LISTA TESTADA CONTEM %d ELEMENTOS GERADOS ALEATORIAMENTE\n", qtdElementos);
    printf("==============================================================\n");

    geraListaNumerosAleatorios(qtdElementos);
    arquivoNums = fopen("numeros.txt", "r");

    while (fscanf(arquivoNums, "%d", &numero) == 1) {
        insereNumInicio(lista_aleatoria, numero);
    }

    fclose(arquivoNums);

    printf("TESTE ORDENACAO CRESCENTE:\n");
    tempoInicio = clock();

    qtdTrocas = selectionSortDecresc(lista_aleatoria);

    tempoFim = clock();
    tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    trocasPorSec = qtdTrocas / tempoGasto;

    printf("FORAM REALIZADAS %u TROCAS DE ELEMENTOS\n", qtdTrocas);
    printf("O TEMPO DE EXECUCAO FOI DE %.3lfs PARA ESSA OPERACAO\n", tempoGasto);
    printf("FORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\n", trocasPorSec);

    printf("==============================================================\n");
    printf("A LISTA TESTADA CONTEM %d NOMES NAO ORDENADOS\n", qtdNomes);
    printf("==============================================================\n");
    
    tempoInicio = clock();

    qtdTrocas = selectionSortLexCresc(lista_nomes);

    tempoFim = clock();
    tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    trocasPorSec = qtdTrocas / tempoGasto;

    printf("FORAM REALIZADAS %u TROCAS DE ELEMENTOS\n", qtdTrocas);
    printf("O TEMPO DE EXECUCAO FOI DE %.3lfs PARA ESSA OPERACAO\n", tempoGasto);
    printf("FORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\n", trocasPorSec);

    limpaListaNum(lista_sequencial);
    limpaListaNum(lista_aleatoria);
    limpaListaStr(lista_nomes);

    return 0;
}
