#include "Headers/Menus/MenuGeral.h"
#include "Headers/Menus/MenuRelatorios/Relatorios.h"

#include "Headers/StructsBase/Base.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int main(void) {

  int isFullA = 0;
  Aluno aluno[TAM];
  aluno[0].QuantDisc = 0;

  int isFullD = 0;
  Disciplinas disciplinas[TAM];
  disciplinas[0].QuantAluno = 0;

  int isFullP = 0;
  Professor professores[TAM];

  int SubOption, option;
  
  do {
    option = menu_geral();
    switch (option) {
        case 0: {
        system("clear");
        printf("Saindo ...\n");
        break;
      }
        case 1: {
        do{
        SubOption = menu_aluno();
        switch (SubOption) {
        case 0: {
          break;
        }
        case 1: {
          InserirAluno(isFullA, aluno);
          if(isFullA != TAM){
            aluno[isFullA].matricula = GerarCodigo();
            aluno[isFullA].QuantDisc++;
            isFullA++;
          }
          break;
        }
        case 2: {
          ExcluirAluno(isFullA, aluno);
          if(isFullA != 0){
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
          do{
            option = menu_relatoriosAluno();
            switch (option) {
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
          }while(option);
          break;
        }
        }
          }while(SubOption);
          break;
        }
        case 2: {
          system("clear");
          SubOption = menu_professor();
          switch (option) {
          case 0: {
            break;
          }
          case 1: {
            InserirProfessor(isFullP, professores);
            isFullP++;
            break;
          }
          case 2: {
            ExcluirProfessor(isFullP, professores);
            isFullP--;
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
            option = menu_relatoriosProfessor();
            switch (option) {
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
            break;
          }
          }
          break;
        }
        case 3: {
          SubOption = menu_disciplina();
          switch (option) {
          case 0: {
            break;
          }
          case 1: {
            InserirDisciplina(isFullP, isFullD, disciplinas, professores);
            isFullD++;
            break;
          }
          case 2: {
            ExcluirDisciplina(isFullD, disciplinas);
            isFullD--;
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
            option = menu_relatoriosDisciplina();
            switch (option) {
            case 0: {
              break;
            }
            case 1: {
              ListarDisciplinaComAlunos(isFullD, disciplinas, isFullA, aluno, isFullP,
                                        professores);
              break;
            }
            case 2: {
              ListarDisciplinasComMaisDeQuarenta(isFullD, disciplinas, isFullP,
                                                 professores);
              break;
            }
            }
            break;
          }
          }
          break;
        }
        case 4: {
          SubOption = menu_relatorios();
          switch (option) {
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
          break;
        }
      }
  }while(option);
}