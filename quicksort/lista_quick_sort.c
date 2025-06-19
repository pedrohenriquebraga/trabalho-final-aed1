# include "lista_quick_sort.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

struct item_numero {
    int num;
    struct item_numero * prox, * anter;
};

struct item_texto {
    char * texto;
    struct item_texto * prox, * anter;
};

typedef struct item_numero Item;

typedef struct item_texto Elem;

struct lista_numeros {
    Item * prim, * ult, * atual;
    int size;
};

struct lista_textos {
    Elem * prim, * ult, * atual;
    int size;
};

Lista * criar_lista_numeros () {
    Lista * LISTA = (Lista*)malloc(sizeof(Lista));
    if (LISTA == NULL) {
        exit (1);
    }
    LISTA->size = 0;
    LISTA->prim = NULL;
    LISTA->ult = NULL;
    return LISTA;
}

List * criar_lista_textos () {
    List * LISTA = (List*)malloc(sizeof(Lista));
    if(LISTA == NULL) {
        exit(1);
    }
    LISTA->size = 0;
    LISTA->prim = NULL;
    LISTA->ult = NULL;
    return LISTA;
}

int adicionar_numero_indexado (Lista * LISTA, int num, int index) {
    if (LISTA == NULL) {
        return 0;
    }
    if (LISTA->size == 0) {
        Item * new_item = (Item*)malloc(sizeof(Item));
        if (new_item == NULL) {
            exit (1);
        }
        new_item->anter = NULL;
        new_item->num = num;
        new_item->prox = NULL;
        LISTA->prim = new_item;
        LISTA->atual = new_item;
        LISTA->ult = new_item;
        LISTA->size++;
    } else if (index == LISTA->size) {
        Item * new_item = (Item*)malloc(sizeof(Item));
        if (new_item == NULL) {
            exit (1);
        }
        new_item->num = num;
        new_item->anter = LISTA->ult;
        LISTA->ult->prox = new_item;
        new_item->prox = NULL;
        LISTA->ult = new_item;
        LISTA->size++; 
    } else if (index == 0) {
        Item * new_item = (Item*)malloc(sizeof(Item));
        if (new_item == NULL) {
            exit (1);
        }
        new_item->num = num;
        new_item->anter = NULL;
        new_item->prox = LISTA->prim;
        LISTA->prim->anter = new_item;
        LISTA->prim = new_item;
        LISTA->size++;
    } else if ((index > 0) && (index < LISTA->size)) {
        Item * new_item = (Item*)malloc(sizeof(Item)), *tmp;
        if (new_item == NULL) {
            exit (1);
        }
        new_item->num = num;
        int i;
        LISTA->atual = LISTA->prim;
        for (i = 0; i < index - 1; i++) {
            LISTA->atual = LISTA->atual->prox;
        }
        tmp = LISTA->atual->prox;
        new_item->anter = LISTA->atual;
        new_item->prox = tmp;
        LISTA->atual->prox = new_item;
        tmp->anter = new_item;
        LISTA->size++;
    } else {
        return 0;
    }
    return 1;
}

int adicionar_numero_inicio(Lista * LISTA, int num) {
   return adicionar_numero_indexado(LISTA, num,  0);
}

