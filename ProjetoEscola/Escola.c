#include <stdio.h>
#include<stdlib.h>

#define TAM 5

int lista_Alunos[TAM];

typedef struct data {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct ficha_de_alunos {
  char name[50];
  int matricula;
  char sex;
  char cpf[14];
  Data dataBirth;
} Aluno;

typedef struct ficha_de_professores {
  char name[50];
  int matricula;
  char sex[20];
  char cpf[14];
} Professores;

typedef struct ficha_de_disciplinas {
  char name[50];
  int codigo;
  char semestre[20];
  char professor[50];
} Disciplinas;

int main(void) {
  int option = 1;
  Aluno aluno[TAM];
  int isFull = 0, i; 
  Professores professores[TAM];
  
  while(option){
  system("clear");
  printf("====================================\n");
  printf("==============ESCOLA================\n");
  printf("====================================\n");
  printf("===[0] Sair\n");
  printf("===[1] Inserir Aluno\n");
  printf("===[2] Excluir Aluno\n");
  printf("===[3] Listar Aluno\n");
  printf("===[4] Inserir Professor\n");
  printf("===[5] Excluir Professor\n");
  printf("===[6] Inserir Disciplina\n");
  printf("===[7] Excluir Disciplina\n");
  printf("== :");
  scanf("%d", &option);
  switch(option){
      case 0:{
        printf("Saindo ...");
        getchar();
        break;
      }
      case 1:{
        if(isFull != TAM){
          printf("====================================\n");
          printf("===========MATRICULAR ALUNO=========\n");
          printf("====================================\n");
          printf("Nome do aluno: ");
          fflush(stdin);
          scanf("%s", aluno[isFull].name);
          fflush(stdin);
          printf("Numero de matricula: ");
          scanf("%d", &aluno[isFull].matricula);
          printf("Sexo do aluno [M/F]: ");
          fflush(stdin);
          scanf("%c", &aluno[isFull].sex);
          printf("CPF do aluno: ");
          fflush(stdin);
          scanf("%s", aluno[isFull].cpf);
          printf("Data de nascimento dd MM AAAA: ");
          scanf("%d%d%d", &aluno[isFull].dataBirth.dia,&aluno[isFull].dataBirth.mes, &aluno[isFull].dataBirth.ano);
          isFull++;
          getchar();
          
        }else{
          printf("Lista esta cheia");
          getchar();
        }
        break;
      }
      case 2:{
        printf("===[2] Excluir Aluno\n");
        getchar();
        break;
      }
      case 3:{
        if(isFull == 0){
          printf("Sem alunos matriculados");
          getchar();
          break;
        }
        for(i = 0; i < isFull ;i++){
          fflush(stdin);
          printf("\n==========================================\n");
          printf("Nome : %s\n", aluno[i].name);
          printf("Matricula : %d\n", aluno[i].matricula);
          printf("Sexo : %c\n", aluno[i].sex);
          printf("CPF : %s\n", aluno[isFull].cpf);
          printf("Data de Nascimento : %d/%d/%d\n", aluno[isFull].dataBirth.dia,aluno[isFull].dataBirth.mes, aluno[isFull].dataBirth.ano);
          printf("==========================================\n");
          getchar();
        }
        break;
      }
      case 4:{
        printf("===[4] Excluir Professor\n");
        getchar();
        break;
      }
      case 5:{
        printf("===[5] Inserir Disciplina\n");
        getchar();
        break;
      }
      case 6:{
        printf("===[6] Excluir Disciplina\n");
        getchar();
        break;
      }
    }
  }
  
}