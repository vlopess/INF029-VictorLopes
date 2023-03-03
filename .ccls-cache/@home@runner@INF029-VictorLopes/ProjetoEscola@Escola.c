#include <stdio.h>

typedef struct DataBirth{
  int dd;
  int mm;
  int yy;
} DataBirth;

typedef struct ficha_de_alunos {
  char name[50];
  char matricula[14];
  char sex[20];
  DataBirth data;
  char cpf[14];
} aluno;

int main(void) {
  
}