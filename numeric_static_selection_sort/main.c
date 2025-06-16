#include<stdio.h>
#include<time.h>
#include"lista.h"

int main(){

    Lista * listaSequencial = criaLista();
    Lista * listaAleatoria = criaLista();

    FILE * arquivo;
    int numero, qnt_elementos = 25000;
    clock_t tempoInicio;
    clock_t tempoFinal;

    //ordenando uma lista já ordenada de forma crescente

    geraListaNumerosEmSequencia(qnt_elementos);

    arquivo = fopen("numeros.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    while (fscanf(arquivo, "%d", &numero) == 1) {
        insereFinal(listaSequencial, numero);
    }

    fclose(arquivo);

    printf("A LISTA TESTADA CONTEM %d ELEMENTOS\n", qnt_elementos);
    printf("-----------------------------------\n");

    printf("TESTE EM LISTA JA ORDENADA\n"); 
    tempoInicio = clock();

    int qnt_trocas = SelectionSortCresc(listaSequencial);

    tempoFinal = clock();

    double tempoGasto = (double) (tempoFinal - tempoInicio) / CLOCKS_PER_SEC;
    double trocas_segundo = qnt_trocas / tempoGasto;

    printf("FORAM REALIZADAS %d TROCAS DE ELEMENTOS\n", qnt_trocas);
    printf("O TEMPO DE EXECUÇÃO FOI DE %.3lfs PARA ESSA OPERAÇÃO\n", tempoGasto);
    printf("FORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\n", trocas_segundo);
    printf("-----------------------------------\n");

    //ordenando uma lista já ordenada de forma decrescente

    printf("ORDENACAO DECRESCENTE EM LISTA CRESCENTE\n");

    tempoInicio = clock();

    qnt_trocas = SelectionSortDescres(listaSequencial);

    tempoFinal = clock();

    tempoGasto = (double) (tempoFinal - tempoInicio) / CLOCKS_PER_SEC;
    trocas_segundo = qnt_trocas / tempoGasto;

    printf("FORAM REALIZADAS %d TROCAS DE ELEMENTOS\n", qnt_trocas);
    printf("O TEMPO DE EXECUÇÃO FOI DE %.3lfs PARA ESSA OPERAÇÃO\n", tempoGasto);
    printf("FORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\n", trocas_segundo);
    printf("-----------------------------------\n");

    
    //ordenando uma lista aleatória de forma crescente

    printf("A LISTA TESTADA CONTEM %d NUMEROS ALEATORIOS\n", qnt_elementos);

    geraListaNumerosAleatorios(qnt_elementos);
    arquivo = fopen("numeros.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    while (fscanf(arquivo, "%d", &numero) == 1) {
        insereFinal(listaAleatoria, numero);
    }
    
    fclose(arquivo);
    
    printf("TESTE DE ORDENCAO CRESCENTE\n");
    
    tempoInicio = clock();
    
    qnt_trocas = SelectionSortCresc(listaAleatoria);
    
    //imprimeLista(listaAleatoria);
    
    tempoFinal = clock();
    
    tempoGasto = (double) (tempoFinal - tempoInicio) / CLOCKS_PER_SEC;
    trocas_segundo = qnt_trocas / tempoGasto;
    
    printf("FORAM REALIZADAS %d TROCAS DE ELEMENTOS\n", qnt_trocas);
    printf("O TEMPO DE EXECUÇÃO FOI DE %.3lfs PARA ESSA OPERAÇÃO\n", tempoGasto);
    printf("FORAM REALIZADAS %.2lf TROCAS POR SEGUNDO\n", trocas_segundo);
    printf("-----------------------------------\n");
    
    destroiLista(listaSequencial);
    destroiLista(listaAleatoria);
    
    return 0;
}