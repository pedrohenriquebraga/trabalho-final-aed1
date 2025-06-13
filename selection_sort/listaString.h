#ifndef LISTA_STRING_HEADER
#define LISTA_STRING_HEADER

#define TAM_MAX 100
struct elementoStr {
    char dado[TAM_MAX + 1];
    struct elementoStr * prox;
    struct elementoStr * ant;
};
 
struct descritorStr {
    struct elementoStr * inicio;
    struct elementoStr * final;
    int qtd;
};
 
typedef struct elementoStr ElemStr;
typedef struct descritorStr ListaStrings;

#define SUCESSO 0
#define FALHA 1
#define INVALIDO -1

ListaStrings * criaListaStrings();
int tamanhoListaStr(ListaStrings * lista);
int limpaListaStr(ListaStrings * lista);
int verificaListaStr(ListaStrings * lista);
int insereStrFinal(ListaStrings * lista, char * elem);
int insereStrInicio(ListaStrings * lista, char * elem);
int removeStrFinal(ListaStrings * lista);
int removeStrInicio(ListaStrings * lista);
int imprimeListaStr(ListaStrings * lista);

#endif