# include <stdio.h>
# include "lista_quick_sort.h"


int main () {
    Lista * lista_numeros = criar_lista_numeros();
    List * lista_textos = criar_lista_textos();
    int tam, num_of_elem = 25000;

    printf("Teste com %d numeros :\n", num_of_elem);
    generate_random_nums(num_of_elem, "random_nums");
    adicionar_numero_de_arquivo_para_lista("random_nums", lista_numeros);
    
    tam = tamanho_lista_numeros(lista_numeros);
    double tempo_total = 0.0;
    int trocas = 0;
    quick_sort_numeros_cres(lista_numeros, 0, tam - 1, &tempo_total, &trocas);

    printf("Resultado - Ordenacao crescente - %d numeros : \n", num_of_elem);
    printf("\033[34mTempo gasto = %.2lfs\n\033[0m", tempo_total);
    printf("\033[31mNum. de trocas = %d\n\n\033[0m", trocas);

    adicionar_numero_de_lista_para_arquivo(lista_numeros, "nums_cres");

    destruir_lista_numeros(lista_numeros);
    lista_numeros = criar_lista_numeros();

    tempo_total = 0.0;
    trocas = 0;
    adicionar_numero_de_arquivo_para_lista("random_nums", lista_numeros);
    quick_sort_numeros_decr(lista_numeros, 0, tam - 1, &tempo_total, &trocas);

    printf("Resultado - Ordenacao decrescente - %d numeros : \n", num_of_elem);
    printf("\033[34mTempo gasto = %.2lfs\n\033[0m", tempo_total);
    printf("\033[31mNum. de trocas = %d\n\033[0m", trocas);

    adicionar_numero_de_lista_para_arquivo(lista_numeros, "nums_decr");

    destruir_lista_numeros(lista_numeros);

    tempo_total = 0.0;
    trocas = 0;

    printf("Teste com %d palavras :\n", 1000000);
    adicionar_texto_de_arquivo_para_lista("nomes_aleatorios.txt", lista_textos);
    tam = tamanho_lista_textos(lista_textos);

    quick_sort_textos_a_z(lista_textos, 0, tam - 1, &tempo_total, &trocas);

    printf("Resultado - Ordenacao [A-Z] - %d palavras : \n", 1000000);
    printf("\033[34mTempo gasto = %.2lfs\n\033[0m", tempo_total);
    printf("\033[31mNum. de trocas = %d\n\033[0m", trocas);

    adicionar_texto_de_lista_para_arquivo(lista_textos, "names_az");

    destruir_lista_textos(lista_textos);

    lista_textos = criar_lista_textos();

    printf("Teste com %d palavras :\n", 1000000);
    adicionar_texto_de_arquivo_para_lista("nomes_aleatorios.txt", lista_textos);

    tempo_total = 0.0;
    trocas = 0;

    quick_sort_textos_z_a(lista_textos, 0, tam - 1, &tempo_total, &trocas);

    printf("Resultado - Ordenacao [Z-A] - %d palavras : \n", 1000000);
    printf("\033[34mTempo gasto = %.2lfs\n\033[0m", tempo_total);
    printf("\033[31mNum. de trocas = %d\n\033[0m", trocas);

    adicionar_texto_de_lista_para_arquivo(lista_textos, "names_za");

    destruir_lista_textos(lista_textos);
    return 0;
}