int adicionar_texto_posicao (List * LISTA, char * texto, int index) {
    if (LISTA == NULL) {
        return 0;
    }
    if (LISTA->size == 0) {
        Elem * new_item = (Elem*)malloc(sizeof(Elem));
        if (new_item == NULL) {
            exit (1);
        }
        new_item->texto = (char*)malloc(strlen(texto) * sizeof(char));
        strcpy(new_item->texto, texto);
        new_item->anter = NULL;
        new_item->prox = NULL;
        LISTA->prim = new_item;
        LISTA->atual = new_item;
        LISTA->ult = new_item;
        LISTA->size++;
    } else if (index == LISTA->size) {
        Elem * new_item = (Elem*)malloc(sizeof(Elem));
        if (new_item == NULL) {
            exit (1);
        }
        new_item->texto = (char*)malloc(strlen(texto) * sizeof(char));
        strcpy(new_item->texto, texto);
        new_item->anter = LISTA->ult;
        LISTA->ult->prox = new_item;
        new_item->prox = NULL;
        LISTA->ult = new_item;
        LISTA->size++; 
    } else if (index == 0) {
        Elem * new_item = (Elem*)malloc(sizeof(Elem));
        if (new_item == NULL) {
            exit (1);
        }
        new_item->texto = (char*)malloc(strlen(texto) * sizeof(char));
        strcpy(new_item->texto, texto);
        new_item->anter = NULL;
        new_item->prox = LISTA->prim;
        LISTA->prim->anter = new_item;
        LISTA->prim = new_item;
        LISTA->size++;
    } else if ((index > 0) && (index < LISTA->size)) {
        Elem * new_item = (Elem*)malloc(sizeof(Elem)), *tmp;
        if (new_item == NULL) {
            exit (1);
        }
        new_item->texto = (char*)malloc(strlen(texto) * sizeof(char));
        strcpy(new_item->texto, texto);
        int i;
        LISTA->atual = LISTA->prim;
        for (i = 0; i < index - 1; i++) {
            LISTA->atual = LISTA->atual->prox;
        }
        tmp = LISTA->atual->prox;
        new_item->anter = LISTA->atual;
        new_item->prox = tmp;
        LISTA->atual->prox = new_item;
        tmp->anter = new_item;
        LISTA->size++;
    } else {
        return 0;
    }
    return 1;
}

int adicionar_numero_final(Lista * LISTA, int num) {
    return adicionar_numero_indexado(LISTA, num, LISTA->size);
}

int adicionar_texto_inicio (List * LISTA, char * texto) {
    adicionar_texto_posicao(LISTA, texto, 0);
}

int adicionar_texto_final (List * LISTA, char * texto) {
    if(LISTA == NULL)
    {
        return 0;
    }
    Elem * no = (Elem*)malloc(sizeof(Elem));
    no->texto = (char*)malloc(strlen(texto) * sizeof(char));
    no->prox = NULL;
    strcpy(no->texto, texto);
    no->anter = LISTA->ult;
    LISTA->ult = no;
    LISTA->ult->prox = no;
    return 1;
}

Item * consultar_elemento_num_indexado (Lista * LISTA, int index) {
    if (LISTA == NULL) {
        return 0;
    }
    int i;
    if (index <= (LISTA->size / 2)) {
        LISTA->atual = LISTA->prim;
        for (i = 0; i < LISTA->size; i++) {
            if (i == index) {
                return LISTA->atual;
            }
            LISTA->atual = LISTA->atual->prox;
        }
    } else {
        LISTA->atual = LISTA->ult;
        for (i = LISTA->size - 1; i >= 0; i--) {
            if (i == index) {
                return LISTA->atual;
            }
            LISTA->atual = LISTA->atual->anter;
        }
    }
    return 0;
}

Elem * consultar_primeiro_elemento_texto (List * LISTA) {
    if(LISTA == NULL) {
        exit(1);
    }
    if(LISTA->prim == NULL) {
        exit(1);
    }
    else return LISTA->prim;
}

Elem * consultar_elemento_texto_posicao (List * LISTA, int index) {
    if (LISTA == NULL) {
        return 0;
    }
    int i;
    if (index <= (LISTA->size / 2)) {
        LISTA->atual = LISTA->prim;
        for (i = 0; i < LISTA->size; i++) {
            if (i == index) {
                return LISTA->atual;
            }
            LISTA->atual = LISTA->atual->prox;
        }
    } else {
        LISTA->atual = LISTA->ult;
        for (i = LISTA->size - 1; i >= 0; i--) {
            if (i == index) {
                return LISTA->atual;
            }
            LISTA->atual = LISTA->atual->anter;
        }
    }
    return 0;
}

int consultar_valor_num_indexado (Lista * LISTA, int index) {
    if (LISTA == NULL) {
        return 0;
    }
    int i;
    if (index <= (LISTA->size / 2)) {
        LISTA->atual = LISTA->prim;
        for (i = 0; i < LISTA->size; i++) {
            if (i == index) {
                return LISTA->atual->num;
            }
            LISTA->atual = LISTA->atual->prox;
        }
    } else {
        LISTA->atual = LISTA->ult;
        for (i = LISTA->size - 1; i >= 0; i--) {
            if (i == index) {
                return LISTA->atual->num;
            }
            LISTA->atual = LISTA->atual->anter;
        }
    }
    return 0;
}

char * consultar_conteudo_primeiro_texto (List * LISTA) {
    if(LISTA == NULL) {
        exit(1);
    }
    if(LISTA->prim == NULL) {
        exit(1);
    }
    else return LISTA->prim->texto;
}

