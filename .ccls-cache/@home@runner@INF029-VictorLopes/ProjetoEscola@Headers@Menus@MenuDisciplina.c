#include <stdio.h>
#include "MenuDisciplina.h"
#include "MenuGeral.h"
#include "../StructsBase/disciplina.h"

int menu_disciplina() {
  int option;
  printf("\n====================================\n");
  printf("===============DISCIPLINA============\n");
  printf("====================================\n");
  printf("===[0] Voltar\\                  ===\n");
  printf("===[1] Inserir Disciplina\\       ===\n");
  printf("===[2] Excluir Disciplina\\       ===\n");
  printf("===[3] Atualizar Disciplina\\     ===\n");
  printf("===[4] Listar Disciplina\\        ===\n");
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