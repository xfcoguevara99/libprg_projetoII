//
// Created by francisco on 6/10/2025.
//
#include <pilha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cartao.h"
#include "lista_enc.h"
#include "fila.h"

int main() {
    FILE *arquivo = fopen("fila_atendimentos.bin","rb");
    cartao_n cartao1 = {"ruperto","descipcion1",1},cartao2 = {"paola","descripcion2",2};
    pilha_acoes *pilha = criar_pilha(),*pilha1 = criar_pilha();
    cadastrar_acao(&pilha,"hola munedo curel");
    cadastrar_acao(&pilha,"asagasgasga");
    cadastrar_acao(&pilha,"sgHrgRGRGWRGWR");
    cartao1.acoes = *pilha;
    salvar_cartao(&cartao1);
    cadastrar_acao(&pilha1,"hola munedo curel");
    cadastrar_acao(&pilha1,"asagasgasga");
    cadastrar_acao(&pilha1,"sgHrgRGRGWRGWR");
    cartao2.acoes = *pilha1;
    fila_t *fila = criar_fila();
    adicionar_na_fila(&fila,&cartao1);
    adicionar_na_fila(&fila,&cartao2);
    salvar_fila(fila);
    cartao_n *cartao3 = ler_cartao(arquivo);
    fila_t *fila2 = ler_fila_atendimento();
    fclose(arquivo);




    return 0;
};
