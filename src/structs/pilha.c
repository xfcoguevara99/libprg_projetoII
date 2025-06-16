//
// Created by francisco on 6/10/2025.
//
#include <stdlib.h>
#include "pilha.h"
#include <stdio.h>
#include <string.h>

typedef struct pilha {
    char acoes[CAPACIDADE_INICIAL_PILHA][200];
    int topo;
    int capacidade;
} pilha_acoes;

pilha_acoes *criar_pilha() {
    pilha_acoes *pilha = (pilha_acoes*)malloc(sizeof(pilha_acoes));
    pilha->topo = -1;
    pilha->capacidade = CAPACIDADE_INICIAL_PILHA;
}

void cadastrar_acao(pilha_acoes **pilha, char *descricao) {
    int topo = (*pilha)->topo + 1;
    if ((*pilha)->topo != (*pilha)->capacidade) {
        strcpy((*pilha)->acoes[topo], descricao);
        (*pilha)->topo++;
    } else {
        printf("Pilha cheia!!");
        printf("Nao e possivel cadastrar mais operacoes.");
    }
}

void desfazer_acao(pilha_acoes **pilha) {
    if ((*pilha)->topo >= 0) {
        (*pilha)->topo--;
    } else {
        printf("Pilha vazia.");
        printf("Nehuma acao cadastrada.");
    }
}


