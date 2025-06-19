//
// Created by francisco on 6/13/2025.
//

#include "cartao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criar_cartao(cartao_n *cartao,char *nome, char *descricao, int prioridade) {
    //cartao_n *cartao = malloc(sizeof(cartao_n));
    strcpy(cartao->nome, nome);
    strcpy(cartao->descripcao_problema, descricao);
    cartao->prioridade = prioridade;
}

void salvar_cartao(FILE *arquivo, cartao_n *cartao) {
    fwrite(cartao->nome, sizeof(cartao->nome), 1, arquivo);
    fwrite(cartao->descripcao_problema, sizeof(cartao->descripcao_problema), 1, arquivo);
    fwrite(&cartao->prioridade, sizeof(int), 1, arquivo);
    printf("passo na funcao salvar cartao");
}

cartao_n *ler_cartao(FILE *arquivo) {
    cartao_n *cartao = malloc(sizeof(cartao_n));
    fread(&cartao->nome, 32, 1, arquivo);
    fread(&cartao->descripcao_problema, 512, 1, arquivo);
    fread(&cartao->prioridade, sizeof(int), 1, arquivo);
    return cartao;
}
