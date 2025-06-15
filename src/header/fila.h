//
// Created by francisco on 6/10/2025.
//
#include "cartao.h"
#ifndef FILA_H
#define FILA_H
#define CAPACIDADE_INICIAL_FILA 30
typedef struct fila fila_t;
fila_t *crear_fila();
void adicionar_na_fila(fila_t **fila,cartao_n **cartao);
cartao_n *proximo_da_fila(fila_t **fila);
#endif //FILA_H
