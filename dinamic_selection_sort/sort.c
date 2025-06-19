#include "listaNumeros.h"
#include "listaString.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int trocaElementosNum(ListaNumeros *lista, ElemNum *elem1, ElemNum *elem2) {
   verificaListaNum(lista);

   if (elem1 == NULL || elem2 == NULL || elem1 == elem2)
   {
      return FALHA;
   }

   ElemNum *ant1 = elem1->ant;
   ElemNum *prox1 = elem1->prox;
   ElemNum *ant2 = elem2->ant;
   ElemNum *prox2 = elem2->prox;

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

int trocaElementosStr(ListaStrings *lista, ElemStr *elem1, ElemStr *elem2) {
   verificaListaStr(lista);

   if (elem1 == NULL || elem2 == NULL || elem1 == elem2)
   {
      return FALHA;
   }

   ElemStr *ant1 = elem1->ant;
   ElemStr *prox1 = elem1->prox;
   ElemStr *ant2 = elem2->ant;
   ElemStr *prox2 = elem2->prox;

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

int comparaPalavras(char *palavra1, char *palavra2) {
   if (palavra1 == NULL || palavra2 == NULL) {
       return INVALIDO;
   }
   if (palavra1 == palavra2) {
       return 0;
   }

   int comparacao = strcoll(palavra1, palavra2);

   if (comparacao < 0) {
       return 1;
   } else if (comparacao > 0) {
       return 0;
   } else {
       int tamanho1 = strlen(palavra1);
       int tamanho2 = strlen(palavra2);

       if (tamanho1 < tamanho2) {
         return 1;
       } 

       return 0;
   }
}

int selectionSortCresc(ListaNumeros *lista) {
   verificaListaNum(lista);

   if (lista->qtd < 2)
      return INVALIDO;

   int trocasRealizadas = 0;
   long int contIter = 0;

   ElemNum *i = lista->inicio;

   while (i != NULL)
   {
      ElemNum *menor = i;
      ElemNum *j = i->prox;

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
         trocaElementosNum(lista, i, menor);
         ElemNum *temp = i;
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

int selectionSortDecresc(ListaNumeros *lista)
{
   verificaListaNum(lista);

   if (lista->qtd < 2)
      return FALHA;

   int trocasRealizadas = 0;
   long int contIter = 0;
   ElemNum *i = lista->inicio;

   while (i != NULL)
   {
      ElemNum *maior = i;
      ElemNum *j = i->prox;

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
         trocaElementosNum(lista, i, maior);
         ElemNum *temp = i;
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

int selectionSortLexCresc(ListaStrings *lista)
{
   verificaListaStr(lista);

   if (lista->qtd < 2)
      return INVALIDO;

   int trocasRealizadas = 0;

   ElemStr *i = lista->inicio;

   while (i != NULL)
   {
      ElemStr *menor = i;
      ElemStr *j = i->prox;

      while (j != NULL) {
         if (comparaPalavras(j -> dado, menor -> dado)) {
            menor = j;
         }
         j = j->prox;
      }

      if (menor != i)
      {
         trocaElementosStr(lista, i, menor);
         ElemStr *temp = i;
         i = menor;
         menor = temp;
         trocasRealizadas++;
      }

      i = i->prox;
   }

   return trocasRealizadas;
}

int selectionSortLexDecresc(ListaStrings *lista)
{
   verificaListaStr(lista);

   if (lista->qtd < 2)
      return INVALIDO;

   int trocasRealizadas = 0;

   ElemStr *i = lista->inicio;

   while (i != NULL)
   {
      ElemStr *maior = i;
      ElemStr *j = i->prox;

      while (j != NULL) {
         if (comparaPalavras(j -> dado, maior -> dado) == 0) {
            maior = j;
         }
         j = j -> prox;
      }

      if (maior != i) {
         trocaElementosStr(lista, maior, i);
         ElemStr *temp = i;
         i = maior;
         maior = temp;
         trocasRealizadas++;
      }

      i = i->prox;
   }

   return trocasRealizadas;
}