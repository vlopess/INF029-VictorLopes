#include <stdio.h>
#include <stdlib.h>
#include "MenuProfessor.h"
#include "../StructsBase/professor.h"
#include "MenuGeral.h"


void menu_professor() {
  int option = 1;

  do {
    system("clear");
    puts("====================================");
    puts("===============PROFESSOR============");
    puts("====================================");
    puts("===[0] Voltar                    ===");
    puts("===[1] Inserir Professor         ===");
    puts("===[2] Excluir Professor         ===");
    puts("===[3] Atualizar Professor       ===");
    puts("===[4] Listar Professor          ===");
    puts("===[5] Relatorios Professor      ===");
    printf("===: ");
    scanf("%d", &option);
    switch (option) {
      case 0: {
        menu_geral();
        break;
      }
      case 1: {
        InserirProfessor();
        break;
      }
      case 2: {
        ExcluirProfessor();
        break;
      }
      case 3: {
        AtualizarProfessor();
        break;
      }
      case 4: {
        ListarProfessor();
        break;
      }
    }
  }while (option);
}