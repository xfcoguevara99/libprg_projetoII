//
// Created by francisco on 6/13/2025.
//

#include "cartao.h"

#include <stdlib.h>
#include "pilha.h"
typedef struct cartao{
    char *nome;
    char *descripcao_problema;
    int prioridade;
    pilha_acoes *pilha_acoes;
    int ordem;
}cartao_n;

void criar_cartao(cartao_n **cartao,char *nome,char *descricao,int prioridade) {
    *cartao = (cartao_n*)malloc(sizeof(cartao_n));
    (*cartao)->nome = nome;
    (*cartao)->descripcao_problema = descricao;
    (*cartao)->prioridade = prioridade;
    (*cartao)->ordem = 0;
}
void apagar_cartao(cartao_n **cartao) {
    free((*cartao)->pilha_acoes);
    free(*cartao);
    *cartao = NULL;
}

void inserir_acoes(cartao_n **cartao,pilha_acoes **pilha) {
    (*cartao)->pilha_acoes = *pilha;
}
