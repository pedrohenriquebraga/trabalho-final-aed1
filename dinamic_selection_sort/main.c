#include "listaString.h"
#include "listaNumeros.h"
#include "geraNumeros.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

int main() {
    system("clear");
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Ativa e desativa a exibição das listas
    bool printListas = false;

    ListaNumeros *lista_sequencial = criaListaNumeros();
    ListaNumeros *lista_aleatoria = criaListaNumeros();
    ListaStrings *lista_nomes = criaListaStrings();

    char nome[TAM_MAX];
    unsigned int qtdTrocas;
    int numero;
    double tempoGasto, trocasPorSec;
    clock_t tempoInicio, tempoFim;

    FILE *arquivoNomes = fopen("nomes.txt", "r");
    FILE *arquivoNums = fopen("numeros.txt", "r");

    printf("==============================================================");
    printf("\n\n                       SELECTION SORT\n\n");

    if (arquivoNums == NULL) {
        perror("Erro ao abrir o arquivo de numeros");
        return 1;
    }

    if (arquivoNomes == NULL) {
        perror("Erro ao abrir o arquivo de nomes");
        return 1;
    }

    int contNomes = 0;

    // Defina um valor entre 0 e 10 milhões para nomes, e ilimitado para numeros
    int limiteNomes = 25000, qtdNumeros = 500000;

    while (fscanf(arquivoNomes, "%[^\n]%*c", nome) == 1) {
        contNomes++;
        insereStrInicio(lista_nomes, nome);
        if (contNomes == limiteNomes) {
            break;
        }
    }

    geraListaNumerosEmSequencia(qtdNumeros);

    while (fscanf(arquivoNums, "%d", &numero) == 1) {
        insereNumInicio(lista_sequencial, numero);
    }

    fclose(arquivoNums);
    fclose(arquivoNomes);

    printf("==============================================================\n");
    printf("A LISTA TESTADA CONTEM %d ELEMENTOS INICIALMENTE ORDENADA\n", qtdNumeros);
    printf("==============================================================\n");
    printf("TESTE ORDENACAO CRESCENTE EM SEQUENCIA:\n");
    printf("==============================================================\n\n");


    if (printListas) {
        printf("LISTA ANTES DA ORDENACAO: \n");
        imprimeListaNum(lista_sequencial);
        printf("==============================================================\n");
    }

    tempoInicio = clock();

    qtdTrocas = selectionSortCresc(lista_sequencial);

    tempoFim = clock();
    tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    trocasPorSec = qtdTrocas / tempoGasto;

    printf("\033[1;35mFORAM REALIZADAS %u TROCAS DE ELEMENTOS\033[m\n", qtdTrocas);
    printf("\033[1;36mO TEMPO DE EXECUCAO FOI DE %.3lfs PARA ESSA OPERACAO\033[m\n", tempoGasto);
    printf("\033[1;32mFORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\033[m\n", trocasPorSec);
    
    
    if (printListas) {
        printf("LISTA APOS ORDENACAO: \n");
        imprimeListaNum(lista_sequencial);
    }

    printf("\n==============================================================\n");
    printf("TESTE ORDENACAO DECRESCENTE EM SEQUENCIA CRESCENTE:\n");
    printf("==============================================================\n\n");

    
    if (printListas) {
        printf("LISTA ANTES DA ORDENACAO: \n");
        imprimeListaNum(lista_sequencial);
        printf("==============================================================\n");
    }

    tempoInicio = clock();

    qtdTrocas = selectionSortDecresc(lista_sequencial);

    tempoFim = clock();
    tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    trocasPorSec = qtdTrocas / tempoGasto;

    printf("\033[1;35mFORAM REALIZADAS %u TROCAS DE ELEMENTOS\033[m\n", qtdTrocas);
    printf("\033[1;36mO TEMPO DE EXECUCAO FOI DE %.3lfs PARA ESSA OPERACAO\033[m\n", tempoGasto);
    printf("\033[1;32mFORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\033[m\n", trocasPorSec);
    
    if (printListas) {
        printf("LISTA APOS ORDENACAO: \n");
        imprimeListaNum(lista_sequencial);
    }

    printf("\n==============================================================\n");
    printf("A LISTA TESTADA CONTEM %d ELEMENTOS GERADOS ALEATORIAMENTE\n", qtdNumeros);
    printf("==============================================================\n");

    geraListaNumerosAleatorios(qtdNumeros);
    arquivoNums = fopen("numeros.txt", "r");

    while (fscanf(arquivoNums, "%d", &numero) == 1) {
        insereNumInicio(lista_aleatoria, numero);
    }

    fclose(arquivoNums);

    printf("TESTE ORDENACAO CRESCENTE:\n");
    printf("==============================================================\n\n");

    
    if (printListas) {
        printf("LISTA ANTES DA ORDENACAO: \n");
        imprimeListaNum(lista_aleatoria);
        printf("==============================================================\n");
    }

    tempoInicio = clock();

    qtdTrocas = selectionSortCresc(lista_aleatoria);

    tempoFim = clock();
    tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    trocasPorSec = qtdTrocas / tempoGasto;

    printf("\033[1;35mFORAM REALIZADAS %u TROCAS DE ELEMENTOS\033[m\n", qtdTrocas);
    printf("\033[1;36mO TEMPO DE EXECUCAO FOI DE %.3lfs PARA ESSA OPERACAO\033[m\n", tempoGasto);
    printf("\033[1;32mFORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\033[m\n", trocasPorSec);

    if (printListas) {
        printf("LISTA APOS ORDENACAO: \n");
        imprimeListaNum(lista_aleatoria);
    }

    printf("\n==============================================================\n");
    printf("A LISTA TESTADA CONTEM %d NOMES NAO ORDENADOS\n", contNomes);
    printf("==============================================================\n\n");
    
    if (printListas) {
        printf("LISTA ANTES DA ORDENACAO: \n");
        imprimeListaStr(lista_nomes);
        printf("==============================================================\n");
    }


    tempoInicio = clock();

    qtdTrocas = selectionSortLexCresc(lista_nomes);

    tempoFim = clock();
    tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    trocasPorSec = qtdTrocas / tempoGasto;

    printf("\033[1;35mFORAM REALIZADAS %u TROCAS DE ELEMENTOS\033[m\n", qtdTrocas);
    printf("\033[1;36mO TEMPO DE EXECUCAO FOI DE %.3lfs PARA ESSA OPERACAO\033[m\n", tempoGasto);
    printf("\033[1;32mFORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\033[m\n", trocasPorSec);

    if (printListas) {
        printf("LISTA APOS ORDENACAO: \n");
        imprimeListaStr(lista_nomes);
    }
    printf("\n==============================================================\n");

    limpaListaNum(lista_sequencial);
    limpaListaNum(lista_aleatoria);
    limpaListaStr(lista_nomes);

    return 0;
}
