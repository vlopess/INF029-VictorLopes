#ifndef __ALUNOS_H_
#define __ALUNOS_H_

typedef struct{
  int dia;
  int mes;
  int ano;
}Data;

typedef struct {
  char name[50];
  int matricula;
  char sex;
  char cpf[15];
  Data dataBirth;
}Aluno;

#define TAM 3

void InserirAluno();
void ExcluirAluno();
void AtualizarAluno();
void ListarAluno();
int Isfull();

#endif