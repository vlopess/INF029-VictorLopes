#include "disciplina.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int isFullD = 0;
int isFullDA = 0;
Disciplinas disciplinas[TAM];


void InserirDisciplina() {
  int voltar;
  if (isFullD != TAM) {
    system("clear");
    printf("====================================\n");
    printf("========MATRICULAR DISCIPLINA=======\n");
    printf("====================================\n");
    printf("Nome da disciplina: ");
    getchar();
    fgets(disciplinas[isFullD].name, 50, stdin);
    printf("Codigo da disciplina: ");
    scanf("%d", &disciplinas[isFullD].codigo);
    getchar();
    printf("Semestre da disciplina: ");
    fgets(disciplinas[isFullD].semestre, 20, stdin);
    printf("Professor da disciplina: ");
    fgets(disciplinas[isFullD].professor, 50, stdin);
    isFullD++;
  } else {
    printf("\nLista esta cheia\n");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void ExcluirDisciplina() {
  int e, j, i, voltar;
  if (isFullD == 0) {
    puts("A lista de disciplinas esta vazia");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    printf("\n================DISCIPLINAS=================\n");
    for (i = 0; i < isFullD; i++) {
      fflush(stdin);
      printf("%d  Nome: %s, %d\n", i, disciplinas[i].name,
             disciplinas[i].codigo);
    }
    printf("\n=======================================\n");
    printf("Digite a posicao da Disciplina que deseja excluir: ");
    scanf("%d", &e);

    for (j = e; j < isFullD - 1; j++) {
      for (i = 0;
           disciplinas[j].name[i] != '\0' || disciplinas[j + 1].name[i] != '\0';
           i++) {
        disciplinas[j].name[i] = disciplinas[j + 1].name[i];
      }
      disciplinas[j].name[i] = '\0';
    }
    for (j = e; j < isFullD - 1; j++) {
      for (i = 0; disciplinas[j].professor[i] != '\0' ||
                  disciplinas[j + 1].professor[i] != '\0';
           i++) {
        disciplinas[j].professor[i] = disciplinas[j + 1].professor[i];
      }
      disciplinas[j].professor[i] = '\0';
    }
    for (j = e; j < isFullD - 1; j++) {
      for (i = 0; disciplinas[j].semestre[i] != '\0' ||
                  disciplinas[j + 1].semestre[i] != '\0';
           i++) {
        disciplinas[j].semestre[i] = disciplinas[j + 1].semestre[i];
      }
      disciplinas[j].semestre[i] = '\0';
    }
    for (j = e; j < isFullD - 1; j++) {
      disciplinas[j].codigo = disciplinas[j + 1].codigo;
    }
  }
}

void AtualizarDisciplina() {
  int a, i, voltar;
  if (isFullD == 0) {
    puts("A lista de disciplinas esta vazia");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    printf("\n================DISCIPLINAS=================\n");
    for (i = 0; i < isFullD; i++) {
      fflush(stdin);
      printf("%d  Nome: %s, %d\n", i, disciplinas[i].name,
             disciplinas[i].codigo);
    }
    printf("\n=======================================\n");
    printf("Digite a posicao do disciplinas que deseja atualizar: ");
    scanf("%d", &a);
    system("clear");
    printf("====================================\n");
    printf("======Atualizar DISCIPLINAS=========\n");
    printf("====================================\n");
    printf("Nome da disciplina: ");
    getchar();
    fgets(disciplinas[a].name, 50, stdin);
    printf("Codigo da disciplina: ");
    scanf("%d", &disciplinas[a].codigo);
    getchar();
    printf("Professor da Disciplina:");
    fgets(disciplinas[a].professor, 50, stdin);
    printf("Semestre da Disciplina:");
    fgets(disciplinas[a].semestre, 50, stdin);
  }
}

void ListarDisciplina() {
  int i, voltar;
  if (isFullD == 0) {
    printf("\nSem disciplinas matriculadas\n");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    for (i = 0; i < isFullD; i++) {
      fflush(stdin);
      printf("\n==========================================\n");
      printf("Nome: %s", disciplinas[i].name);
      printf("Codigo: %d\n", disciplinas[i].codigo);
      printf("Semestre: %s", disciplinas[i].semestre);
      printf("Professor: %s", disciplinas[i].professor);
      printf("\n==========================================\n");
    }
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void InserirAlunoNaDisciplina() {
  int d, i, a, voltar, j;
  int isfull = Isfull();
  if (isFullD == 0) {
    printf("\nSem disciplinas matriculadas\n");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    printf("\n================DISCIPLINAS=================\n");
    for (i = 0; i < isFullD; i++) {
      fflush(stdin);
      printf("%d  Nome: %s, %d\n", i, disciplinas[i].name,
             disciplinas[i].codigo);
    }
    printf("\n=======================================\n");
    printf("Digite a posicao do disciplinas que deseja: ");
    scanf("%d", &d);
    if (isfull == 0) {
      printf("A lista nao possui alunos matriculados\n");
      puts("==[1] Voltar");
      scanf("%d", &voltar);
    } else {
      printf("\n================ALUNOS=================\n");
      for (i = 0; i < isfull; i++) {
        fflush(stdin);
        printf("%d  Nome: %s, %d\n", i, aluno[i].name, aluno[i].matricula);
      }
      printf("\n=======================================\n");
      printf("Digite a posicao do Aluno que deseja: ");
      scanf("%d", &a);
      for (i = 0; aluno[j].name[i] != '\0'; i++) {
        disciplinas[d].ListAluno[isFullDA].name[i] = aluno[a].name[i];
      }
      disciplinas[d].ListAluno[isFullDA].name[i] = '\0';
      disciplinas[d].ListAluno[isFullDA].matricula = aluno[a].matricula;
      disciplinas[d].ListAluno[isFullDA].sex = aluno[a].sex;
      for (i = 0; aluno[j].name[i] != '\0'; i++) {
        disciplinas[d].ListAluno[isFullDA].cpf[i] = aluno[a].cpf[i];
      }
      disciplinas[d].ListAluno[isFullDA].cpf[i] = '\0';

      disciplinas[d].ListAluno[isFullDA].dataBirth.dia = aluno[a].dataBirth.dia;
      disciplinas[d].ListAluno[isFullDA].dataBirth.mes = aluno[a].dataBirth.mes;
      disciplinas[d].ListAluno[isFullDA].dataBirth.ano = aluno[a].dataBirth.ano;
    }
    isFullDA++;
  }
}

void ListarDisciplinaComAlunos() {
  int i, voltar, j;
  if (isFullD == 0) {
    printf("\nSem disciplinas matriculadas\n");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    for (i = 0; i < isFullD; i++) {
      fflush(stdin);
      printf("\n==========================================\n");
      printf("Nome: %s", disciplinas[i].name);
      printf("Codigo: %d\n", disciplinas[i].codigo);
      printf("Semestre: %s", disciplinas[i].semestre);
      printf("Professor: %s", disciplinas[i].professor);
      printf("--ALUNOS____________________________________\n");
      for (j = 0; j < isFullDA; j++) {
        printf("Nome: %s", disciplinas[i].ListAluno[j].name);
        printf("Matricula: %d\n", disciplinas[i].ListAluno[j].matricula);
        printf("Sexo: %c\n", disciplinas[i].ListAluno[j].sex);
        printf("CPF: %s\n", disciplinas[i].ListAluno[j].cpf);
        printf("Data de Nascimento: %d/%d/%d\n", disciplinas[i].ListAluno[j].dataBirth.dia,
               disciplinas[i].ListAluno[j].dataBirth.mes, disciplinas[i].ListAluno[j].dataBirth.ano);
      }
      printf("\n==========================================\n");
    }
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}