//
// Created by paola on 6/20/2025.
//

#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H
#include <cartao.h>

typedef struct{
    double tempo_total;
    int atendimentos_totais;
    cartao_n cartao;
}estatisticas;
void inicializar_estatisticas();
estatisticas *leer_estatisticas();
void salvar_estatisticas(estatisticas *info);
void atualizar_estatisticas(estatisticas **info, cartao_n *cartao, double tempo_t);
#endif //ESTATISTICAS_H
