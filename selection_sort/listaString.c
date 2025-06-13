#include "listaString.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int verificaLista(Lista *lista) {
   if (lista == NULL) {
      printf("LISTA NAO ALOCADA\n");
      exit(1);
   }

   return SUCESSO;
}

Lista *criaListaNumeros() {

   Lista * lista = (Lista *) malloc(sizeof(Lista));

   verificaLista(lista);
   lista -> inicio = NULL;
   lista -> final = NULL;
   lista -> qtd = 0;

   return lista;
}

int tamanhoLista(Lista * lista){
   return lista -> qtd;
}

int limpaLista(Lista *lista) {

   verificaLista(lista);
   
   while (lista -> qtd > 0) {
      removeInicio(lista);
   }
   
   free(lista);

   return SUCESSO;
}

int insereFinal(Lista *lista, char * elem) {

   verificaLista(lista);

   Elem * novoElem = (Elem *) malloc(sizeof(Elem));

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
      Elem * aux = lista -> final;
      lista -> final = novoElem;
      novoElem -> ant = aux;
      aux -> prox = novoElem;
   }

   lista -> qtd++;

   return SUCESSO;
}

int insereInicio(Lista *lista, int elem) {
   verificaLista(lista);

   Elem *novoElem = (Elem *) malloc(sizeof(Elem));
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

int removeInicio(Lista *lista) {
   verificaLista(lista);
   if (lista->qtd == 0) {
       return FALHA;
   }

   Elem *aux = lista->inicio;

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

int removeFinal(Lista *lista) {
   verificaLista(lista);
   if (lista -> qtd == 0) {
      return FALHA;
   }

   Elem * aux = lista -> final;

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

int imprimeLista(Lista *lista) {
   verificaLista(lista);

   if (lista -> qtd == 0) {
      printf("A LISTA ESTA VAZIA\n");
      return FALHA;
   }

   Elem * aux = lista -> inicio;
   int i = 0;
   while (aux != NULL) {
      printf("Elem %d: %d\n", i, aux -> dado);
      i++;
      aux = aux -> prox;
   }
   return SUCESSO;
   
}