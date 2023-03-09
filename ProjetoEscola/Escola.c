#include "Headers/aluno.h"
#include <stdio.h>
#include<stdlib.h>


#define TAM 3

int lista_Alunos[TAM];

typedef struct ficha_de_professores {
  char name[50];
  int matricula;
  char sex;
  int cpf;
  Data dataBirth;
} Professores;

typedef struct ficha_de_disciplinas {
  char name[50];
  int codigo;
  char semestre[20];
  char professor[50];
} Disciplinas;

int main(void) {
  int option = 1;
  int isFullA = 0, isFullP = 0, isFullD = 0, i;
  Aluno aluno[TAM]; 
  Professores professores[TAM];
  Disciplinas disciplinas[TAM];
  
  while(option){
  // system("clear");
  printf("\n====================================\n");
  printf("==============ESCOLA================\n");
  printf("====================================\n");
  printf("===[0] Sair\n");
  printf("===[1] Inserir Aluno\n");
  printf("===[2] Excluir Aluno\n");
  printf("===[3] Listar Aluno\n");
  printf("===[4] Inserir Professor\n");
  printf("===[5] Excluir Professor\n");
  printf("===[6] Listar Professor\n");
  printf("===[7] Inserir Disciplina\n");
  printf("===[8] Excluir Disciplina\n");
  printf("===[9] Listar Disciplina\n");
  printf("== :");
  scanf("%d", &option);
  switch(option){
      case 0:{
        printf("Saindo ...");
        getchar();
        break;
      }
      case 1:{
        if(isFullA != TAM){
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
          scanf("%d",&aluno[isFullA].cpf);
          printf("Data de nascimento dd MM AAAA: ");
          scanf("%d%d%d", &aluno[isFullA].dataBirth.dia,&aluno[isFullA].dataBirth.mes, &aluno[isFullA].dataBirth.ano);
          isFullA++;          
          
        }else{
          printf("\nLista esta cheia\n");
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
        if(isFullA == 0){
          printf("\nSem alunos matriculados\n");
          break;
        }
        for(i = 0; i < isFullA ;i++){
          fflush(stdin);
          printf("\n==========================================\n");
          printf("Nome: %s", aluno[i].name);
          printf("Matricula: %d\n", aluno[i].matricula);
          printf("Sexo: %c\n", aluno[i].sex);
          printf("CPF: %d\n", aluno[i].cpf);
          printf("Data de Nascimento: %d/%d/%d\n", aluno[i].dataBirth.dia,aluno[i].dataBirth.mes, aluno[i].dataBirth.ano);
          printf("\n==========================================\n");         
        }
        getchar();
        break;
      }
      case 4:{
        if(isFullP != TAM){
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
          scanf("%d",&professores[isFullP].cpf);
          printf("Data de nascimento dd MM AAAA: ");
          scanf("%d%d%d", &professores[isFullP].dataBirth.dia,&professores[isFullP].dataBirth.mes, &professores[isFullP].dataBirth.ano);
          isFullP++;          
          
        }else{
          printf("\nLista esta cheia\n");
          getchar();
        }
        break;
      }
      case 5:{
        printf("===[5] Inserir Disciplina\n");
        getchar();
        break;
      }
      case 6:{
        if(isFullP == 0){
          printf("\nSem professor matriculados\n");
          break;
        }
        for(i = 0; i < isFullP ;i++){
          fflush(stdin);
          printf("\n==========================================\n");
          printf("Nome: %s", professores[i].name);
          printf("Matricula: %d\n", professores[i].matricula);
          printf("Sexo: %c\n", professores[i].sex);
          printf("CPF: %d\n", professores[i].cpf);
          printf("Data de Nascimento: %d/%d/%d\n", professores[i].dataBirth.dia,professores[i].dataBirth.mes, professores[i].dataBirth.ano);
          printf("\n==========================================\n");         
        }
        getchar();
        break;
      }
      case 7:{
        if(isFullD != TAM){
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
        }else{
          printf("\nLista esta cheia\n");
          getchar();
        }
        break;
      }
      case 8:{
      break;
      }
      case 9:{
        if(isFullD == 0){
          printf("\nSem professor matriculados\n");
          break;
        }
        for(i = 0; i < isFullD ;i++){
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
    }
  }
  
}