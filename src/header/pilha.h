//
// Created by paola on 6/15/2025.
//

#ifndef PILHA_H
#define PILHA_H
#define CAPACIDADE_INICIAL_PILHA 15
#define TAMANHO_DA_STRING 128
typedef struct pilha pilha_acoes;
pilha_acoes *criar_pilha();
void cadastrar_acao(pilha_acoes **pilha,char *descricao);
void desfazer_acao(pilha_acoes **pilha);
#endif //PILHA_H
