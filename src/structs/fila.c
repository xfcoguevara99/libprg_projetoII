//
// Created by francisco on 6/10/2025.
//
#include <stdio.h>
#include "fila.h"
#include <stdlib.h>
#include "cartao.h"

fila_t *criar_fila() {
    fila_t *fila = (fila_t *) malloc(sizeof(fila_t));
    fila->head = 0;
    fila->tail = 0;
    fila->capacidade = CAPACIDADE_INICIAL_FILA;
    fila->tamanho = 0;
    return fila;
}

void adicionar_na_fila(fila_t **fila, cartao_n *cartao) {
    if ((*fila)->tamanho == (*fila)->capacidade) {
        printf("Erro: Fila cheia (overflow)");
        return;
    }
    (*fila)->cartoes[(*fila)->tail] = cartao;
    (*fila)->tail++;
    (*fila)->tamanho++;

}

cartao_n *proximo_da_fila(fila_t **fila) {
    if ((*fila)->tamanho == 0) {
        printf("Fila de atendimento vazia..\n");
        return NULL;
    }
    cartao_n *proximo_cartao = (*fila)->cartoes[(*fila)->head];
    (*fila)->cartoes[(*fila)->head] = NULL;
    (*fila)->head++;
    (*fila)->tamanho--;
    return proximo_cartao;
}

void salvar_fila(fila_t *fila,FILE *arquivo) {

    if (fwrite(&fila->tamanho, sizeof(int), 1, arquivo)!=1) {
        printf("Erro ao gravar o tamnaho da fila\n");
    }
    for (int i = 0; i < fila->tamanho; i++) {
        cartao_n *cartao = fila->cartoes[fila->head + i];
        salvar_cartao(arquivo, cartao);
    }

}

fila_t *ler_fila_atendimento() {
    FILE *arquivo = fopen("fila_atendimentos.bin", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo fila_atendimentos.bin");
        exit(EXIT_FAILURE);
    }
    int tamanho, head, tail;
    fread(&tamanho, sizeof(int), 1, arquivo);
    if (tamanho==0) {
        return NULL;
    }
    fila_t *fila = criar_fila();
    for (int i = 0; i < tamanho; i++) {
        cartao_n *cartao = ler_cartao(arquivo);
        fila->cartoes[fila->tail++] = cartao;
    }
    fila->tamanho = tamanho;
    fila->head = 0;
    fila->tail = tamanho;
    fclose(arquivo);
    return fila;
}

void liberar_fila(fila_t **fila) {
    for (int i= 0; i<(*fila)->tamanho;i++) {
        free((*fila)->cartoes[(*fila)->head+i]);
    }
    free(*fila);
    *fila = NULL;
}
