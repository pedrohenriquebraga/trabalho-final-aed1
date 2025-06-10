typedef struct descritor Lista;

#define SUCESSO 0
#define FALHA 1
#define INVALIDO -1

Lista * criaLista();
int selectionSort(Lista * lista);
int tamanhoLista(Lista * lista);
int limpaLista(Lista * lista);
int verificaLista(Lista * lista);
int insereFinal(Lista * lista, int elem);
int insereInicio(Lista * lista, int elem);
int removeFinal(Lista * lista);
int removeInicio(Lista * lista);
int imprimeLista(Lista * lista);