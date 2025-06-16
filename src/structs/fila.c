//
// Created by francisco on 6/10/2025.
//
#include <stdio.h>
#include "fila.h"
#include <stdlib.h>
#include "cartao.h"

typedef struct fila {
    cartao_n **cartoes;
    int head;
    int tail;
    int capacidade;
    int tamanho;
} fila_t;

fila_t *criar_fila() {
    // Criar a estrutura fila e aloca memória
    fila_t *fila = (fila_t *) malloc(sizeof(fila_t));
    // Alocar memória para os elementos da fila
    fila->cartoes = malloc(sizeof(cartao_n *) * CAPACIDADE_INICIAL_FILA);
    // Definir os valores iniciais da fila
    fila->head = 0;
    fila->tail = 0;
    fila->capacidade = CAPACIDADE_INICIAL_FILA;
    fila->tamanho = 0;
    return fila;
}

void adicionar_na_fila(fila_t **fila, cartao_n **cartao) {
    if ((*fila)->tamanho == (*fila)->capacidade) {
        printf("Erro: Fila cheia (overflow)");
        exit(EXIT_FAILURE);
    }
    if ((*fila)->cartoes[(*fila)->tail] != NULL) {
        (*fila)->cartoes[(*fila)->tail] = *cartao;
        (*fila)->tail++;
        (*fila)->tamanho++;
    }
}

cartao_n *proximo_da_fila(fila_t **fila) {
    if ((*fila)->tamanho == 0) {
        printf("Error: fila vazia");
        exit(EXIT_FAILURE);
    }
    cartao_n *proximo_cartao = (*fila)->cartoes[(*fila)->head];
    (*fila)->cartoes[(*fila)->head] = NULL;
    (*fila)->head++;
    (*fila)->tamanho--;
    return proximo_cartao;
}
