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
}fila_t;

fila_t *crear_fila() {
    // Criar a estrutura fila e aloca memória
    fila_t *fila = (fila_t*)malloc(sizeof(fila_t));
    // Alocar memória para os elementos da fila
    fila->cartoes = (fila_t *) malloc(sizeof(fila_t) * CAPACIDADE_INICIAL);
    // Definir os valores iniciais da fila
    fila->head= 0;
    fila->tail = 0;
    fila->capacidade = CAPACIDADE_INICIAL;
    fila->tamanho= 0;
    return fila;
}
void adicionar_na_fila(fila_t **fila,int value) {
    if ((*fila)-> tamanho == (*fila)->capacidade) {
        printf("Erro: Fila cheia (overflow)");
        exit(EXIT_FAILURE);
    }
    (*fila)->cartoes[(*fila)->tail] = value;
    (*fila)->tail++;
    (*fila)->tamanho++;
}
