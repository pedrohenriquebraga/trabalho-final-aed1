#include "lista.h"
#include "geraNumeros.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Lista *lista = criaLista();
    Lista *lista2 = criaLista();

    geraListaNumeros(5);

    FILE *arquivo = fopen("numeros.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int numero;
    while (fscanf(arquivo, "%d", &numero) == 1) {
        insereInicio(lista, numero);
        insereInicio(lista2, numero);
    }

    fclose(arquivo);

    printf("LISTA ANTES DA ORDENACAO:\n");
    imprimeLista(lista);

    printf("APOS ORDENACAO CRESCENTE:\n");
    selectionSortCresc(lista);
    imprimeLista(lista);

    printf("APOS ORDENACAO DECRESCENTE:\n");
    selectionSortDecresc(lista2);
    imprimeLista(lista2);

    printf("APOS ORDENACAO CRESCENTE A PARTIR DA DECRESCENTE:\n");
    selectionSortDecresc(lista2);
    imprimeLista(lista2);

    limpaLista(lista);

    return 0;
}
