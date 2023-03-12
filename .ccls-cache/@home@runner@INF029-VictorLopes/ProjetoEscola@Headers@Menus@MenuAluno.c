#include "MenuAluno.h"
#include "../StructsBase/aluno.h"
#include "MenuGeral.h"
#include "MenuRelatorios/AlunoR.h"
#include <stdio.h>
#include <stdlib.h>

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
        menu_geral();
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