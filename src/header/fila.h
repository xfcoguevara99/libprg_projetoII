//
// Created by francisco on 6/10/2025.
//
#include "cartao.h"
#ifndef FILA_H
#define FILA_H
#define CAPACIDADE_INICIAL_FILA 40
typedef struct fila {
    int tamanho;
    int head;
    int tail;
    cartao_n *cartoes[CAPACIDADE_INICIAL_FILA];
    int capacidade;
}fila_t;

fila_t *criar_fila();

void adicionar_na_fila(fila_t **fila, cartao_n *cartao);

cartao_n *proximo_da_fila(fila_t **fila);

void salvar_fila(fila_t *fila);

fila_t *ler_fila_atendimento();
#endif //FILA_H
