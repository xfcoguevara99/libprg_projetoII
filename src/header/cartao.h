//
// Created by francisco on 6/13/2025.
//
#include <stdio.h>

#include "pilha.h"
#ifndef CARTAO_H
#define CARTAO_H

typedef struct cartao {
    char nome[32];
    char descripcao_problema[512];
    int prioridade;
    pilha_acoes acoes;
} cartao_n;

cartao_n *criar_cartao(char *nome, char *descricao, int prioridade);

cartao_n *ler_cartao(FILE *arquivo);
void salvar_cartao(FILE *arquivo,cartao_n *cartao);


#endif //CARTAO_H
