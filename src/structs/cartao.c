//
// Created by francisco on 6/13/2025.
//

#include "cartao.h"

#include <stdlib.h>

typedef struct cartao{
    char *nome;
    char *descripcao_problema;
    int prioridade=0;
    char **pilha_acoes;
    int ordem;
}cartao_n;

void criar_cartao(cartao_n **cartao,char *nome,char *descricao,int prioridade) {
    *cartao = (cartao_n*)malloc(sizeof(cartao_n));
    (*cartao)->nome = nome;
    (*cartao)->descripcao_problema = descricao;
    (*cartao)->prioridade = prioridade;
    (*cartao)->ordem = 0;
}
