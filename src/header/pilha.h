//
// Created by francisco on 6/15/2025.
//

#ifndef PILHA_H
#define PILHA_H

#define CAPACIDADE_INICIAL_PILHA 20

#define TAMANHO_DA_STRING 200
#include <stdio.h>

typedef struct pilha {
    int topo;
    char acoes[CAPACIDADE_INICIAL_PILHA][TAMANHO_DA_STRING];
    int capacidade;
} pilha_acoes;

pilha_acoes *criar_pilha();

void cadastrar_acao(pilha_acoes *pilha, char *descricao);

void desfazer_acao(pilha_acoes **pilha);

void salvar_pilha(FILE *arquivo, pilha_acoes pilha);

pilha_acoes *leer_pilha(FILE *arquivo);
#endif //PILHA_H
