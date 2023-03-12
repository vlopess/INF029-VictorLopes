#include "MenuDisciplina.h"
#include "../StructsBase/disciplina.h"
#include "MenuGeral.h"
#include "MenuRelatorios/DisciplinasR.h"
#include <stdio.h>
#include <stdlib.h>

int menu_disciplina() {
  int option = 1;

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
    puts("===[7] Listar Disciplina com Alunos=");
    puts("===[8] Relatorios Disciplina     ===");
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
      ListarDisciplinaComAlunos();
      break;
    }
    case 8: {
      menu_relatoriosDisciplina();    
      break;
    }
    }
  } while (option);
}