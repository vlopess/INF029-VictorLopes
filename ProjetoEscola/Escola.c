#include "Headers/Menus/MenuGeral.h"
#include "Headers/StructsBase/aluno.h"
#include "Headers/StructsBase/disciplina.h"
#include "Headers/StructsBase/professor.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int lista_Alunos[TAM];

int main(void) {
  int option = 1;
  int isFullA = 0, isFullP = 0, isFullD = 0, i;
  Aluno aluno[TAM];
  Professor professores[TAM];
  Disciplinas disciplinas[TAM];

  while (option) {
    // system("clear");
    menu_geral();
    scanf("%d", &option);
    switch (option) {
    case 0: {
      system("clear");
      printf("Saindo ...\n");
      getchar();
      break;
    }
    case 1: {
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
      break;
    }
    case 2: {
      int e, j;
      printf("\n================ALUNOS=================\n");
      for (i = 0; i < isFullA; i++) {
        fflush(stdin);
        printf("%d  Nome: %s, %d\n", i, aluno[i].name, aluno[i].matricula);
      }
      printf("\n=======================================\n");
      printf("Digite a posicao do Aluno que deseja excluir: ");
      scanf("%d", &e);
      for (j = e; j < isFullA - 1; j++) {
        for (i = 0; aluno[j].name[i] != '\0' || aluno[j + 1].name[i] != '\0';
             i++) {
          aluno[j].name[i] = aluno[j + 1].name[i];
        }
        aluno[j].name[i] = '\0';
      }

      for(j = e; j < isFullA - 1; j++){
        aluno[j].matricula = aluno[j + 1].matricula;
      }
      for(j = e; j < isFullA - 1; j++){
        aluno[j].sex = aluno[j + 1].sex;
      }
      for (j = e; j < isFullA - 1; j++) {
        for (i = 0; aluno[j].cpf[i] != '\0' || aluno[j + 1].cpf[i] != '\0';
             i++) {
          aluno[j].cpf[i] = aluno[j + 1].cpf[i];
        }
        aluno[j].cpf[i] = '\0';
      }
      for(j = e; j < isFullA - 1; j++){
        aluno[j].dataBirth.dia = aluno[j + 1].dataBirth.dia;
        aluno[j].dataBirth.mes = aluno[j + 1].dataBirth.mes;
        aluno[j].dataBirth.ano = aluno[j + 1].dataBirth.ano;
      }
      isFullA--;
      break;
    }
    case 3: {
      int a;
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
      break;
    }
    case 4: {
      if (isFullA == 0) {
        printf("\nSem alunos matriculados\n");
        break;
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
      getchar();
      break;
    }
    case 5: {
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
        getchar();
      }
      break;
    }
    case 6: {
      int a;
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
      scanf("%d%d%d", &professores[a].dataBirth.dia,
            &professores[a].dataBirth.mes, &professores[a].dataBirth.ano);
      break;
    }
    case 7: {
      if (isFullP == 0) {
        printf("\nSem professor matriculados\n");
        break;
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
      getchar();
      break;
    }
    case 8: {
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
      break;
    }
    case 9: {
      break;
    }
    case 10: {
      if (isFullD == 0) {
        printf("\nSem professor matriculados\n");
        break;
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
      getchar();
      break;
    }
    case 11: {
      break;
    }
    case 12: {
      break;
    }
    }
  }
}