#ifndef LISTA_STRING_HEADER
#define LISTA_STRING_HEADER

#define TAM_MAX 100
struct elemento {
    char dado[TAM_MAX + 1];
    struct elemento * prox;
    struct elemento * ant;
};
 
struct descritor {
    struct elemento * inicio;
    struct elemento * final;
    int qtd;
};
 
typedef struct elemento Elem;
typedef struct descritor Lista;

#define SUCESSO 0
#define FALHA 1
#define INVALIDO -1

Lista * criaListaNumeros();
int tamanhoLista(Lista * lista);
int limpaLista(Lista * lista);
int verificaLista(Lista * lista);
int insereFinal(Lista * lista, char * elem);
int insereInicio(Lista * lista, char * elem);
int removeFinal(Lista * lista);
int removeInicio(Lista * lista);
int imprimeLista(Lista * lista);

#endif