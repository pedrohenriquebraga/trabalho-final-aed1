#include "listaString.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int verificaListaStr(ListaStrings *lista) {
   if (lista == NULL) {
      printf("LISTA NAO ALOCADA\n");
      exit(1);
   }

   return SUCESSO;
}

ListaStrings *criaListaStrings() {

   ListaStrings * lista = (ListaStrings *) malloc(sizeof(ListaStrings));

   verificaListaStr(lista);
   lista -> inicio = NULL;
   lista -> final = NULL;
   lista -> qtd = 0;

   return lista;
}

int tamanhoListaStr(ListaStrings * lista){
   return lista -> qtd;
}

int limpaListaStr(ListaStrings *lista) {

   verificaListaStr(lista);
   
   while (lista -> qtd > 0) {
      removeStrInicio(lista);
   }
   
   free(lista);

   return SUCESSO;
}

int insereStrFinal(ListaStrings *lista, char * elem) {

   verificaListaStr(lista);

   ElemStr * novoElem = (ElemStr *) malloc(sizeof(ElemStr));

   strcpy(novoElem -> dado, elem);
   novoElem -> ant = NULL;
   novoElem -> prox = NULL;
   
   if (novoElem == NULL) {
      return FALHA;
   }

   if (lista -> qtd == 0) {
      lista -> inicio = novoElem;
      lista -> final = novoElem;
   } else {
      ElemStr * aux = lista -> final;
      lista -> final = novoElem;
      novoElem -> ant = aux;
      aux -> prox = novoElem;
   }

   lista -> qtd++;

   return SUCESSO;
}

int insereStrInicio(ListaStrings *lista, char * elem) {
   verificaListaStr(lista);

   ElemStr *novoElem = (ElemStr *) malloc(sizeof(ElemStr));
   if (novoElem == NULL) return FALHA;

   strcpy(novoElem->dado, elem);
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

int removeStrInicio(ListaStrings *lista) {
   verificaListaStr(lista);
   if (lista->qtd == 0) {
       return FALHA;
   }

   ElemStr *aux = lista->inicio;

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

int removeStrFinal(ListaStrings *lista) {
   verificaListaStr(lista);
   if (lista -> qtd == 0) {
      return FALHA;
   }

   ElemStr * aux = lista -> final;

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

int imprimeListaStr(ListaStrings *lista) {
   verificaListaStr(lista);

   if (lista -> qtd == 0) {
      printf("A LISTA ESTA VAZIA\n");
      return FALHA;
   }

   ElemStr * aux = lista -> inicio;
   int i = 0;
   while (aux != NULL) {
      printf("\033[3mElem %d: %s\033[m\n", i, aux -> dado);
      i++;
      aux = aux -> prox;
   }
   return SUCESSO;
   
}