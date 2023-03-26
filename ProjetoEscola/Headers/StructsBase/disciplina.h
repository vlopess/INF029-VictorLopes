#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "aluno.h"
#include "professor.h"


#define TAM_MAX_ALUNOS_POR_DISCIPLINA 5
#define TAM_IDEAL_ALUNOS_POR_DISCIPLINA 3

//DISCIPLINAS=================================================

typedef struct {
  char name[50];
  int codigo;
  char semestre[20];
  int matriculaProfessor;
  int ListAluno[TAM_MAX_ALUNOS_POR_DISCIPLINA];
  int QuantAluno;
} Disciplinas;


int InserirDisciplina(int isFullP, int isFullD, Disciplinas disciplinas[], Professor professores[]);
int ExcluirDisciplina(int isFullD, Disciplinas disciplinas[]);
void AtualizarDisciplina(int isFullP, int isFullD, Disciplinas disciplinas[], Professor professor[]);
void ListarDisciplina(int isFullD, Disciplinas disciplinas[], int isFullP, Professor professores[]);
void ListarDisciplinaComAlunos(int isFullD, Disciplinas disciplinas[], int isFullA, Aluno aluno[], int isFullP, Professor professores[]);
void ListarDisciplinasComMaisDeQuarenta(int isFullD, Disciplinas disciplinas[], int isFullP, Professor professores[]);
void InserirAlunoNaDisciplina(int isFullD, Disciplinas disciplinas[], int isFullA, Aluno aluno[]);
void ExcluirAlunoDaDisciplina(int isFullD, Disciplinas disciplinas[], int isFullA, Aluno aluno[]);


#endif