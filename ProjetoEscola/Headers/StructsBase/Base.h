#ifndef __BASE_H_
#define __BASE_H_
#define TAM_MAX_ALUNOS_POR_DISCIPLINA 5
#define TAM_IDEAL_ALUNOS_POR_DISCIPLINA 3

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

void InserirAluno();
void ExcluirAluno();
void AtualizarAluno();
void ListarAluno();
void ListarAlunoPorSexo();
void ListarAlunoPorOrdemAlfabetico();
void ListarAlunoPorOrdemNascimento();
void ListarAlunoComMenosDeTresDisciplinas();

//PROFESSOR===============================================

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
void ListarProfesorPorOrdemNascimento();

//DISCIPLINAS=================================================

typedef struct {
  char name[50];
  int codigo;
  char semestre[20];
  int matriculaProfessor;
  int ListAluno[TAM_MAX_ALUNOS_POR_DISCIPLINA];
  int QuantAluno;
} Disciplinas;


void InserirDisciplina();
void ExcluirDisciplina();
void AtualizarDisciplina();
void ListarDisciplina();
void ListarDisciplinaComAlunos();
void ListarDisciplinasComMaisDeQuarenta();
void InserirAlunoNaDisciplina();
void ExcluirAlunoDaDisciplina();
void IniciarTamanho();


//============================================
void Aniversariantes();
void Buscar();
int GerarCodigo();

#endif