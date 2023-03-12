#include <stdio.h>
#include <stdlib.h>
#include "AlunoR.h"
#include "../../StructsBase/aluno.h"


void menu_relatoriosAluno() {
  int option;
  system("clear");
  puts("========================================================");
  puts("============ALUNO/RELATORIOS============================");
  puts("========================================================");
  puts("===[0] Voltar                                        ===");
  puts("===[1] Listar alunos por sexo                        ===");
  puts("===[2] Listar alunos por ordem alfabetica            ===");
  puts("===[3] Listar alunos por data de nascimento          ===");
  puts("===[4] Lista de alunos matriculados em 3 disciplinas ===");
  printf("==: ");
  scanf("%d", &option);
  switch(option){
    case 0:{
      break;
    }
    case 1:{
      ListarAlunoPorSexo();
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