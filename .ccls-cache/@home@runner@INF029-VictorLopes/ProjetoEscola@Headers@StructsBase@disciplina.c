#include "disciplina.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 3
int isFullD = 0;
Disciplinas disciplinas[TAM];

void InserirDisciplina() {
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
    getchar();
  }
}

void ExcluirDisciplina() {
  int e, j, i;
  printf("\n================DISCIPLINAS=================\n");
  for (i = 0; i < isFullD; i++) {
    fflush(stdin);
    printf("%d  Nome: %s, %d\n", i, disciplinas[i].name, disciplinas[i].codigo);
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

void AtualizarDisciplina() {
  int a, i;
  printf("\n================DISCIPLINAS=================\n");
  for (i = 0; i < isFullD; i++) {
    fflush(stdin);
    printf("%d  Nome: %s, %d\n", i, disciplinas[i].name, disciplinas[i].codigo);
  }
  printf("\n=======================================\n");
  printf("Digite a posicao do Aluno que deseja atualizar: ");
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

void ListarDisciplina() {
  int i;
  if (isFullD == 0) {
    printf("\nSem professor matriculados\n");
  }
  for (i = 0; i < isFullD; i++) {
    fflush(stdin);
    printf("\n==========================================\n");
    printf("Nome: %s", disciplinas[i].name);
    printf("Codigo: %d\n", disciplinas[i].codigo);
    printf("Semestre: %s", disciplinas[i].semestre);
    printf("Professor: %s", disciplinas[i].professor);
    printf("\n==========================================\n");
  }
}