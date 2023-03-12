#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "aluno.h"

typedef struct {
  char name[50];
  int codigo;
  char semestre[20];
  char professor[50];
  Aluno ListAluno[3];
} Disciplinas;


void InserirDisciplina();
void ExcluirDisciplina();
void AtualizarDisciplina();
void ListarDisciplina();
void ListarDisciplinaComAlunos();
void InserirAlunoNaDisciplina();
void ExcluirAlunoNaDisciplina();

#endif