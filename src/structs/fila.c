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
        exit(EXIT_FAILURE);
    }
    if ((*fila)->cartoes[(*fila)->tail] != NULL) {
        (*fila)->cartoes[(*fila)->tail] = cartao;
        (*fila)->tail++;
        (*fila)->tamanho++;
    }
}

cartao_n *proximo_da_fila(fila_t **fila) {
    if ((*fila)->tamanho == 0) {
        printf("Error: fila vazia");
        exit(EXIT_FAILURE);
    }
    cartao_n *proximo_cartao = (*fila)->cartoes[(*fila)->head];
    (*fila)->cartoes[(*fila)->head] = NULL;
    (*fila)->head++;
    (*fila)->tamanho--;
    return proximo_cartao;
}

void salvar_fila(fila_t *fila) {
    FILE *arquivo = fopen("fila_atendimentos.bin", "wb");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    fwrite(&fila->tamanho, sizeof(int), 1, arquivo);
    fwrite(&fila->head, sizeof(int), 1, arquivo);
    fwrite(&fila->tail, sizeof(int), 1, arquivo);
    for (int i = fila->head; i < fila->tail; i++) {
        cartao_n *cartao = fila->cartoes[i];
        salvar_cartao(arquivo, cartao);
    }
    fclose(arquivo);
}

fila_t *ler_fila_atendimento() {
    FILE *arquivo = fopen("fila_atendimentos.bin", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    int tamanho, head, tail;
    fread(&tamanho, sizeof(int), 1, arquivo);
    fread(&head, sizeof(int), 1, arquivo);
    fread(&tail, sizeof(int), 1, arquivo);
    fila_t *fila = criar_fila();
    for (int i = 0; i < tamanho; i++) {
        cartao_n *cartao = ler_cartao(arquivo);
        fila->cartoes[fila->tail++] = cartao;
        //fila->tamanho++;
    }
    fila->tamanho = tamanho;
    fila->head = head;
    fila->tail = tail;
    fclose(arquivo);
    return fila;
}
