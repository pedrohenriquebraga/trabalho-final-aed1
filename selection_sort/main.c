#include "lista.h"
#include "geraNumeros.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Lista *lista = criaLista();

    geraListaNumeros(50);

    FILE *arquivo = fopen("numeros.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int numero;
    while (fscanf(arquivo, "%d", &numero) == 1) {
        insereInicio(lista, numero);
    }

    fclose(arquivo);

    printf("APOS ORDENACAO:\n");
    selectionSort(lista);
    imprimeLista(lista);
    limpaLista(lista);

    return 0;
}
