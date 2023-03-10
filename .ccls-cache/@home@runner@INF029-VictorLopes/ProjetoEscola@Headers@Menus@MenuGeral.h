#ifndef __MENU_H_
#define __MENU_H_

#include <stdio.h>


int menu_geral() {
  int option;
  printf("\n====================================\n");
  printf("==============ESCOLA================\n");
  printf("====================================\n");
  printf("===[0] Sair                      ===\n");
  printf("===[1] Aluno\\                     ===\n");
  printf("===[2] Professor\\                ===\n");
  printf("===[3] Disciplina\\               ===\n");
  printf("===[4] Relatorios\\                ===\n");
  printf("===: ");
  scanf("%d", &option);
  return option;
}

#endif