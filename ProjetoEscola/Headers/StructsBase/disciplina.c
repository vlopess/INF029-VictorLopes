#include "disciplina.h"
#include "aluno.h"
#include "Base.h"
#include "../Validation/validate.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Funções da Disciplina======================================

int InserirDisciplina(int isFullP, int isFullD, Disciplinas disciplinas[], Professor professores[]) {
  int voltar, erro;
  system("clear");
  if (isFullD != TAM) {
    if (isFullP != 0) {

      puts("====================================");
      puts("========MATRICULAR DISCIPLINA=======");
      puts("====================================");
      do {
        printf("Nome da disciplina: ");
        getchar();
        fgets(disciplinas[isFullD].name, 50, stdin);
        size_t ln = strlen(disciplinas[isFullD].name) - 1;
        if (disciplinas[isFullD].name[ln] == '\n')
          disciplinas[isFullD].name[ln] = '\0';
        printf("Semestre da disciplina: ");
        fgets(disciplinas[isFullD].semestre, 20, stdin);
        ln = strlen(disciplinas[isFullD].semestre) - 1;
        if (disciplinas[isFullD].semestre[ln] == '\n')
          disciplinas[isFullD].semestre[ln] = '\0';
        for(int k = 0; k < isFullP; k++){
          printf("%s, %d\n", professores[k].name, professores[k].matricula);
        }
        printf("Numero de matricula do professor da disciplina: ");
        scanf("%d", &disciplinas[isFullD].matriculaProfessor);
        erro = ValidarExistenciaProfessor(
            disciplinas[isFullD].matriculaProfessor, isFullP, professores);
      } while (erro);
      disciplinas[isFullD].codigo = GerarCodigo();      
      puts("Disciplina cadastrada com sucesso!!");
      puts("==[1] Voltar");
      scanf("%d", &voltar);
      return -1;
    } else {
      puts("Sem professores matriculados para criar disciplina");
      puts("==[1] Voltar");
      scanf("%d", &voltar);
      return 0;
    }
  } else {
    puts("\nLista esta cheia");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
    return 0;
  }  
}

int ExcluirDisciplina(int isFullD, Disciplinas disciplinas[]) {
  int e, j, i, voltar, code, c, o = 1;
  if (isFullD == 0) {
    puts("A lista de disciplinas esta vazia");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
    return 0;
  } else {
    puts("================DISCIPLINAS=================");
    for(int k = 0; k < isFullD; k++){
      printf("%s, %d\n", disciplinas[k].name, disciplinas[k].codigo);
    }
    printf("Digite o codigo da Disciplina que deseja excluir: ");
    scanf("%d", &code);
    for (e = 0; e < isFullD; e++) {
      if (code == disciplinas[e].codigo) {
        o = 1;
        for (j = e; j < isFullD - 1; j++) {
          for (i = 0; disciplinas[j].name[i] != '\0' ||
                      disciplinas[j + 1].name[i] != '\0';
               i++) {
            disciplinas[j].name[i] = disciplinas[j + 1].name[i];
          }
          disciplinas[j].name[i] = '\0';
        }
        for (j = e; j < isFullD - 1; j++) {
          disciplinas[j].matriculaProfessor =
              disciplinas[j + 1].matriculaProfessor;
          disciplinas[j].codigo = disciplinas[j + 1].codigo;
        }
        for (j = e; j < isFullD - 1; j++) {
          for (i = 0; disciplinas[j].semestre[i] != '\0' ||
                      disciplinas[j + 1].semestre[i] != '\0';
               i++) {
            disciplinas[j].semestre[i] = disciplinas[j + 1].semestre[i];
          }
          disciplinas[j].semestre[i] = '\0';
        }
        for (c = e; c < isFullD - 1; c++) {
          disciplinas[c].QuantAluno = disciplinas[c + 1].QuantAluno;
          for (i = 0; i < disciplinas[c].QuantAluno; i++) {
            disciplinas[c].ListAluno[i] = disciplinas[c + 1].ListAluno[i];
          }
        }      
        puts("Disciplina excluida com sucesso!!");
        puts("==[1] Voltar");
        scanf("%d", &voltar);
        return -1;
      }
    }
    if(o){
      printf("Codigo de disciplina invalido");
      puts("==[1] Voltar");
      scanf("%d", &voltar);
      return 0;
    }
  }  
}

