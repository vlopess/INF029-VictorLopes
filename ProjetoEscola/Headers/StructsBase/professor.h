#ifndef _PROFESSOR_H
#define _PROFESSOR_H
#include "aluno.h"

//PROFESSOR===============================================

typedef struct{
  char name[50];
  int matricula;
  char sex;
  char cpf[15];
  Data dataBirth;
}Professor;

int InserirProfessor(int isFullP, Professor professores[]);
int ExcluirProfessor(int isFullP, Professor professores[]);
void AtualizarProfessor(int isFullP, Professor professores[]);
void ListarProfessor(int isFullP, Professor professores[]);
void ListarProfessorPorSexo(int isFullP, Professor professores[]);
void ListarProfessorPorOrdemAlfabetico(int isFullP, Professor professores[]);
void ListarProfessorPorOrdemNascimento(int isFullP, Professor professores[]);



#endif