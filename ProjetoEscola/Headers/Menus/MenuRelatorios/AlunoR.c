#include <stdio.h>
#include "AlunoR.h"


int menu_relatoriosAluno() {
  int option;
  printf("\n======================================================\n");
  printf("============ALUNO/RELATORIOS============================\n");
  printf("========================================================\n");
  printf("===[0] Voltar\\                                      ===\n");
  printf("===[1] Listar alunos por sexo                        ===\n");
  printf("===[2] Listar alunos por ordem alfabetica            ===\n");
  printf("===[3] Listar alunos por data de nascimento          ===\n");
  printf("===[4] Lista de alunos matriculados em 3 disciplinas ===\n");
  printf("===: ");
  scanf("%d", &option);
  return option;
}