char * consultar_conteudo_texto_posicao (List * LISTA, int pos) {
    if(LISTA == NULL) {
        exit(1);
    }
    if(pos > LISTA->size) {
        exit(1);
    }
    Elem * no = LISTA->prim;
    for(int i=0;i<pos;i++)
    {
        no = no->prox;
    }
    return no->texto;
}

int verificar_texto_na_lista (List * LISTA, char * text) {
    if (LISTA == NULL) {
        return 0;
    }
    Elem * no = LISTA->prim;
    for(int i=0;i<LISTA->size;i++) {
        if(strcasecmp(text, no->texto) == 0) return 1;
        no = no->prox;
    }
    return 0;
}


int remover_index_especifico (Lista * LISTA, int index) {
    if (LISTA == NULL) {
        return 0;
    }
    if (LISTA->size == 1) {
        free(LISTA->atual);
        LISTA->size--;
    } else if (index == 0) {
        Item * tmp = LISTA->prim->prox;
        free(LISTA->prim);
        LISTA->prim = tmp;
        LISTA->atual = LISTA->prim;
        LISTA->size--;
    } else if ((index > 0) && (index < LISTA->size)) {
        int i;
        LISTA->atual = LISTA->prim;
        for (i = 0; i < index - 1; i++) {
            LISTA->atual = LISTA->atual->prox;
        }
        Item * tmp = LISTA->atual->prox;
        LISTA->atual->prox = tmp->prox;
        tmp->prox->anter = LISTA->atual;
        free(tmp);
        LISTA->size--;
    } else if (index == LISTA->size - 1) {
        Item * tmp = LISTA->ult->anter;
        free(LISTA->ult);
        LISTA->ult = tmp;
        LISTA->size--;
    } else {
        return 0;
    }
    return 1;
}

int remover_inicio_numeros (Lista * LISTA) {
    return remover_index_especifico(LISTA, 0);
}

int remover_final_numeros (Lista * LISTA) {
    return remover_index_especifico(LISTA, LISTA->size - 1);
}

int remover_texto_especifico (List * LISTA, char * text) {
    if (LISTA == NULL) {
        return 0;
    }
    Elem * no = LISTA->prim;
    if (LISTA->size == 1) {
        if (strcasecmp(text, LISTA->prim->texto) == 0) {
            remover_inicio_textos(LISTA);
            return 1;
        }
    } else for(int i=0;i<LISTA->size;i++) {
        if(strcasecmp(no->texto, text) == 0) {
            Elem * temp = no->anter;
            temp->prox = no->prox;
            temp->prox->anter = temp;
            free(no);
            LISTA->size--;
            return 1;
        }
    }

    return 0;
}

int remover_inicio_textos (List * LISTA) {
    if (LISTA == NULL) {
        return 0;
    }
    if (LISTA->size == 1) {
        free(LISTA->prim);
        LISTA->size--;
    }
    else {
        Elem * no = LISTA->prim;
        LISTA->prim = LISTA->prim->prox;
        LISTA->prim->anter = NULL;
        free(no);
        LISTA->size--;
    }
    return 1;
}

int remover_final_textos (List * LISTA) {
    if (LISTA == NULL) {
        return 0;
    }
    if (LISTA->size == 1) {
        free(LISTA->prim);
        LISTA->size--;
    }
    else {
        Elem * no = LISTA->ult;
        LISTA->ult = LISTA->ult->anter;
        LISTA->ult->prox = NULL;
        free(no);
        LISTA->size--;
    }
    return 1;
}

int destruir_lista_numeros (Lista * LISTA) {
    if (LISTA == NULL) {
        return 0;
    }
    while (LISTA->size != 0) {
        remover_inicio_numeros(LISTA);
    }
    free(LISTA);
    return 1;
}

int destruir_lista_textos (List * LISTA) {
    if (LISTA == NULL) {
        return 0;
    }
    while (LISTA->size != 0) {
        remover_inicio_textos(LISTA);
    }
    free(LISTA);
    return 1;
}

int adicionar_numero_de_arquivo_para_lista (char * file_name, Lista * LISTA) {
    if (LISTA == NULL) {
        return 0;
    }
    int i, num;
    FILE * arq = fopen(file_name, "r");
    if (arq == NULL) return 0;
    while (fscanf(arq, "%d", &num) == 1) {
        adicionar_numero_inicio(LISTA, num);
    }
    fclose(arq);
    return 1;
}

