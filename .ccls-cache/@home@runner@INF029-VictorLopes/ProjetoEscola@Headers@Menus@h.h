#ifndef __MENUR_H_
#define __MENUR_H_

#include <stdio.h>


int menu_relatorios() {
  int option;
  printf("\n=======================================\n");
  printf("============RELATORIOS===================\n");
  printf("=========================================\n");
  printf("===[0] Voltar\\                                  ===\n");
  printf("===[1] Listar Disciplinas com alunos             ===\n");
  printf("===[2] Listar alunos por sexo                    ===\n");
  printf("===[3] Listar alunos por ordem alfabetica        ===\n");
  printf("===[4] Listar alunos por data de nascimento      ===\n");
  printf("===: ");
  scanf("%d", &option);
  return option;
}

#endif