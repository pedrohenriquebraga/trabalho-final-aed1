#include "listaString.h"
#include "listaNumeros.h"
#include "geraNumeros.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    ListaStrings *lista_sequencial = criaLista();
    ListaStrings *lista_aleatoria = criaLista();

    int qtdElementos = 1000, numero;
    clock_t tempoInicio;
    clock_t tempoFim;
    double tempoGasto, trocasPorSec;
    unsigned int qtdTrocas;

    geraListaNumerosEmSequencia(qtdElementos);

    FILE *arquivo = fopen("numeros.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while (fscanf(arquivo, "%d", &numero) == 1) {
        insereInicio(lista_sequencial, numero);
    }

    fclose(arquivo);

    printf("\nA LISTA TESTADA CONTÉM %d ELEMENTOS INICIALMENTE ORDENADA\n", qtdElementos);
    
    printf("==============================================================\n");
    printf("TESTE ORDENACAO CRESCENTE EM SEQUENCIA:\n");

    tempoInicio = clock();

    qtdTrocas = selectionSortCresc(lista_sequencial);

    tempoFim = clock();
    tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    trocasPorSec = qtdTrocas / tempoGasto;

    printf("FORAM REALIZADAS %u TROCAS DE ELEMENTOS\n", qtdTrocas);
    printf("O TEMPO DE EXECUÇÃO FOI DE %.3lfs PARA ESSA OPERAÇÃO\n", tempoGasto);
    printf("FORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\n", trocasPorSec);
    printf("==============================================================\n");
    printf("TESTE ORDENACAO DECRESCENTE EM SEQUENCIA CRESCENTE:\n");

    tempoInicio = clock();

    qtdTrocas = selectionSortDecresc(lista_sequencial);

    tempoFim = clock();
    tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    trocasPorSec = qtdTrocas / tempoGasto;

    printf("FORAM REALIZADAS %u TROCAS DE ELEMENTOS\n", qtdTrocas);
    printf("O TEMPO DE EXECUÇÃO FOI DE %.3lfs PARA ESSA OPERAÇÃO\n", tempoGasto);
    printf("FORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\n", trocasPorSec);

    printf("==============================================================\n");
    printf("A LISTA TESTADA CONTÉM %d ELEMENTOS GERADOS ALEATORIAMENTE\n", qtdElementos);
    printf("==============================================================\n");

    geraListaNumerosAleatorios(qtdElementos);
    arquivo = fopen("numeros.txt", "r");

    while (fscanf(arquivo, "%d", &numero) == 1) {
        insereInicio(lista_aleatoria, numero);
    }

    fclose(arquivo);

    printf("TESTE ORDENACAO CRESCENTE:\n");
    tempoInicio = clock();

    qtdTrocas = selectionSortDecresc(lista_aleatoria);

    tempoFim = clock();
    tempoGasto = (double) (tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    trocasPorSec = qtdTrocas / tempoGasto;

    printf("FORAM REALIZADAS %u TROCAS DE ELEMENTOS\n", qtdTrocas);
    printf("O TEMPO DE EXECUÇÃO FOI DE %.3lfs PARA ESSA OPERAÇÃO\n", tempoGasto);
    printf("FORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\n", trocasPorSec);

    printf("==============================================================\n");

    limpaListaStr(lista_sequencial);
    limpaListaStr(lista_aleatoria);

    return 0;
}