int adicionar_texto_de_arquivo_para_lista (char * file_name, List * LISTA) {
    char line_str[256]; 
    FILE * arq = fopen(file_name, "r");
    if (arq == NULL) {
        return 0;
    }
    while (fscanf(arq, "%s", line_str) == 1) {
        adicionar_texto_inicio(LISTA, line_str);
    }
    fclose(arq);
    return 1;
}

int adicionar_numero_de_lista_para_arquivo (Lista * LISTA, char * file_name) {
    if (LISTA == NULL) {
        return 0;
    }
    FILE * arq = fopen(file_name, "w");
    if (arq == NULL) {
        return 0;
    }
    int i;
    LISTA->atual = LISTA->prim;
    for (i = 0; i < LISTA->size; i++) {
        fprintf(arq, "%d\n", LISTA->atual->num);
        LISTA->atual = LISTA->atual->prox;
    }
    fclose(arq);
    return 1;
}

int generate_random_nums (unsigned long long int num_of_nums, char * name) {
    srand(5);
    int k = 0, signal;
    FILE * arq = fopen(name, "w");
    for (k = 0; k < num_of_nums; k++) {
        signal = rand() % 2;
        if (signal == 0) signal = -1;
        if (signal == 1) signal = 1;
        fprintf(arq, "%d\n", signal * (rand() % 10000));
    }
    fclose(arq);
    return 1;
}

int adicionar_texto_de_lista_para_arquivo (List * LISTA, char * file_name) {
    if (LISTA == NULL) {
        return 0;
    }
    FILE * arq = fopen(file_name, "w");
    int i;
    Elem * no = LISTA->prim;
    for (i = 0; i < LISTA->size; i++) {
        fprintf(arq, "%s\n", no->texto);
        no = no->prox;
    }
    fclose(arq);
    return 1;
}

int imprime_lista_numeros(Lista * LISTA) {
    if(LISTA == NULL) {
        return 0;
    }
    Item * no = LISTA->prim;
    for(int i=0;i<LISTA->size;i++) {
        printf("%d\n", no->num);
        no = no->prox;
    }
    return 1;
}

int imprime_lista_textos(List * LISTA) {
    if(LISTA == NULL) {
        return 0;
    }
    Elem * no = LISTA->prim;
    for(int i=0;i<LISTA->size;i++) {
        printf("%s\n", no->texto);
        no = no->prox;
    }
    return 1;
}

int tamanho_lista_numeros(Lista * LISTA) {
    if(LISTA == NULL)
    {
        return 0;
    }
    return LISTA->size;
}

int tamanho_lista_textos(List * LISTA) {
    if(LISTA == NULL)
    {
        return 0;
    }
    return LISTA->size;
}

int trocaElementosStr(List * LISTA, Elem * elem1, Elem * elem2) {
    if(LISTA == NULL) {
        return 0;
   }

    if (elem1 == NULL || elem2 == NULL || elem1 == elem2)
    {
        return 0;
    }

   Elem *ant1 = elem1->anter;
   Elem *prox1 = elem1->prox;
   Elem *ant2 = elem2->anter;
   Elem *prox2 = elem2->prox;

   if (prox1 == elem2)
   {
      elem1->prox = prox2;
      elem1->anter = elem2;
      elem2->prox = elem1;
      elem2->anter = ant1;

      if (ant1 != NULL)
      {
         ant1->prox = elem2;
      }
      if (prox2 != NULL)
      {
         prox2->anter = elem1;
      }
   }
   else if (prox2 == elem1)
   {
      elem2->prox = prox1;
      elem2->anter = elem1;
      elem1->prox = elem2;
      elem1->anter = ant2;

      if (ant2 != NULL)
      {
         ant2->prox = elem1;
      }
      if (prox1 != NULL)
      {
         prox1->anter = elem2;
      }
   }
   else
   {
      elem1->prox = prox2;
      elem1->anter = ant2;
      elem2->prox = prox1;
      elem2->anter = ant1;

      if (ant1 != NULL)
      {
         ant1->prox = elem2;
      }
      if (prox1 != NULL)
      {
         prox1->anter = elem2;
      }
      if (ant2 != NULL)
      {
         ant2->prox = elem1;
      }
      if (prox2 != NULL)
      {
         prox2->anter = elem1;
      }
   }

   if (LISTA->prim == elem1)
   {
      LISTA->prim = elem2;
   }
   else if (LISTA->prim == elem2)
   {
      LISTA->prim = elem1;
   }

   if (LISTA->ult == elem1)
   {
      LISTA->ult = elem2;
   }
   else if (LISTA->ult == elem2)
   {
      LISTA->ult = elem1;
   }

   return 1;
}

