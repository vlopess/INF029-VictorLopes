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

int InserirAluno(int isFullA, Aluno aluno[]);
int ExcluirAluno(int isFullA, Aluno aluno[]);
void AtualizarAluno(int isFullA, Aluno aluno[]);
void ListarAluno(int isFullA, Aluno aluno[]);
void ListarAlunoPorSexo(int isFullA, Aluno aluno[]);
void ListarAlunoPorOrdemAlfabetico(int isFullA, Aluno aluno[]);
void ListarAlunoPorOrdemNascimento(int isFullA, Aluno aluno[]);
void ListarAlunoComMenosDeTresDisciplinas(int isFullA, Aluno aluno[]);

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

//============================================

void Aniversariantes(int isFullA, Aluno aluno[], int isFullP, Professor professores[]);
void Buscar(int isFullA, Aluno aluno[], int isFullP, Professor professores[]);
int GerarCodigo();

//RELATORIOS==========================================

int ValidarData(int ano, int mes, int dia);
int ValidarCPF(char cpf[]);
int ValidarSexo(char sex);
int ValidarExistenciaProfessor(int matricula, int limite, Professor professores[]);

#endif