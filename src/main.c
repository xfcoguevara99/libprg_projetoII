//
// Created by francisco on 6/10/2025.
//
#include <stdio.h>
#include "cartao.h"
#include "lista_enc.h"
int main(){
    cartao_n *cartao1,*cartao2,*cartao3,*cartao4;
    criar_cartao(&cartao1,"francisco","diversos problemas de conexão",3);
    criar_cartao(&cartao2,"pablo","diversos problemas de conexão",3);
    criar_cartao(&cartao3,"paola","diversos problemas de conexão",3);
    criar_cartao(&cartao4,"milagros","diversos problemas de conexão",3);
    no *head_list_enc = NULL;
    adicionar_no(&head_list_enc,cartao1);
    adicionar_no(&head_list_enc,cartao2);
    adicionar_no(&head_list_enc,cartao3);
    adicionar_no(&head_list_enc,cartao4);


};