int trocaElementosNum(Lista * LISTA, Item * elem1, Item * elem2) {
    if(LISTA == NULL) {
        return 0;
    }

   if (elem1 == NULL || elem2 == NULL || elem1 == elem2)
   {
      return 0;
   }

   Item *ant1 = elem1->anter;
   Item *prox1 = elem1->prox;
   Item *ant2 = elem2->anter;
   Item *prox2 = elem2->prox;

   if (prox1 == elem2)
   {
      elem1->prox = prox2;
      elem1->anter = elem2;
      elem2->prox = elem1;
      elem2->anter = ant1;

      if (ant1 != NULL)
      {
         ant1->prox = elem2;
      }
      if (prox2 != NULL)
      {
         prox2->anter = elem1;
      }
   }
   else if (prox2 == elem1)
   {
      elem2->prox = prox1;
      elem2->anter = elem1;
      elem1->prox = elem2;
      elem1->anter = ant2;

      if (ant2 != NULL)
      {
         ant2->prox = elem1;
      }
      if (prox1 != NULL)
      {
         prox1->anter = elem2;
      }
   }
   else
   {
      elem1->prox = prox2;
      elem1->anter = ant2;
      elem2->prox = prox1;
      elem2->anter = ant1;

      if (ant1 != NULL)
      {
         ant1->prox = elem2;
      }
      if (prox1 != NULL)
      {
         prox1->anter = elem2;
      }
      if (ant2 != NULL)
      {
         ant2->prox = elem1;
      }
      if (prox2 != NULL)
      {
         prox2->anter = elem1;
      }
   }

   if (LISTA->prim == elem1)
   {
      LISTA->prim = elem2;
   }
   else if (LISTA->prim == elem2)
   {
      LISTA->prim = elem1;
   }

   if (LISTA->ult == elem1)
   {
      LISTA->ult = elem2;
   }
   else if (LISTA->ult == elem2)
   {
      LISTA->ult = elem1;
   }

   return 1;
}

int ListaNumsOrdenada (Lista * LISTA, int tam) {
    if(LISTA == NULL)
    {
        return 0;
    }
    Item * no = LISTA->prim;
    for(int i=0;i<tam;i++)
    {
        if(no->num > no->prox->num)
        {
            return 0;
        }
        no = no->prox;
    }
    return 1;
}

int ListaTextoOrdenada (List * LISTA, int tam) {
    if(LISTA == NULL)
    {
        return 0;
    }
    Elem * no = LISTA->prim;
    for(int i=0;i<tam;i++)
    {
        if(strcasecmp(no->texto, no->prox->texto) > 0)
        {
            return 0;
        }
    }
    return 1;
}

void quick_sort_numeros_cres (Lista * LISTA, int inicio, int fim, double * tempo_total, int * n_trocas) {
    if (inicio < fim) {
        clock_t t_inicio, t_final;
        t_inicio = clock();
        Item * pivo = consultar_elemento_num_indexado(LISTA, fim);
        int i = inicio - 1, j;
        LISTA->atual = consultar_elemento_num_indexado(LISTA, inicio);
        for (j = inicio; j <= fim - 1; j++) {
            if (LISTA->atual->num <= pivo->num) {
                (*n_trocas)++;
                i++;
                trocaElementosNum(LISTA, consultar_elemento_num_indexado(LISTA, i), LISTA->atual);
            }
            LISTA->atual = LISTA->atual->prox;
        }
        trocaElementosNum(LISTA, consultar_elemento_num_indexado(LISTA, i + 1), pivo);
        int partition_index = i + 1;
        (*n_trocas)++;
        t_final = clock();
        double tempo_gasto = (double) (t_final - t_inicio) / CLOCKS_PER_SEC;
        (*tempo_total) = (*tempo_total) + tempo_gasto;
        quick_sort_numeros_cres(LISTA, inicio, partition_index - 1, tempo_total, n_trocas);
        quick_sort_numeros_cres(LISTA, partition_index + 1, fim, tempo_total, n_trocas);
    }
}

