#include <stdio.h>
#include <stdlib.h>
#include "Relatorios.h"
#include "../../StructsBase/Base.h"


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
      Buscar();
      break;
    }
  }
}

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

void menu_relatoriosAluno() {
  int option;
  system("clear");

  do {
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
    switch (option) {
    case 0: {
      break;
    }
    case 1: {
      ListarAlunoPorSexo();
      break;
    }
    case 2: {
      ListarAlunoPorOrdemAlfabetico();
      break;
    }
    case 3: {
      ListarAlunoPorOrdemNascimento();
      break;
    }
    case 4: {
      break;
    }
    }
  } while (option);
}