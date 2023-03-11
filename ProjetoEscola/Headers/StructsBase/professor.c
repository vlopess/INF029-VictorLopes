#include "professor.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 3

Professor professores[TAM];
int isFullP = 0;

void InserirProfessor() {
  if (isFullP != TAM) {
    system("clear");
    printf("====================================\n");
    printf("========MATRICULAR PROFESSOR========\n");
    printf("====================================\n");
    printf("Nome do Professor: ");
    getchar();
    fgets(professores[isFullP].name, 50, stdin);
    printf("Numero de matricula: ");
    scanf("%d", &professores[isFullP].matricula);
    getchar();
    printf("Sexo do professor [M/F]: ");
    professores[isFullP].sex = getchar();
    getchar();
    printf("CPF do professor: ");
    fgets(professores[isFullP].cpf, 15, stdin);
    printf("Data de nascimento dd MM AAAA: ");
    scanf("%d%d%d", &professores[isFullP].dataBirth.dia,
          &professores[isFullP].dataBirth.mes,
          &professores[isFullP].dataBirth.ano);
    isFullP++;

  } else {
    printf("\nLista esta cheia\n");
  }
}

void ExcluirProfessor() {
  int e, j, i;
  printf("\n================PROFESSOR=================\n");
  for (i = 0; i < isFullP; i++) {
    fflush(stdin);
    printf("%d  Nome: %s, %d\n", i, professores[i].name,
           professores[i].matricula);
  }
  printf("\n=======================================\n");
  printf("Digite a posicao do professor que deseja excluir: ");
  scanf("%d", &e);
  for (j = e; j < isFullP - 1; j++) {
    for (i = 0;
         professores[j].name[i] != '\0' || professores[j + 1].name[i] != '\0';
         i++) {
      professores[j].name[i] = professores[j + 1].name[i];
    }
    professores[j].name[i] = '\0';
  }

  for (j = e; j < isFullP - 1; j++) {
    professores[j].matricula = professores[j + 1].matricula;
  }
  for (j = e; j < isFullP - 1; j++) {
    professores[j].sex = professores[j + 1].sex;
  }
  for (j = e; j < isFullP - 1; j++) {
    for (i = 0; professores[j].cpf[i] != '\0' || professores[j + 1].cpf[i] != '\0';
         i++) {
      professores[j].cpf[i] = professores[j + 1].cpf[i];
    }
    professores[j].cpf[i] = '\0';
  }
  for (j = e; j < isFullP - 1; j++) {
    professores[j].dataBirth.dia = professores[j + 1].dataBirth.dia;
    professores[j].dataBirth.mes = professores[j + 1].dataBirth.mes;
    professores[j].dataBirth.ano = professores[j + 1].dataBirth.ano;
  }
  isFullP--;
}

void AtualizarProfessor() {
  int a, i;
  printf("\n================PROFESSORES=================\n");
  for (i = 0; i < isFullP; i++) {
    fflush(stdin);
    printf("%d  Nome: %s, %d\n", i, professores[i].name,
           professores[i].matricula);
  }
  printf("\n=======================================\n");
  printf("Digite a posicao do Professor que deseja atualizar: ");
  scanf("%d", &a);
  system("clear");
  printf("====================================\n");
  printf("===========Atualizar Professor=========\n");
  printf("====================================\n");
  printf("Nome do Professor: ");
  getchar();
  fgets(professores[a].name, 50, stdin);
  printf("Numero de matricula: ");
  scanf("%d", &professores[a].matricula);
  getchar();
  printf("Sexo do Professor [M/F]: ");
  professores[a].sex = getchar();
  getchar();
  printf("CPF do Professor: ");
  fgets(professores[a].cpf, 15, stdin);
  printf("Data de nascimento dd MM AAAA: ");
  scanf("%d%d%d", &professores[a].dataBirth.dia, &professores[a].dataBirth.mes,
        &professores[a].dataBirth.ano);
}

void ListarProfessor() {
  int i;
  if (isFullP == 0) {
    printf("\nSem professor matriculados\n");
  }
  for (i = 0; i < isFullP; i++) {
    fflush(stdin);
    printf("\n==========================================\n");
    printf("Nome: %s", professores[i].name);
    printf("Matricula: %d\n", professores[i].matricula);
    printf("Sexo: %c\n", professores[i].sex);
    printf("CPF: %s\n", professores[i].cpf);
    printf("Data de Nascimento: %d/%d/%d\n", professores[i].dataBirth.dia,
           professores[i].dataBirth.mes, professores[i].dataBirth.ano);
    printf("\n==========================================\n");
  }
}
