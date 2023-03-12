#include <stdio.h>
#include <stdlib.h>
#include "Relatorios.h"
#include "../../StructsBase/aluno.h"

void menu_relatorios(){
  int option;
  system("clear");
  puts("==================================================");
  puts("============RELATORIOS============================");
  puts("==================================================");
  puts("===[0] Voltar                                  ===");
  puts("===[1] Aniversariante do mes                   ===");
  puts("===[2] Lista de Pessoas                        ===");
  printf("==: ");
  scanf("%d", &option);
  switch(option){
    case 0:{
      break;
    }
    case 1:{
      Aniversariantes();
      break;
    }
    case 2:{
      break;
    }
  }
}