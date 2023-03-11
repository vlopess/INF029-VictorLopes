#include <stdio.h>
#include <stdlib.h>
#include "MenuGeral.h"
#include "MenuAluno.h"
#include "MenuDisciplina.h"
#include "MenuProfessor.h"

void menu_geral(void) {
  int option, i;
  printf("\n====================================\n");
  printf("==============ESCOLA================\n");
  printf("====================================\n");
  printf("===[0] Sair\n");
  printf("===[1] Aluno\n");
  printf("===[2] Professor\n");
  printf("===[3] Disciplina\n");
  printf("== :");
  scanf("%d", &option);
  switch (option) {
    case 0: {
      system("clear");
      printf("Saindo ...\n");
      break;
    }
    case 1: {
      system("clear");
      menu_aluno();
      break;
    }
    case 2: {
      system("clear");
      menu_professor();
      break;
    }
    case 3: {
      system("clear");
      menu_disciplina();
      break;
    }
    case 4: {
      system("clear");
      break;
    }
  }
  return option;
}