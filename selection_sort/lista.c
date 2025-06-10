#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

struct elemento {
   int dado;
   struct elemento * prox;
   struct elemento * ant;
};

struct descritor {
   struct elemento * inicio;
   struct elemento * final;
   int qtd;
};

typedef struct elemento Elem;

int trocaElementos(Lista *lista, Elem *elem1, Elem *elem2) {
   verificaLista(lista);
   
   if (elem1 == NULL || elem2 == NULL || elem1 == elem2) {
      return FALHA;
   }

   Elem *ant1 = elem1->ant;
   Elem *prox1 = elem1->prox;
   Elem *ant2 = elem2->ant;
   Elem *prox2 = elem2->prox;

   if (prox1 == elem2) {
      elem1->prox = prox2;
      elem1->ant = elem2;
      elem2->prox = elem1;
      elem2->ant = ant1;

      if (ant1 != NULL) {
         ant1->prox = elem2;
      }
      if (prox2 != NULL) {
         prox2->ant = elem1;
      }
   } else if (prox2 == elem1) {
      elem2->prox = prox1;
      elem2->ant = elem1;
      elem1->prox = elem2;
      elem1->ant = ant2;

      if (ant2 != NULL) {
         ant2->prox = elem1;
      }
      if (prox1 != NULL) {
         prox1->ant = elem2;
      }
   }
   else {
      elem1->prox = prox2;
      elem1->ant = ant2;
      elem2->prox = prox1;
      elem2->ant = ant1;

      if (ant1 != NULL) {
         ant1->prox = elem2;
      }
      if (prox1 != NULL) {
         prox1->ant = elem2;
      }
      if (ant2 != NULL) {
         ant2->prox = elem1;
      }
      if (prox2 != NULL) {
         prox2->ant = elem1;
      }
   }

   if (lista->inicio == elem1) {
      lista->inicio = elem2;
   } else if (lista->inicio == elem2) {
      lista->inicio = elem1;
   }

   if (lista->final == elem1) {
      lista->final = elem2;
   } else if (lista->final == elem2) {
      lista->final = elem1;
   }

   return SUCESSO;
}

int verificaLista(Lista *lista) {
   if (lista == NULL) {
      printf("LISTA NAO ALOCADA\n");
      exit(1);
   }

   return SUCESSO;
}

Lista *criaLista() {

   Lista * lista = (Lista *) malloc(sizeof(Lista));

   verificaLista(lista);
   lista -> inicio = NULL;
   lista -> final = NULL;
   lista -> qtd = 0;

   return lista;
}

int tamanhoLista(Lista * lista){
   return lista->qtd;
}

int selectionSort(Lista *lista) {
   verificaLista(lista);

   if (lista -> qtd < 2) return FALHA;

   Elem *i = lista->inicio;
   
   while (i != NULL) {
      Elem *menor = i;
      Elem *j = i -> prox;

      while (j != NULL) {
         if (j->dado < menor->dado) {
            menor = j;
         }
         j = j->prox;
      }

      if (menor != i) {
         trocaElementos(lista, i, menor);
         Elem *temp = i;
         i = menor;
         menor = temp;
      }

      i = i->prox;
   }

   return SUCESSO;
}


int limpaLista(Lista *lista) {

   verificaLista(lista);
   
   while (lista -> qtd > 0) {
      removeInicio(lista);
   }
   
   free(lista);

   return SUCESSO;
}


int insereFinal(Lista *lista, int elem) {

   verificaLista(lista);

   Elem * novoElem = (Elem *) malloc(sizeof(Elem));

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