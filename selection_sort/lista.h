#ifndef LISTA_HEADER
#define LISTA_HEADER

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
typedef struct descritor Lista;

#define SUCESSO 0
#define FALHA 1
#define INVALIDO -1

Lista * criaLista();
int tamanhoLista(Lista * lista);
int limpaLista(Lista * lista);
int verificaLista(Lista * lista);
int insereFinal(Lista * lista, int elem);
int insereInicio(Lista * lista, int elem);
int removeFinal(Lista * lista);
int removeInicio(Lista * lista);
int imprimeLista(Lista * lista);

#endif