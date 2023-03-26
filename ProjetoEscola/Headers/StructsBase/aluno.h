#ifndef __ALUNOS_H_
#define __ALUNOS_H_

//ALUNOS=================================================

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
  int QuantDisc;
}Aluno;

int InserirAluno(int isFullA, Aluno aluno[]);
int ExcluirAluno(int isFullA, Aluno aluno[]);
void AtualizarAluno(int isFullA, Aluno aluno[]);
void ListarAluno(int isFullA, Aluno aluno[]);
void ListarAlunoPorSexo(int isFullA, Aluno aluno[]);
void ListarAlunoPorOrdemAlfabetico(int isFullA, Aluno aluno[]);
void ListarAlunoPorOrdemNascimento(int isFullA, Aluno aluno[]);
void ListarAlunoComMenosDeTresDisciplinas(int isFullA, Aluno aluno[]);

#endif