#include <stdio.h>
#include <stdlib.h>
#include "DisciplinasR.h"
#include "../../StructsBase/disciplina.h"

void menu_relatoriosDisciplina() {
  int option;
  system("clear");
  puts("==================================================");
  puts("==============Disciplina/RELATORIOS===============");
  puts("==================================================");
  puts("===[0] Voltar                                  ===");
  puts("===[1] Listar Disciplinas com alunos           ===");
  puts("===[2] Lista de disciplinas com + de 40 alunos ===");
  printf("==: ");
  scanf("%d", &option);
  switch(option){
    case 0:{
      break;
    }
    case 1:{
      ListarDisciplinaComAlunos();
      break;
    }
    case 2:{
      break;
    }
  }
}