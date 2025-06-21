//
// Created by francisco on 6/20/2025.
//

#include "estatisticas.h"

#include <stdio.h>
#include <stdlib.h>

void inicializar_estatisticas() {
    estatisticas *info = malloc(sizeof(estatisticas));
    info->atendimentos_totais = 0;
    info->tempo_total = 0;
    info->cartao.acoes.topo = -1;
    salvar_estatisticas(info);
    free(info);
}

estatisticas *leer_estatisticas() {
    estatisticas *info_estatisticas = malloc(sizeof(estatisticas));
    FILE *arquivo = fopen("estatisticas.bin", "rb");
    fread(&info_estatisticas->tempo_total, sizeof(double), 1, arquivo);
    fread(&info_estatisticas->atendimentos_totais, sizeof(int), 1, arquivo);
    fread(&info_estatisticas->cartao, sizeof(cartao_n), 1, arquivo);
    fclose(arquivo);
    return info_estatisticas;
}

void salvar_estatisticas(estatisticas *info) {
    FILE *arquivo = fopen("estatisticas.bin", "wb");
    if (fwrite(info, sizeof(estatisticas), 1, arquivo) != 1) {
        printf("Erro na escritura da das estatisticas.\n");
    }
    fflush(arquivo);
    fclose(arquivo);
}

void atualizar_estatisticas(estatisticas **info, cartao_n *cartao, double tempo_t) {
    if ((*info)->cartao.acoes.topo < cartao->acoes.topo) {
        (*info)->cartao = *cartao;
    }
    (*info)->tempo_total += tempo_t;
    (*info)->atendimentos_totais += 1;
}
