#include <stdio.h>
#include <stdlib.h>
#include "MenuGeral.h"
#include "MenuRelatorios/Relatorios.h"
#include "../StructsBase/Base.h"


void menu_geral(void) {
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
    switch (option) {
      case 0: {
        system("clear");
        printf("Saindo ...\n");
        break;
      }
      case 1: {
        system("clear");
        menu_aluno();
        break;
      }
      case 2: {
        system("clear");
        menu_professor();
        break;
      }
      case 3: {
        system("clear");
        menu_disciplina();
        break;
      }
      case 4: {
        system("clear");
        menu_relatorios();
        break;
      }
    }
  }while (option);
}

void menu_professor() {
  int option;
  system("clear");
  do {
    
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
    switch (option) {
      case 0: {
        break;
      }
      case 1: {
        InserirProfessor();
        break;
      }
      case 2: {
        ExcluirProfessor();
        break;
      }
      case 3: {
        AtualizarProfessor();
        break;
      }
      case 4: {
        ListarProfessor();
        break;
      }
      case 5: {
        menu_relatoriosProfessor();
        break;
      }
    }
  }while (option);
}

void menu_disciplina() {
  int option = 1;
system("clear");
  do {
    
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
    switch (option) {
    case 0: {
      break;
    }
    case 1: {
      InserirDisciplina();
      break;
    }
    case 2: {
      ExcluirDisciplina();
      break;
    }
    case 3: {
      AtualizarDisciplina();
      break;
    }
    case 4: {
      InserirAlunoNaDisciplina();
      break;
    }
    case 5: {
      ExcluirAlunoDaDisciplina();
      break;
    }
    case 6: {
      ListarDisciplina();
      break;
    }
    case 7: {
      menu_relatoriosDisciplina();    
      break;
    }
    }
  } while (option);
}

void menu_aluno() {
  int option;  ;

  do {
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
    switch (option) {
      case 0: {
        break;
      }
      case 1: {
        InserirAluno();
        break;
      }
      case 2: {
        ExcluirAluno();
        break;
      }
      case 3: {
        AtualizarAluno();
        break;
      }
      case 4: {
        ListarAluno();
        break;
      }
      case 5: {
        menu_relatoriosAluno();
        break;
      }
    }
  }while (option);
}