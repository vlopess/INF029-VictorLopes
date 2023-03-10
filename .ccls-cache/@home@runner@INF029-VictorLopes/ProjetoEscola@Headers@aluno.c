#include "aluno.h"

typedef struct{
  int dia;
  int mes;
  int ano;
}Data;

typedef struct{
  char name[50];
  int matricula;
  char sex;
  int cpf;
  Data dataBirth;
}Aluno;
