#include "aluno.h"
#include <stdio.h>

typedef struct data {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct ficha_de_alunos {
  char name[50];
  int matricula;
  char sex;
  int cpf;
  Data dataBirth;
} Aluno;