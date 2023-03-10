#ifndef __MENUA_H_
#define __MENUA_H_

#include <stdio.h>


int menu_aluno() {
  int option;
  printf("\n====================================\n");
  printf("===============ALUNO================\n");
  printf("====================================\n");
  printf("===[0] Voltar\\                  ===\n");
  printf("===[1] Inserir Aluno\\           ===\n");
  printf("===[2] Excluir Aluno\\           ===\n");
  printf("===[3] Atualizar Aluno\\         ===\n");
  printf("===[4] Listar Aluno\\            ===\n");
  printf("===: ");
  scanf("%d", &option);
  return option;
}

#endif