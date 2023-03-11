#include <stdio.h>
#include <stdlib.h>
#include "MenuAluno.h"
#include "MenuGeral.h"
#include "../StructsBase/aluno.h"

void menu_aluno() {
  int option;
  printf("\n====================================\n");
  printf("===============ALUNO================\n");
  printf("====================================\n");
  printf("===[0] Voltar\\                  ===\n");
  printf("===[1] Inserir Aluno\\           ===\n");
  printf("===[2] Excluir Aluno\\           ===\n");
  printf("===[3] Atualizar Aluno\\         ===\n");
  printf("===[4] Listar Aluno\\            ===\n");
  printf("===: ");
  scanf("%d", &option);
  switch(option){
    case 0:{
      system("clear");
      menu_geral();
      break;
    }
    case 1:{
      system("clear");
      InserirAluno();
      menu_aluno();
      break;
    }
    case 2:{
      system("clear");
      ExcluirAluno();
      menu_aluno();
      break;
    }
    case 3:{
      system("clear");
      AtualizarAluno();
      menu_aluno();
      break;
    }
    case 4:{
      system("clear");
      ListarAluno();
      menu_aluno();
      break;
    }
  }
}