//
// Created by francisco on 6/13/2025.
//

#ifndef CARTAO_H
#define CARTAO_H
#include "pilha.h"
typedef struct cartao cartao_n;
void criar_cartao(cartao_n **cartao,char *nome,char *descricao,int prioridade);
void apagar_cartao(cartao_n **cartao);
void inserir_acoes(cartao_n **cartao,pilha_acoes **pilha);
#endif //CARTAO_H
