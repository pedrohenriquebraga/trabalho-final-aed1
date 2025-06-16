#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"lista.h"

struct elemento{
    int vetor[N];
    int qnt;
};

typedef struct elemento Elem;

void *criaLista(){
    Lista * lista = (Lista*)malloc(sizeof(Lista));
    if(lista == NULL) exit(1);

    lista->qnt = 0;
    return lista;
}

void imprimeLista(Lista * lista){
    if(lista == NULL) exit(1);

    for(int i = 0; i < lista->qnt; i++){
        printf("Elemento: %d: %d\n", i+1, lista->vetor[i]);
    }
}

void insereInicio(Lista * lista, int num){
    if(lista == NULL) exit(1);

    if(lista->qnt == 0) lista->vetor[0] = num;
    else if(lista->qnt != N){
        int tamanho = lista->qnt;
        while(tamanho > 0){
            lista->vetor[tamanho] = lista->vetor[tamanho - 1];
            tamanho--;
        }
        lista->vetor[tamanho] = num; 
    }
    lista->qnt++;
}

void insereFinal(Lista * lista, int num){
    if(lista == NULL) exit(1);

    if(lista->qnt != N){
        lista->vetor[lista->qnt] = num;
        lista->qnt++;
    }
}

void removeInicio(Lista * lista){
    if(lista == NULL) exit(1);

    if(lista->qnt == 0) return;
    else{
        for(int i = 0; i < lista->qnt; i++){
            lista->vetor[i] = lista->vetor[i+1];
        }
        lista->qnt--;
    }
}

void removeFinal(Lista * lista){
    if(lista == NULL) exit(1);

    if(lista->qnt != 0){
        lista->qnt--;
    }

}

void destroiLista(Lista * lista){
    if(lista == NULL) exit(1);

    free(lista);
}

int SelectionSortCresc(Lista * lista){
    if(lista == NULL) exit(1);
    int cont = 0;

    for(int i = 0; i < lista->qnt - 1; i++){

        int menor_indice = i;
        for(int j = i+1; j < lista->qnt; j++){
            if(lista->vetor[j] < lista->vetor[menor_indice]){
                menor_indice = j;
            }
        }

        if (menor_indice != i) {
            int temp = lista->vetor[menor_indice];
            lista->vetor[menor_indice] = lista->vetor[i];
            lista->vetor[i] = temp;
            cont++;
        }
    }
    return cont;
}

int SelectionSortDescres(Lista * lista){
    if(lista == NULL) exit(1);
    int cont = 0;

    for(int i = 0; i < lista->qnt - 1; i++){

        int menor_indice = i;
        for(int j = i+1; j < lista->qnt; j++){
            if(lista->vetor[j] > lista->vetor[menor_indice]){
                menor_indice = j;
            }
        }

        if (menor_indice != i) {
            int temp = lista->vetor[menor_indice];
            lista->vetor[menor_indice] = lista->vetor[i];
            lista->vetor[i] = temp;
            cont++;
        }
    }
    return cont;
}

void geraListaNumerosEmSequencia(int qnt_elementos){
    FILE *pFile;
    int i, valor;

    pFile = fopen("numeros.txt", "w");
    if (pFile == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (i = 0; i< qnt_elementos; i++){
        fprintf(pFile, "%d\n", i);
    }
    fclose(pFile);

}

void geraListaNumerosAleatorios(int qnt_elementos){
    srand(5);

    FILE *pFile;
    int i, valor;

    pFile = fopen("./numeros.txt", "w");
    if (pFile == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (i = 0; i < qnt_elementos; i++) {
        valor = rand() % 100;
        fprintf(pFile, "%d\n", valor);
    }

    fclose(pFile);
}