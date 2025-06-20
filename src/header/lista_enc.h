//
// Created by francisco on 6/14/2025.
//

#ifndef LISTA_ENC_H
#define LISTA_ENC_H

typedef struct no_lista_enc {
    cartao_n cartao;
    struct no_lista_enc *cartao_proximo;
} no;

void adicionar_no(no **head, cartao_n *cartao);

void salvar_lista_encadeada(no *lista);

no *ler_lista_encadeada();

void liberar_lista_encadeada(no **head);
#endif //LISTA_ENC_H
