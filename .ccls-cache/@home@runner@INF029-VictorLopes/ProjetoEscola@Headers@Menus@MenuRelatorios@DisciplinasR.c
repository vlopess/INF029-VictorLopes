#include <stdio.h>
#include "DisciplinasR.h"

int menu_relatoriosDisciplina() {
  int option;
  printf("\n================================================\n");
  printf("================Disciplina/RELATORIOS=============\n");
  printf("==================================================\n");
  printf("===[0] Voltar\\                                ===\n");
  printf("===[1] Listar Disciplinas com alunos           ===\n");
  printf("===[2] Lista de disciplinas com + de 40 alunos ===\n");
  printf("===: ");
  scanf("%d", &option);
  return option;
}