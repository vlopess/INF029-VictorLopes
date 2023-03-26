#include "Headers/StructsBase/aluno.h"
#include "Headers/StructsBase/professor.h"
#include "Headers/StructsBase/disciplina.h"
#include "Headers/Menus/MenuGeral.h"
#include "Headers/Menus/MenuRelatorios/Relatorios.h"
#include "Headers/StructsBase/Base.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 3
#define SUCESS -1

int main(void) {

  int isFullA = 0;
  Aluno aluno[TAM];
  aluno[0].QuantDisc = 0;

  int isFullD = 0;
  Disciplinas disciplinas[TAM];
  disciplinas[0].QuantAluno = 0;

  int isFullP = 0;
  Professor professores[TAM];

  int SubOption, option, RelaOption, retorno;

  do {
    option = menu_geral();
    switch (option) {
    case 0: {
      system("clear");
      printf("Saindo ...\n");
      break;
    } // sair do progrma
    case 1: {
      do {
        SubOption = menu_aluno();
        switch (SubOption) {
        case 0: {
          break;
        } 
        case 1: {
          retorno = InserirAluno(isFullA, aluno);
          if (retorno == SUCESS) {            
            isFullA++;
          }
          break;
        }
        case 2: {
          retorno = ExcluirAluno(isFullA, aluno);
          if (retorno == SUCESS) {
            isFullA--;
          }
          break;
        }
        case 3: {
          AtualizarAluno(isFullA, aluno);
          break;
        }
        case 4: {
          ListarAluno(isFullA, aluno);
          break;
        }
        case 5: {
          do {
            RelaOption = menu_relatoriosAluno();
            switch (RelaOption) {
            case 0: {
              break;
            }
            case 1: {
              ListarAlunoPorSexo(isFullA, aluno);
              break;
            }
            case 2: {
              ListarAlunoPorOrdemAlfabetico(isFullA, aluno);
              break;
            }
            case 3: {
              ListarAlunoPorOrdemNascimento(isFullA, aluno);
              break;
            }
            case 4: {
              ListarAlunoComMenosDeTresDisciplinas(isFullA, aluno);
              break;
            }
            }
          } while (RelaOption);
          break;
        }
        }
      } while (SubOption);
      break;
    } // menu aluno
    case 2: {
      system("clear");
      do {
        SubOption = menu_professor();
        switch (SubOption) {
        case 0: {
          break;
        }
        case 1: {
          retorno = InserirProfessor(isFullP, professores);
          if (retorno == SUCESS) {            
            isFullP++;
          }
          break;
        }
        case 2: {
          retorno = ExcluirProfessor(isFullP, professores);
          if (retorno == SUCESS) {
            isFullP--;
          }
          break;
        }
        case 3: {
          AtualizarProfessor(isFullP, professores);
          break;
        }
        case 4: {
          ListarProfessor(isFullP, professores);
          break;
        }
        case 5: {
          do {
            RelaOption = menu_relatoriosProfessor();
            switch (RelaOption) {
            case 0: {
              break;
            }
            case 1: {
              ListarProfessorPorSexo(isFullP, professores);
              break;
            }
            case 2: {
              ListarProfessorPorOrdemAlfabetico(isFullP, professores);
              break;
            }
            case 3: {
              ListarProfessorPorOrdemNascimento(isFullP, professores);
              break;
            }
            }
          } while (RelaOption);
          break;
        }
        }
      } while (SubOption);
      break;
    } // menu professor
    case 3: {
      do {
        SubOption = menu_disciplina();
        switch (SubOption) {
        case 0: {
          break;
        }
        case 1: {
          retorno =
              InserirDisciplina(isFullP, isFullD, disciplinas, professores);
          if (retorno == SUCESS) {
            isFullD++;
          }
          break;
        }
        case 2: {
          retorno = ExcluirDisciplina(isFullD, disciplinas);
          if (retorno == SUCESS) {
            isFullD--;
          }
          break;
        }
        case 3: {
          AtualizarDisciplina(isFullP, isFullD, disciplinas, professores);
          break;
        }
        case 4: {
          InserirAlunoNaDisciplina(isFullD, disciplinas, isFullA, aluno);
          break;
        }
        case 5: {
          ExcluirAlunoDaDisciplina(isFullD, disciplinas, isFullA, aluno);
          break;
        }
        case 6: {
          ListarDisciplina(isFullD, disciplinas, isFullP, professores);
          break;
        }
        case 7: {
          do {
            RelaOption = menu_relatoriosDisciplina();
            switch (RelaOption) {
            case 0: {
              break;
            }
            case 1: {
              ListarDisciplinaComAlunos(isFullD, disciplinas, isFullA, aluno,
                                        isFullP, professores);
              break;
            }
            case 2: {
              ListarDisciplinasComMaisDeQuarenta(isFullD, disciplinas, isFullP,
                                                 professores);
              break;
            }
            }
          } while (RelaOption);
          break;
        }
        }
      } while (SubOption);
      break;
    } // menu disciplina
    case 4: {
      do {
        RelaOption = menu_relatorios();
        switch (RelaOption) {
        case 0: {
          break;
        }
        case 1: {
          Aniversariantes(isFullA, aluno, isFullP, professores);
          break;
        }
        case 2: {
          Buscar(isFullA, aluno, isFullP, professores);
          break;
        }
        }
      } while (RelaOption);
      break;
    } // menu relatório
    }
  } while (option);
}