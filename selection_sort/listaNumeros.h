#ifndef LISTA_NUMEROS_HEADER
#define LISTA_NUMEROS_HEADER

struct elementoNum {
    int dado;
    struct elementoNum * prox;
    struct elementoNum * ant;
};
 
struct descritorNum {
    struct elementoNum * inicio;
    struct elementoNum * final;
    int qtd;
};
 
typedef struct elementoNum ElemNum;
typedef struct descritorNum ListaNumeros;

#define SUCESSO 0
#define FALHA 1
#define INVALIDO -1

ListaNumeros * criaListaNumeros();
int tamanhoListaNum(ListaNumeros * lista);
int limpaListaNum(ListaNumeros * lista);
int verificaListaNum(ListaNumeros * lista);
int insereNumFinal(ListaNumeros * lista, int elem);
int insereNumInicio(ListaNumeros * lista, int elem);
int removeNumFinal(ListaNumeros * lista);
int removeNumInicio(ListaNumeros * lista);
int imprimeListaNum(ListaNumeros * lista);

#endif