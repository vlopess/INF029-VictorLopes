#include "MenuGeral.h"
#include "MenuAluno.h"
#include "MenuDisciplina.h"
#include "MenuProfessor.h"
#include "MenuRelatorios/Relatorios.h"
#include <stdio.h>
#include <stdlib.h>

void menu_geral(void) {
  int option;
  do {
    system("clear");
    puts("====================================");
    puts("==============ESCOLA================");
    puts("====================================");
    puts("===[0] Sair                      ===");
    puts("===[1] Aluno                     ===");
    puts("===[2] Professor                 ===");
    puts("===[3] Disciplina                ===");
    puts("===[4] Relatorios                ===");
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
        menu_relatorios();
        break;
      }
    }
  }while (option);
}