//
// Created by francisco on 6/13/2025.
//

#include "cartao.h"
#include <stdlib.h>
#include "pilha.h"
#include <string.h>

typedef struct cartao {
    char nome[32];
    char descripcao_problema[512];
    int prioridade;
    pilha_acoes *acoes;
} cartao_n;

cartao_n criar_cartao(char nome[],char descricao[],int prioridade) {
    cartao_n cartao;
    strcpy(cartao.nome,nome);
    strcpy(cartao.descripcao_problema,descricao);
    cartao.prioridade = prioridade;
    return cartao;
}


