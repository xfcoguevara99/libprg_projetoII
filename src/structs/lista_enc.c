//
// Created by francisco on 6/10/2025.
//
#include "cartao.h"
#include "lista_enc.h"
#include <stddef.h>
#include <stdlib.h>


void adicionar_no(no **head, cartao_n *cartao) {
    no *novo_no = (no *) malloc(sizeof(no));
    //novo_no->dados = malloc(sizeof(cartao));
    novo_no->cartao = *cartao;
    if (*head == NULL) {
        novo_no->cartao_proximo = NULL;
    } else {
        novo_no->cartao_proximo = *head;
    }
    *head = novo_no;
}

void salvar_lista_encadeada(no *lista) {
    FILE *arquivo = fopen("lista_atendimentos_finalizados.bin", "wb");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo lista_atendimentos_finalizados.bin ");
        exit(-1);
    }
    no *no_atual = lista;
    while (no_atual != NULL) {
        fwrite(&no_atual->cartao, sizeof(cartao_n), 1, arquivo);
        no_atual = no_atual->cartao_proximo;
    }
    fflush(arquivo);
    fclose(arquivo);
}

no *ler_lista_encadeada() {
    FILE *arquivo = fopen("lista_atendimentos_finalizados.bin","rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo lista_atendimentos_finalizados.bin ");
        return NULL;
    }
    no *head = NULL;
    cartao_n temp;

    while (fread(&temp, sizeof(cartao_n), 1, arquivo) == 1) {
        no *novo = malloc(sizeof(no));
        if (!novo) {
            perror("Erro ao alocar memoria para no");
            exit(EXIT_FAILURE);
        }
        novo->cartao = temp;
        if (head == NULL) {
            novo->cartao_proximo = NULL;
        }
        novo->cartao_proximo = head;
        head = novo;
    }
        return head;
    fflush(arquivo);
    fclose(arquivo);
}
