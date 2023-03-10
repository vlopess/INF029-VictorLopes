#ifndef __MENUP_H_
#define __MENUP_H_

#include <stdio.h>


int menu_professor() {
  int option;
  printf("\n====================================\n");
  printf("===============ALUNO================\n");
  printf("====================================\n");
  printf("===[0] Voltar\\                  ===\n");
  printf("===[1] Inserir Professor\\       ===\n");
  printf("===[2] Excluir Professor\\       ===\n");
  printf("===[3] Atualizar Professor\\     ===\n");
  printf("===[4] Listar Professor\\        ===\n");
  printf("===: ");
  scanf("%d", &option);
  return option;
}

#endif