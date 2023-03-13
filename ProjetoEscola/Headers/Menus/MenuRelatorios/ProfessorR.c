#include <stdio.h>
#include <stdlib.h>
#include "ProfessorR.h"
#include "../../StructsBase/professor.h"

void menu_relatoriosProfessor() {
  int option;
  system("clear");
  puts("====================================================");
  puts("============Professor/RELATORIOS====================");
  puts("====================================================");
  puts("===[0] Voltar                                    ===");
  puts("===[1] Listar Professores por sexo               ===");
  puts("===[2] Listar Professores por ordem alfabetica   ===");
  puts("===[3] Listar Professores por data de nascimento ===");
  printf("===: ");
  scanf("%d", &option);
  switch(option){
    case 0:{
      break;
    }
    case 1:{
      ListarProfessorPorSexo();
      break;
    }
    case 2:{
      ListarProfessorPorOrdemAlfabetico();
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