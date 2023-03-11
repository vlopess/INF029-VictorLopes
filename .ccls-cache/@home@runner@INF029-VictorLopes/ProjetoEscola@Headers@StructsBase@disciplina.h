#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct {
  char name[50];
  int codigo;
  char semestre[20];
  char professor[50];
} Disciplinas;

void InserirDisciplina();
void ExcluirDisciplina();
void AtualizarDisciplina();
void ListarDisciplina();

#endif