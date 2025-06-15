//
// Created by francisco on 6/10/2025.
//
#include <stdlib.h>
#include "pilha.h"

typedef struct pilha {
    char **acoes;
    int topo;
    int capacidade;

}pilha_acoes;

pilha_acoes *criar_pilha() {
    pilha_acoes *pilha = malloc(sizeof(pilha_acoes));
    pilha->acoes = malloc(sizeof(char*)*CAPACIDADE_INICIAL_PILHA);
    for (int i = 0; i < CAPACIDADE_INICIAL_PILHA ; i++) {
        pilha->acoes[i] = malloc(sizeof(char)*TAMANHO_DA_STRING);
    }
    pilha->topo = -1;
    pilha->capacidade = CAPACIDADE_INICIAL_PILHA;
    return pilha;
}
