#include <stdio.h>

typedef struct lista_numeros Lista;
typedef struct lista_textos List;

typedef struct item_numero Item;
typedef struct item_texto Elem;

Lista * criar_lista_numeros ();

List * criar_lista_textos ();

int destruir_lista_numeros (Lista * LISTA);

int destruir_lista_textos (List * LISTA);

int adicionar_numero_indexado (Lista * LISTA, int num, int index);

int adicionar_numero_inicio (Lista * LISTA, int num);

int adicionar_numero_final (Lista * LISTA, int num);

int remover_index_especifico (Lista * LISTA, int index);

int remover_inicio_numeros (Lista * LISTA);

int remover_final_numeros (Lista * LISTA);

int remover_texto_especifico(List * LISTA, char * text);

int remover_inicio_textos (List * LISTA);

int remover_final_textos (List * LISTA);

Item * consultar_elemento_num_indexado (Lista * LISTA, int index);

Elem * consultar_primeiro_elemento_texto (List * LISTA);

Elem * consultar_elemento_texto_posicao (List * LISTA, int pos);

int consultar_valor_num_indexado (Lista * LISTA, int index);

char * consultar_conteudo_texto_posicao (List * LISTA, int pos);

char * consultar_conteudo_primeiro_texto (List * LISTA);

int verificar_texto_na_lista (List * LISTA, char * text);

int adicionar_numero_de_arquivo_para_lista (char * file_name, Lista * LISTA);

int adicionar_texto_de_arquivo_para_lista (char * file_name, List * LISTA);

// O arquivo devera conter um numero/texto por linha.

int generate_random_nums (unsigned long long int num_of_nums, char * name);

int adicionar_numero_de_lista_para_arquivo (Lista * LISTA, char * file_name);

int adicionar_texto_de_lista_para_arquivo (List * LISTA, char * file_name);

int imprime_lista_numeros(Lista * LISTA);

int imprime_lista_textos(List * LISTA);

int tamanho_lista_numeros(Lista * LISTA);

int tamanho_lista_textos(List * LISTA);

int trocaElementosStr(List * LISTA, Elem * elem1, Elem * elem2);

int trocaElementosNum(Lista * LISTA, Item * elem1, Item * elem2);

int ListaNumsOrdenada (Lista * LISTA, int tam);

int ListaTextoOrdenada (List * LISTA, int tam);

void quick_sort_numeros_cres (Lista * LISTA, int inicio, int fim, double * tempo_total, int * n_trocas);

void quick_sort_numeros_decr (Lista * LISTA, int inicio, int fim, double * tempo_total, int * n_trocas);

void quick_sort_textos_a_z (List * LISTA, int inicio, int fim, double * tempo_total, int * n_trocas);

void quick_sort_textos_z_a (List * LISTA, int inicio, int fim, double * tempo_total, int * n_trocas);