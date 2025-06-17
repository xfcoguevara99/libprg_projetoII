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
#include "lista_enc.h"

int main() {
    cartao_n cartao1 = {"ruperto", "descipcion1", 1}, cartao2 = {"paola", "descripcion2", 2};
    pilha_acoes *pilha = criar_pilha(), *pilha1 = criar_pilha();
    cadastrar_acao(pilha, "hola munedo curel");
    cadastrar_acao(pilha, "asagasgasga");
    cadastrar_acao(pilha, "sgHrgRGRGWRGWR");
    cartao1.acoes = *pilha;
    FILE *arquivo_escritura = fopen("fila_atendimentos.bin", "wb");
    salvar_cartao(arquivo_escritura, &cartao1);
    fclose(arquivo_escritura);
    cadastrar_acao(pilha1, "hola munedo curel");
    cadastrar_acao(pilha1, "asagasgasga");
    cadastrar_acao(pilha1, "sgHrgRGRGWRGWR");
    cartao2.acoes = *pilha1;
    fila_t *fila = criar_fila();
    adicionar_na_fila(&fila, &cartao1);
    adicionar_na_fila(&fila, &cartao2);
    FILE *arquivo_leitura = fopen("fila_atendimentos.bin", "rb");
    cartao_n *cartao3 = ler_cartao(arquivo_leitura);
    fclose(arquivo_leitura);
    salvar_fila(fila);
    free(fila);
    fila_t *fila2 = ler_fila_atendimento();


    no *lista_encadeada = NULL;
    adicionar_no(&lista_encadeada, &cartao1);
    adicionar_no(&lista_encadeada, &cartao2);
    salvar_lista_encadeada(lista_encadeada);
    FILE *arquivo_leitura2 = fopen("lista_atendimentos_finalizados.bin", "rb");
    no *lista_encadeada_2 = ler_lista_encadeada(arquivo_leitura2);
    fclose(arquivo_leitura);
    return 0;
};
