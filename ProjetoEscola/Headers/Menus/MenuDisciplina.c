#ifndef __MENUD_H_
#define __MENUD_H_

#include <stdio.h>


int menu_disciplina() {
  int option;
  printf("\n====================================\n");
  printf("===============ALUNO================\n");
  printf("====================================\n");
  printf("===[0] Voltar\\                  ===\n");
  printf("===[1] Inserir Disciplina\\       ===\n");
  printf("===[2] Excluir Disciplina\\       ===\n");
  printf("===[3] Atualizar Disciplina\\     ===\n");
  printf("===[4] Listar Disciplina\\        ===\n");
  printf("===: ");
  scanf("%d", &option);
  return option;
}

#endif