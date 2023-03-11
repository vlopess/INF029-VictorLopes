#include <stdio.h>
#include "ProfessorR.h"

int menu_relatoriosProfessor() {
  int option;
  printf("\n=======================================\n");
  printf("============Professor/RELATORIOS=============\n");
  printf("=========================================\n");
  printf("===[0] Voltar\\                                  ===\n");
  printf("===[1] Listar Professores por sexo               ===\n");
  printf("===[2] Listar Professores por ordem alfabetica   ===\n");
  printf("===[3] Listar Professores por data de nascimento ===\n");
  printf("===: ");
  scanf("%d", &option);
  return option;
}