void AtualizarDisciplina(int isFullP, int isFullD, Disciplinas disciplinas[], Professor professor[]) {
  int a, i, j, voltar, code, erro, c = 1;
  if (isFullD == 0) {
    puts("A lista de disciplinas esta vazia");
  } else {
    puts("================DISCIPLINAS=================");
    for(int k = 0; k < isFullD; k++){
      printf("%s, %d\n", disciplinas[k].name, disciplinas[k].codigo);
    }
    printf("Digite o codigo da disciplinas que deseja atualizar: ");
    scanf("%d", &code);
    for (a = 0; a < isFullD; a++) {
      if (code == disciplinas[a].codigo) {
        c = 0;
        do {
          puts("====================================");
          puts("======Atualizar DISCIPLINAS=========");
          puts("====================================");
          printf("Nome da disciplina: ");
          getchar();
          fgets(disciplinas[a].name, 50, stdin);
          size_t ln = strlen(disciplinas[a].name) - 1;
          if (disciplinas[a].name[ln] == '\n')
            disciplinas[a].name[ln] = '\0';
          printf("Semestre da Disciplina:");
          fgets(disciplinas[a].semestre, 50, stdin);
          ln = strlen(disciplinas[a].semestre) - 1;
          if (disciplinas[a].semestre[ln] == '\n')
            disciplinas[a].semestre[ln] = '\0';
          printf("Numero de matricula do professor da disciplina: ");
          scanf("%d", &disciplinas[a].matriculaProfessor);
          erro = ValidarExistenciaProfessor(disciplinas[a].matriculaProfessor,
                                            isFullP, professor);
        } while (erro);
      }
    }
    if (c) {
      puts("Codigo de matricula inexistente");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ListarDisciplina(int isFullD, Disciplinas disciplinas[], int isFullP,
                      Professor professores[]) {
  int i, voltar, c;
  if (isFullD == 0) {
    puts("Sem disciplinas matriculadas");
  } else {
    for (i = 0; i < isFullD; i++) {
      puts("==========================================");
      printf("Nome: %s\n", disciplinas[i].name);
      printf("Codigo: %d\n", disciplinas[i].codigo);
      printf("Semestre: %s\n", disciplinas[i].semestre);
      for (c = 0; c < isFullP; c++) {
        if (disciplinas[i].matriculaProfessor == professores[c].matricula) {
          printf("Professor: %s\n", professores[c].name);
          break;
        }
      }
      if (c == isFullP) {
        puts("SEM PROFESSOR");
      }
      puts("==========================================");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void InserirAlunoNaDisciplina(int isFullD, Disciplinas disciplinas[],
                              int isFullA, Aluno aluno[]) {
  int d, a, y, voltar, j, code, c = 1, i = 0;
  if (isFullD == 0) {
    puts("Sem disciplinas matriculadas");
  } else {
    puts("\n================DISCIPLINAS=================");
    for(int k = 0; k < isFullD; k++){
      printf("%s, %d\n", disciplinas[k].name, disciplinas[k].codigo);
    }
    printf("Digite o codigo da disciplinas que deseja: ");
    scanf("%d", &code);
    for (d = 0; d < isFullD; d++) {
      if (code == disciplinas[d].codigo) {
        c = 0;
        if (disciplinas[d].QuantAluno != TAM_MAX_ALUNOS_POR_DISCIPLINA) {
          if (isFullA == 0) {
            puts("Nao ha alunos matriculados");
          } else {
            puts("================ALUNOS=================");
            for(int k = 0; k < isFullA; k++){
                printf("%s, %d\n", aluno[k].name, aluno[k].matricula);
            }
            printf("Digite a matricula do Aluno que deseja: ");
            scanf("%d", &code);
            for(y = 0; y < disciplinas[d].QuantAluno; y++){
              if(code == disciplinas[d].ListAluno[y]) break;
            }
            if(y == disciplinas[d].QuantAluno){
              for (a = 0, i = 1; a < isFullA; a++) {
                if (code == aluno[a].matricula) {
                    i = 0;
                    disciplinas[d].ListAluno[disciplinas[d].QuantAluno] = aluno[a].matricula;
                    disciplinas[d].QuantAluno++;
                    puts("Aluno cadastrado na disciplina com sucesso!!");
                    break;
                }
              }
            }else{
              puts("Aluno ja matriculado na disciplina");
            }
          }
        } else {
          puts("Turma cheia");
        }
      }
    }
    if (c) {
      puts("Codigo de disciplina inexistente");
    }
    if (i) {
      puts("Numero de matricula inexistente");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ExcluirAlunoDaDisciplina(int isFullD, Disciplinas disciplinas[],
                              int isFullA, Aluno aluno[]) {
  int e, j, i, d, voltar, code;
  if (isFullD == 0) {
    puts("Sem disciplinas matriculadas");
  } else {
    puts("============EXCLUIR ALUNO DA DISCIPLINA=================");
    for(int k = 0; k < isFullD; k++){
      printf("%s, %d\n", disciplinas[k].name, disciplinas[k].codigo);
    }
    printf("Digite o codigo da disciplina que deseja excluir o aluno: ");
    scanf("%d", &code);
    for (d = 0; d < isFullD; d++) {
      if (code == disciplinas[d].codigo) {
        if (disciplinas[d].QuantAluno == 0) {
          puts("Sem alunos matriculados");
        } else {
          puts("___________EXCLUIR ALUNO DA DISCIPLINA__________");
          for(int k = 0; k < isFullA; k++){
            printf("%s, %d\n", aluno[k].name, aluno[k].matricula);
          }
          printf("Digite a matricula do Aluno que deseja excluir: ");
          scanf("%d", &code);
          for (e = 0; e < isFullA; e++) {
            if (code == aluno[e].matricula) {
              for (j = e; j < isFullD; j++) {
                disciplinas[d].ListAluno[j] = disciplinas[d].ListAluno[j + 1];
              }
              disciplinas[d].QuantAluno--;
              puts("Aluno excluido da disciplina com sucesso!!");
              break;
            }
          }
          if (e == isFullA) {
            puts("Numero de matricula inexistente");
          }
        }
        break;
      }
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ListarDisciplinaComAlunos(int isFullD, Disciplinas disciplinas[],
                               int isFullA, Aluno aluno[], int isFullP,
                               Professor professores[]) {
  int i, voltar, j, c, k;
  system("clear");
  if (isFullD == 0) {
    puts("Sem disciplinas matriculadas");
  } else {
    puts("==============DISCIPLINA================");
    for (i = 0; i < isFullD; i++) {
      fflush(stdin);
      printf("Nome: %s\n", disciplinas[i].name);
      printf("Codigo: %d\n", disciplinas[i].codigo);
      printf("Semestre: %s\n", disciplinas[i].semestre);
      for (c = 0; c < isFullP; c++) {
        if (disciplinas[i].matriculaProfessor == professores[c].matricula) {
          printf("Professor: %s\n", professores[c].name);
          break;
        }
      }
      if (c == isFullP) {
        puts("SEM PROFESSOR");
      }
      puts("=========ALUNOS==============================");
      if (disciplinas[i].QuantAluno == 0) {
        puts("\t\tSem alunos matriculados");
      } else {
        for (j = 0; j < disciplinas[i].QuantAluno; j++) {
          for (k = 0; k < isFullA; k++) {
            if (disciplinas[i].ListAluno[j] == aluno[k].matricula) {
              printf("\t\tNome: %s\n", aluno[k].name);
              printf("\t\tMatricula: %d\n", aluno[k].matricula);
              printf("\t\tSexo: %c\n", aluno[k].sex);
              printf("\t\tCPF: %s\n", aluno[k].cpf);
              printf("\t\tData de Nascimento: %d/%d/%d\n",
                     aluno[k].dataBirth.dia, aluno[k].dataBirth.mes,
                     aluno[k].dataBirth.ano);
              puts("________________________________________");
            }
          }
        }
      }
      puts("==========================================");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}



void ListarDisciplinasComMaisDeQuarenta(int isFullD, Disciplinas disciplinas[], int isFullP, Professor professores[]) {
  int c, i, voltar, a = 1;
  system("clear");
  if (isFullD == 0) {
    puts("\nSem disciplinas matriculadas");
  } else {
    for (i = 0; i < isFullD; i++) {
      if (disciplinas[i].QuantAluno > 4) {
        a = 0;
        fflush(stdin);
        puts("==========================================");
        printf("Nome: %s\n", disciplinas[i].name);
        printf("Codigo: %d\n", disciplinas[i].codigo);
        printf("Semestre: %s\n", disciplinas[i].semestre);
        for (c = 0; c < isFullP; c++) {
          if (disciplinas[i].matriculaProfessor == professores[c].matricula) {
            printf("Professor: %s\n", professores[c].name);
            break;
          }
        }
        if (c == isFullP) {
          puts("SEM PROFESSOR");
        }
        puts("==========================================");
      }
    }
  }
  if (a) {
    puts("Nao ha disciplinas com mais de 40 alunos");
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}