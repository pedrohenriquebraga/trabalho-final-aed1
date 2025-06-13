#include "listaNumeros.h"
#include "listaString.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int trocaElementos(Lista *lista, Elem *elem1, Elem *elem2)
{
   verificaLista(lista);

   if (elem1 == NULL || elem2 == NULL || elem1 == elem2)
   {
      return FALHA;
   }

   Elem *ant1 = elem1->ant;
   Elem *prox1 = elem1->prox;
   Elem *ant2 = elem2->ant;
   Elem *prox2 = elem2->prox;

   if (prox1 == elem2)
   {
      elem1->prox = prox2;
      elem1->ant = elem2;
      elem2->prox = elem1;
      elem2->ant = ant1;

      if (ant1 != NULL)
      {
         ant1->prox = elem2;
      }
      if (prox2 != NULL)
      {
         prox2->ant = elem1;
      }
   }
   else if (prox2 == elem1)
   {
      elem2->prox = prox1;
      elem2->ant = elem1;
      elem1->prox = elem2;
      elem1->ant = ant2;

      if (ant2 != NULL)
      {
         ant2->prox = elem1;
      }
      if (prox1 != NULL)
      {
         prox1->ant = elem2;
      }
   }
   else
   {
      elem1->prox = prox2;
      elem1->ant = ant2;
      elem2->prox = prox1;
      elem2->ant = ant1;

      if (ant1 != NULL)
      {
         ant1->prox = elem2;
      }
      if (prox1 != NULL)
      {
         prox1->ant = elem2;
      }
      if (ant2 != NULL)
      {
         ant2->prox = elem1;
      }
      if (prox2 != NULL)
      {
         prox2->ant = elem1;
      }
   }

   if (lista->inicio == elem1)
   {
      lista->inicio = elem2;
   }
   else if (lista->inicio == elem2)
   {
      lista->inicio = elem1;
   }

   if (lista->final == elem1)
   {
      lista->final = elem2;
   }
   else if (lista->final == elem2)
   {
      lista->final = elem1;
   }

   return SUCESSO;
}

int comparaPalavras(char * palavra1, char * palavra2) {
   if (palavra1 == palavra2) {
      return INVALIDO;
   }

   if (strcmp(palavra1, palavra2) > 0) {
      return 0;
   }

   return 1;
}

int selectionSortCresc(Lista *lista)
{
   verificaLista(lista);

   if (lista->qtd < 2)
      return INVALIDO;

   int trocasRealizadas = 0;
   long int contIter = 0;

   Elem *i = lista->inicio;

   while (i != NULL)
   {
      Elem *menor = i;
      Elem *j = i->prox;

      while (j != NULL)
      {
         if (j->dado < menor->dado)
         {
            menor = j;
         }
         j = j->prox;
         contIter++;
      }

      if (menor != i)
      {
         trocaElementos(lista, i, menor);
         Elem *temp = i;
         i = menor;
         menor = temp;
         trocasRealizadas++;
      }

      i = i->prox;
      contIter++;
   }

   printf("A LISTA FOI PERCORRIDA %ld VEZES\n", contIter);
   return trocasRealizadas;
}

int selectionSortDecresc(Lista *lista)
{
   verificaLista(lista);

   if (lista->qtd < 2)
      return FALHA;

   int trocasRealizadas = 0;
   long int contIter = 0;
   Elem *i = lista->inicio;

   while (i != NULL)
   {
      Elem *maior = i;
      Elem *j = i->prox;

      while (j != NULL)
      {
         if (j->dado > maior->dado)
         {
            maior = j;
         }
         j = j->prox;
         contIter++;
      }

      if (maior != i)
      {
         trocaElementos(lista, i, maior);
         Elem *temp = i;
         i = maior;
         maior = temp;
         trocasRealizadas++;
      }

      i = i->prox;
      contIter++;
   }

   printf("A LISTA FOI PERCORRIDA %ld VEZES\n", contIter);

   return trocasRealizadas;
}

int selectionSortLexCresc(Lista *lista)
{
   verificaLista(lista);

   if (lista->qtd < 2)
      return INVALIDO;

   int trocasRealizadas = 0;
   long int contIter = 0;

   Elem *i = lista->inicio;

   while (i != NULL)
   {
      Elem *menor = i;
      Elem *j = i->prox;

      while (j != NULL) {
         if (comparaPalavras(j -> dado, menor -> dado)) {
            menor = j;
         }
         j = j->prox;
         contIter++;
      }

      if (menor != i)
      {
         trocaElementos(lista, i, menor);
         Elem *temp = i;
         i = menor;
         menor = temp;
         trocasRealizadas++;
      }

      i = i->prox;
      contIter++;
   }

   printf("A LISTA FOI PERCORRIDA %ld VEZES\n", contIter);
   return trocasRealizadas;
}