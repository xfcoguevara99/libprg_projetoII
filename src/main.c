//
// Created by francisco on 6/10/2025.
//
#include <pilha.h>
#include <stdio.h>
#include "cartao.h"
#include "lista_enc.h"
#include "fila.h"

int main() {
    cartao_n *cartao1, *cartao2, *cartao3, *cartao4;
    criar_cartao(&cartao1, "francisco", "diversos problemas de conexão", 3);
    criar_cartao(&cartao2, "pablo", "diversos problemas de conexão", 3);
    criar_cartao(&cartao3, "paola", "diversos problemas de conexão", 3);
    criar_cartao(&cartao4, "milagros", "diversos problemas de conexão", 3);
    fila_t *fila_chamadas = crear_fila();
    adicionar_na_fila(&fila_chamadas, &cartao1);
    adicionar_na_fila(&fila_chamadas, &cartao2);
    adicionar_na_fila(&fila_chamadas, &cartao3);
    adicionar_na_fila(&fila_chamadas, &cartao4);
    cartao_n *atendimento1 = proximo_da_fila(&fila_chamadas);
    pilha_acoes *pilha = criar_pilha();
    char *acao1 = "primeiramente foi realizado o analisis do problema e suas possiveis causas";
    cadastrar_acao(&pilha, acao1);
    char *acao2 = "foi conferido todos os possiveis componenntes geradores do problema";
    cadastrar_acao(&pilha, acao2);
    char *acao3 = "o problema e a bobina numero 1 que apresentava um curto, foi solicitada uma nova peca";
    cadastrar_acao(&pilha, acao3);
    desfazer_acao(&pilha);
    char *acao4 = "o dias 16/06/2025 recebemos a peca e foi substituida finalizando assim o requerimento";
    cadastrar_acao(&pilha, acao4);
    inserir_acoes(&atendimento1, &pilha);
    no *lista_atendimentos = NULL;
    adicionar_no(&lista_atendimentos, atendimento1);
    cartao_n *atendimento2 = proximo_da_fila(&fila_chamadas);
    pilha_acoes *pilha2 = criar_pilha();
    cadastrar_acao(&pilha2, acao1);
    cadastrar_acao(&pilha2, acao4);
    inserir_acoes(&atendimento2, &pilha2);
    adicionar_no(&lista_atendimentos, atendimento2);
};
