#include <stdio.h>
#include "MenuProfessor.h"
#include "MenuGeral.h"
#include "../StructsBase/professor.h"

int menu_professor() {
  int option;
  printf("\n====================================\n");
  printf("===============PROFESSOR=============\n");
  printf("====================================\n");
  printf("===[0] Voltar\\                  ===\n");
  printf("===[1] Inserir Professor\\       ===\n");
  printf("===[2] Excluir Professor\\       ===\n");
  printf("===[3] Atualizar Professor\\     ===\n");
  printf("===[4] Listar Professor\\        ===\n");
  printf("===: ");
  scanf("%d", &option);
  switch(option){
    case 0:{
      menu_geral();
      break;
    }
    case 1:{

      break;
    }
    case 2:{

      break;
    }
    case 3:{

      break;
    }
    case 4:{

      break;
    }
  }
}