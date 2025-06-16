#define N 1000000

typedef struct elemento Lista;

void *criaLista();
void imprimeLista(Lista * lista);
void insereInicio(Lista * lista, int num);
void insereFinal(Lista * lista, int num);
void removeInicio(Lista * lista);
void removeFinal(Lista * lista);
void destroiLista(Lista * lista);
int SelectionSortCresc(Lista * lista);
int SelectionSortDescres(Lista * lista);

void geraListaNumerosEmSequencia(int qnt_elementos);
void geraListaNumerosAleatorios(int qnt_elementos);