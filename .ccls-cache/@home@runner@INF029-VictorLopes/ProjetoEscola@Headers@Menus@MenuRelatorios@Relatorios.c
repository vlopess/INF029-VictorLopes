#include "Relatorios.h"
#include "../../StructsBase/Base.h"
#include <stdio.h>
#include <stdlib.h>

int menu_relatorios() {
  int option;
  system("clear");
  do{
  puts("==================================================");
  puts("============RELATORIOS============================");
  puts("==================================================");
  puts("===[0] Voltar                                  ===");
  puts("===[1] Aniversariante do mes                   ===");
  puts("===[2] Lista de Pessoas                        ===");
  printf("==: ");
  scanf("%d", &option);
  return option;
  } while (option);
}

int menu_relatoriosProfessor() {
  int option;
  do{
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
  return option;
  } while (option);
}

int menu_relatoriosDisciplina() {
  int option;
  system("clear");
  do{
  puts("==================================================");
  puts("==============Disciplina/RELATORIOS===============");
  puts("==================================================");
  puts("===[0] Voltar                                  ===");
  puts("===[1] Listar Disciplinas com alunos           ===");
  puts("===[2] Lista de disciplinas com + de 40 alunos ===");
  printf("==: ");
  scanf("%d", &option);
  return option;
    } while (option);
}

int menu_relatoriosAluno() {
  int option;

  do {
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
    return option;
  } while (option);
}