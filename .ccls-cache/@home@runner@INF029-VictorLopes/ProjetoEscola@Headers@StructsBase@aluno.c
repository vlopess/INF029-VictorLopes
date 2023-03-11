#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 3
Aluno aluno[TAM];
int isFullA = 0;

void InserirAluno() {
  if (isFullA != TAM) {
    system("clear");
    printf("====================================\n");
    printf("===========MATRICULAR ALUNO=========\n");
    printf("====================================\n");
    printf("Nome do aluno: ");
    getchar();
    fgets(aluno[isFullA].name, 50, stdin);
    printf("Numero de matricula: ");
    scanf("%d", &aluno[isFullA].matricula);
    getchar();
    printf("Sexo do aluno [M/F]: ");
    aluno[isFullA].sex = getchar();
    getchar();
    printf("CPF do aluno: ");
    fgets(aluno[isFullA].cpf, 15, stdin);
    printf("Data de nascimento dd MM AAAA: ");
    scanf("%d%d%d", &aluno[isFullA].dataBirth.dia,
          &aluno[isFullA].dataBirth.mes, &aluno[isFullA].dataBirth.ano);
    isFullA++;

  } else {
    printf("\nLista esta cheia\n");
    getchar();
  }
}

void ExcluirAluno() {
  int e, j, i;
  printf("\n================ALUNOS=================\n");
  for (i = 0; i < isFullA; i++) {
    fflush(stdin);
    printf("%d  Nome: %s, %d\n", i, aluno[i].name, aluno[i].matricula);
  }
  printf("\n=======================================\n");
  printf("Digite a posicao do Aluno que deseja excluir: ");
  scanf("%d", &e);
  for (j = e; j < isFullA - 1; j++) {
    for (i = 0; aluno[j].name[i] != '\0' || aluno[j + 1].name[i] != '\0'; i++) {
      aluno[j].name[i] = aluno[j + 1].name[i];
    }
    aluno[j].name[i] = '\0';
  }

  for (j = e; j < isFullA - 1; j++) {
    aluno[j].matricula = aluno[j + 1].matricula;
  }
  for (j = e; j < isFullA - 1; j++) {
    aluno[j].sex = aluno[j + 1].sex;
  }
  for (j = e; j < isFullA - 1; j++) {
    for (i = 0; aluno[j].cpf[i] != '\0' || aluno[j + 1].cpf[i] != '\0'; i++) {
      aluno[j].cpf[i] = aluno[j + 1].cpf[i];
    }
    aluno[j].cpf[i] = '\0';
  }
  for (j = e; j < isFullA - 1; j++) {
    aluno[j].dataBirth.dia = aluno[j + 1].dataBirth.dia;
    aluno[j].dataBirth.mes = aluno[j + 1].dataBirth.mes;
    aluno[j].dataBirth.ano = aluno[j + 1].dataBirth.ano;
  }
  isFullA--;
}
void AtualizarAluno() {
  int a, i;
  printf("\n================ALUNOS=================\n");
  for (i = 0; i < isFullA; i++) {
    fflush(stdin);
    printf("%d  Nome: %s, %d\n", i, aluno[i].name, aluno[i].matricula);
  }
  printf("\n=======================================\n");
  printf("Digite a posicao do Aluno que deseja atualizar: ");
  scanf("%d", &a);
  system("clear");
  printf("====================================\n");
  printf("===========Atualizar ALUNO=========\n");
  printf("====================================\n");
  printf("Nome do aluno: ");
  getchar();
  fgets(aluno[a].name, 50, stdin);
  printf("Numero de matricula: ");
  scanf("%d", &aluno[a].matricula);
  getchar();
  printf("Sexo do aluno [M/F]: ");
  aluno[a].sex = getchar();
  getchar();
  printf("CPF do aluno: ");
  fgets(aluno[a].cpf, 15, stdin);
  printf("Data de nascimento dd MM AAAA: ");
  scanf("%d%d%d", &aluno[a].dataBirth.dia, &aluno[a].dataBirth.mes,
        &aluno[a].dataBirth.ano);
}

void ListarAluno() {
  int i;
  if (isFullA == 0) {
    printf("\nSem alunos matriculados\n");
  }
  for (i = 0; i < isFullA; i++) {
    fflush(stdin);
    printf("\n==========================================\n");
    printf("Nome: %s", aluno[i].name);
    printf("Matricula: %d\n", aluno[i].matricula);
    printf("Sexo: %c\n", aluno[i].sex);
    printf("CPF: %s\n", aluno[i].cpf);
    printf("Data de Nascimento: %d/%d/%d\n", aluno[i].dataBirth.dia,
           aluno[i].dataBirth.mes, aluno[i].dataBirth.ano);
    printf("\n==========================================\n");
  }
}