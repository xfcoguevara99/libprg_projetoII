//
// Created by francisco on 6/13/2025.
//

#include "cartao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criar_cartao(cartao_n *cartao, char *nome, char *descricao, int prioridade) {
    strcpy(cartao->nome, nome);
    strcpy(cartao->descripcao_problema, descricao);
    cartao->prioridade = prioridade;
}

void salvar_cartao(FILE *arquivo, cartao_n *cartao) {
    if (fwrite(cartao->nome, sizeof(cartao->nome), 1, arquivo) != 1) {
        printf("Erro ao guardar o nome do cartao\n");
    }
    if (fwrite(cartao->descripcao_problema, sizeof(cartao->descripcao_problema), 1, arquivo) != 1) {
        printf("Erro ao guardar a descricao do cartao\n");
    };
    if (fwrite(&cartao->prioridade, sizeof(int), 1, arquivo) != 1) {
        printf("Erro ao guardar a prioridade do cartao\n");
    };
}

cartao_n *ler_cartao(FILE *arquivo) {
    cartao_n *cartao = malloc(sizeof(cartao_n));
    fread(&cartao->nome, 32, 1, arquivo);
    fread(&cartao->descripcao_problema, 512, 1, arquivo);
    fread(&cartao->prioridade, sizeof(int), 1, arquivo);
    return cartao;
}
