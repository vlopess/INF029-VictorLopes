#include <stdio.h>
#include <stdlib.h>
#include "MenuGeral.h"
#include "MenuRelatorios/Relatorios.h"
#include "../StructsBase/Base.h"


int menu_geral() {
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
    return option;
  }while (option);
}

int menu_professor() {
  int option;
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
    return option;
  }while (option);
}

int menu_disciplina() {
  int option;
  do {
    system("clear");
    puts("====================================");
    puts("===============DISCIPLINA===========");
    puts("====================================");
    puts("===[0] Voltar                    ===");
    puts("===[1] Inserir Disciplina        ===");
    puts("===[2] Excluir Disciplina        ===");
    puts("===[3] Atualizar Disciplina      ===");
    puts("===[4] Inserir Aluno na Disciplina==");
    puts("===[5] Excluir Aluno da Disciplina==");
    puts("===[6] Listar Disciplina         ===");
    puts("===[7] Relatorios Disciplina     ===");
    printf("===: ");
    scanf("%d", &option);
    return option;
  } while (option);
}

int menu_aluno() {
  int option;  ;
    system("clear");
    puts("====================================");
    puts("===============ALUNO================");
    puts("====================================");
    puts("===[0] Voltar                    ===");
    puts("===[1] Inserir Aluno             ===");
    puts("===[2] Excluir Aluno             ===");
    puts("===[3] Atualizar Aluno           ===");
    puts("===[4] Listar Aluno              ===");
    puts("===[5] Relatorios Aluno          ===");
    printf("===: ");
    scanf("%d", &option);
    return option;
}