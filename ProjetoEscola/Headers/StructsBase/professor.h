#include "aluno.h"

#ifndef _PROFESSOR_H
#define _PROFESSOR_H


typedef struct{
  char name[50];
  int matricula;
  char sex;
  char cpf[15];
  Data dataBirth;
}Professor;

void InserirProfessor();
void ExcluirProfessor();
void AtualizarProfessor();
void ListarProfessor();
void ListarProfessorPorSexo();
void ListarProfessorPorOrdemAlfabetico();


#endif