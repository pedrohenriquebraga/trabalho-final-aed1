#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

int trocaElementos(int * dado1, int * dado2) {
 
   if (dado1 == dado2) {
      return INVALIDO;
   }

   int temp = *dado1;
   *dado1 = *dado2;
   *dado2 = temp;

   return SUCESSO;
}

int selectionSortCresc(int *dados, unsigned int len) {

   if (len < 2) {
      return INVALIDO;
   }

    int trocasRealizadas = 0;
    long int contIter = 0;

    int i = 0;
    
    while (i < len) {
       int menor = i;
       int j = i + 1;
 
       while (j < len) {
          if (dados[j] < dados[i]) {
             menor = j;
          }
          j++;
          contIter++;
       }
 
       if (menor != i) {
          trocaElementos(&dados[i], &dados[menor]);
          int temp = i;
          i = menor;
          menor = temp;
          trocasRealizadas++;
       }
 
       i++;
       contIter++;
    }
 
    printf("A LISTA FOI PERCORRIDA %ld VEZES\n", contIter);
    return trocasRealizadas;
 }
 
int selectionSortDecresc(int *dados, unsigned int len) {
    
   if (len < 2) {
      return INVALIDO;
   }

    int trocasRealizadas = 0;
    long int contIter = 0;

    int i = 0;
    
    while (i < len) {
       int maior = i;
       int j = i + 1;
 
       while (j < len) {
          if (dados[j] > dados[i]) {
             maior = j;
          }
          j++;
          contIter++;
       }
 
       if (maior != i) {
          trocaElementos(&dados[i], &dados[maior]);
          int temp = i;
          i = maior;
          maior = temp;
          trocasRealizadas++;
       }
 
       i++;
       contIter++;
    }
 
    printf("A LISTA FOI PERCORRIDA %ld VEZES\n", contIter);
    return trocasRealizadas;
 }
