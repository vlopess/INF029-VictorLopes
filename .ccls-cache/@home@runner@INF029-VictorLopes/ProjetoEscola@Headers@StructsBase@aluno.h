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
  int QuantDisc;
}Aluno;

void InserirAluno();
void ExcluirAluno();
void AtualizarAluno();
void ListarAluno();
void ListarAlunoPorSexo();
void ListarAlunoPorOrdemAlfabetico();
void Aniversariantes();
void Buscar();

#endif