#include "listaNumeros.h"
#include <stdlib.h>
#include <stdio.h>

int verificaListaNum(ListaNumeros *lista) {
   if (lista == NULL) {
      printf("LISTA NAO ALOCADA\n");
      exit(1);
   }

   return SUCESSO;
}

ListaNumeros *criaListaNumeros() {

   ListaNumeros * lista = (ListaNumeros *) malloc(sizeof(ListaNumeros));

   verificaListaNum(lista);
   lista -> inicio = NULL;
   lista -> final = NULL;
   lista -> qtd = 0;

   return lista;
}

int tamanhoListaNum(ListaNumeros * lista){
   return lista->qtd;
}

int limpaListaNum(ListaNumeros *lista) {

   verificaListaNum(lista);
   
   while (lista -> qtd > 0) {
      removeNumInicio(lista);
   }
   
   free(lista);

   return SUCESSO;
}

int insereNumFinal(ListaNumeros *lista, int elem) {

   verificaListaNum(lista);

   ElemNum * novoElem = (ElemNum *) malloc(sizeof(ElemNum));

   novoElem -> dado = elem;
   novoElem -> ant = NULL;
   novoElem -> prox = NULL;
   
   if (novoElem == NULL) {
      return FALHA;
   }

   if (lista -> qtd == 0) {
      lista -> inicio = novoElem;
      lista -> final = novoElem;
   } else {
      ElemNum * aux = lista -> final;
      lista -> final = novoElem;
      novoElem -> ant = aux;
      aux -> prox = novoElem;
   }

   lista -> qtd++;

   return SUCESSO;
}

int insereNumInicio(ListaNumeros *lista, int elem) {
   verificaListaNum(lista);

   ElemNum *novoElem = (ElemNum *) malloc(sizeof(ElemNum));
   if (novoElem == NULL) return FALHA;

   novoElem->dado = elem;
   novoElem->prox = lista->inicio;
   novoElem->ant = NULL;

   if (lista->qtd == 0) {
       lista->inicio = novoElem;
       lista->final = novoElem;
   } else {
       lista->inicio->ant = novoElem; 
       lista->inicio = novoElem;
   }

   lista->qtd++;
   return SUCESSO;
}

int removeNumInicio(ListaNumeros *lista) {
   verificaListaNum(lista);
   if (lista->qtd == 0) {
       return FALHA;
   }

   ElemNum *aux = lista->inicio;

   if (lista->qtd == 1) {
       lista->inicio = NULL;
       lista->final = NULL;
   } else {
       lista->inicio = lista->inicio->prox;
       lista->inicio->ant = NULL;
   }
   
   free(aux);
   lista->qtd--;

   return SUCESSO;
}

int removeNumFinal(ListaNumeros *lista) {
   verificaListaNum(lista);
   if (lista -> qtd == 0) {
      return FALHA;
   }

   ElemNum * aux = lista -> final;

   if (lista -> inicio == lista -> final) {
      lista -> inicio = NULL;
      lista -> final = NULL;
   } else {
      lista -> final = aux -> ant;
      lista -> final -> prox = NULL;
   }

   lista -> qtd--;
   free(aux);
   return SUCESSO;
}

int imprimeListaNum(ListaNumeros *lista) {
   verificaListaNum(lista);

   if (lista -> qtd == 0) {
      printf("A LISTA ESTA VAZIA\n");
      return FALHA;
   }

   ElemNum * aux = lista -> inicio;
   int i = 0;
   while (aux != NULL) {
      printf("\033[3mElem %d: %d\033[m\n", i, aux -> dado);
      i++;
      aux = aux -> prox;
   }
   return SUCESSO;
   
}