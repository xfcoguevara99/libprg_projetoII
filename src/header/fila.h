//
// Created by francisco on 6/10/2025.
//

#ifndef FILA_H
#define FILA_H
#define CAPACIDADE_INICIAL 30
typedef struct fila fila_t;
fila_t *crear_fila();
void adicionar_na_fila(fila_t **fila,int value);
#endif //FILA_H