void quick_sort_numeros_decr (Lista * LISTA, int inicio, int fim, double * tempo_total, int * n_trocas) {
    if (inicio < fim) {
        clock_t t_inicio, t_final;
        t_inicio = clock();
        Item * pivo = consultar_elemento_num_indexado(LISTA, fim);
        int i = inicio - 1, j;
        LISTA->atual = consultar_elemento_num_indexado(LISTA, inicio);
        for (j = inicio; j <= fim - 1; j++) {
            if (LISTA->atual->num >= pivo->num) {
                (*n_trocas)++;
                i++;
                trocaElementosNum(LISTA, consultar_elemento_num_indexado(LISTA, i), LISTA->atual);
            }
            LISTA->atual = LISTA->atual->prox;
        }
        trocaElementosNum(LISTA, consultar_elemento_num_indexado(LISTA, i + 1), pivo);
        int partition_index = i + 1;
        (*n_trocas)++;
        t_final = clock();
        double tempo_gasto = (double) (t_final - t_inicio) / CLOCKS_PER_SEC;
        (*tempo_total) = (*tempo_total) + tempo_gasto;
        quick_sort_numeros_decr(LISTA, inicio, partition_index - 1, tempo_total, n_trocas);
        quick_sort_numeros_decr(LISTA, partition_index + 1, fim, tempo_total, n_trocas);
    }
}

void quick_sort_textos_a_z (List * LISTA, int inicio, int fim, double * tempo_total, int * n_trocas) {
    if (inicio < fim) {
        clock_t t_inicio, t_final;
        t_inicio = clock();
        Elem * pivo = consultar_elemento_texto_posicao(LISTA, fim);
        int i = inicio - 1, j;
        LISTA->atual = consultar_elemento_texto_posicao(LISTA, inicio);
        for (j = inicio; j <= fim - 1; j++) {
            if (strcasecmp(LISTA->atual->texto, pivo->texto) <= 0) {
                (*n_trocas)++;
                i++;
                trocaElementosStr(LISTA, consultar_elemento_texto_posicao(LISTA, i), LISTA->atual);
            }
            LISTA->atual = LISTA->atual->prox;
        }
        trocaElementosStr(LISTA, consultar_elemento_texto_posicao(LISTA, i + 1), pivo);
        (*n_trocas)++;
        int partition_index = i + 1;
        t_final = clock();
        double tempo_gasto = (double) (t_final - t_inicio) / CLOCKS_PER_SEC;
        (*tempo_total) = (*tempo_total) + tempo_gasto;
        quick_sort_textos_a_z(LISTA, inicio, partition_index - 1, tempo_total, n_trocas);
        quick_sort_textos_a_z(LISTA, partition_index + 1, fim, tempo_total, n_trocas);
    }
}

void quick_sort_textos_z_a (List * LISTA, int inicio, int fim, double * tempo_total, int * n_trocas) {
    if (inicio < fim) {
        clock_t t_inicio, t_final;
        t_inicio = clock();
        Elem * pivo = consultar_elemento_texto_posicao(LISTA, fim);
        int i = inicio - 1, j;
        LISTA->atual = consultar_elemento_texto_posicao(LISTA, inicio);
        for (j = inicio; j <= fim - 1; j++) {
            if (strcasecmp(LISTA->atual->texto, pivo->texto) >= 0) {
                (*n_trocas)++;
                i++;
                trocaElementosStr(LISTA, consultar_elemento_texto_posicao(LISTA, i), LISTA->atual);
            }
            LISTA->atual = LISTA->atual->prox;
        }
        trocaElementosStr(LISTA, consultar_elemento_texto_posicao(LISTA, i + 1), pivo);
        (*n_trocas)++;
        int partition_index = i + 1;
        t_final = clock();
        double tempo_gasto = (double) (t_final - t_inicio) / CLOCKS_PER_SEC;
        (*tempo_total) = (*tempo_total) + tempo_gasto;
        quick_sort_textos_z_a(LISTA, inicio, partition_index - 1, tempo_total, n_trocas);
        quick_sort_textos_z_a(LISTA, partition_index + 1, fim, tempo_total, n_trocas);
    }
}