//
// Created by francisco on 6/10/2025.
//
#include "cartao.h"
#include "lista_enc.h"
#include <stddef.h>
#include <stdlib.h>


typedef struct no_lista_enc {
    cartao_n *dados;
    no *proximo;

}no;

void adicionar_no(no **head,cartao_n *cartao) {
    no *novo_no = (no*)malloc(sizeof(no));
    //novo_no->dados = malloc(sizeof(cartao));
    novo_no->dados = cartao;
    if (*head == NULL) {
        novo_no->proximo =  NULL;
    }else {
        novo_no->proximo = *head;
    }
        *head = novo_no;
}