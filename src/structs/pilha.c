//
// Created by francisco on 6/10/2025.
//
#include <stdlib.h>
#include "pilha.h"
#include <stdio.h>
#include <string.h>


pilha_acoes *criar_pilha() {
    pilha_acoes *pilha = (pilha_acoes *) malloc(sizeof(pilha_acoes));
    pilha->topo = -1;
    pilha->capacidade = CAPACIDADE_INICIAL_PILHA;
    return pilha;
}

void cadastrar_acao(pilha_acoes *pilha, char *descricao) {

    int topo = (*pilha).topo + 1;
    if ((*pilha).topo != (*pilha).capacidade) {
        strcpy((*pilha).acoes[topo], descricao);
        (*pilha).topo++;
    } else {
        printf("Pilha cheia!!");
        printf("Nao e possivel cadastrar mais operacoes.");
    }
}

void desfazer_acao(pilha_acoes **pilha) {
    if ((*pilha)->topo >= 0) {
        (*pilha)->topo--;
    } else {
        printf("Pilha vazia.\n");
        printf("Nehuma acao cadastrada.");
        return;
    }
    printf("Acao removida com sucesso.\n");
}

void salvar_pilha(FILE *arquivo, pilha_acoes pilha) {
    fwrite(&pilha.topo, sizeof(int), 1, arquivo);
    for (int i = 0; i <= pilha.topo; i++) {
        fwrite(pilha.acoes[i],TAMANHO_DA_STRING, 1, arquivo);
    }
}

pilha_acoes *leer_pilha(FILE *arquivo) {
    pilha_acoes *pilha = malloc(sizeof(pilha_acoes));
    fread(&pilha->topo, sizeof(int), 1, arquivo);
    for (int i = 0; i <= pilha->topo; i++) {
        fread(pilha->acoes[i],TAMANHO_DA_STRING, 1, arquivo);
    }
    return pilha;
}
