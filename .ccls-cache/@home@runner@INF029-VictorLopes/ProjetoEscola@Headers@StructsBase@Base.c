#include "aluno.h"
#include "disciplina.h"
#include "professor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

    // Por ainda não entender em sua totalidade a modularizaçõa e a
    // transferencência de dados entre arquivos em c, acabei optando em deixar
    // todas as structs no mesmo arquivo para não gerar erros, mas tentei
    // separar e organizar até onde eu consigo.

    int isFullA = 0;
Aluno aluno[TAM];

int isFullD = 0;
Disciplinas disciplinas[TAM];
void IniciarTamanho();

int isFullP = 0;
Professor professores[TAM];

int ValidarData(int ano, int mes, int dia);
int ValidarMatricula(int matricula, int limite);
int ValidarCPF(char cpf[]);

// Funções do Aluno======================================

void InserirAluno() {
  int voltar;

  if (isFullA != TAM) {
    int error;
    system("clear");
    do {
      printf("====================================\n");
      printf("===========MATRICULAR ALUNO=========\n");
      printf("====================================\n");
      printf("Nome do aluno: ");
      getchar();
      fgets(aluno[isFullA].name, 50, stdin);
      size_t ln = strlen(aluno[isFullA].name) - 1;
      if (aluno[isFullA].name[ln] == '\n')
        aluno[isFullA].name[ln] = '\0';
      printf("Numero de matricula: ");
      scanf("%d", &aluno[isFullA].matricula);
      getchar();
      printf("Sexo do aluno [M/F]: ");
      aluno[isFullA].sex = getchar();
      getchar();
      printf("CPF do aluno: ");
      fgets(aluno[isFullA].cpf, 15, stdin);
      ln = strlen(aluno[isFullA].cpf) - 1;
      if (aluno[isFullA].cpf[ln] == '\n')
        aluno[isFullA].cpf[ln] = '\0';
      printf("Data de nascimento dd MM AAAA: ");
      scanf("%d%d%d", &aluno[isFullA].dataBirth.dia,
            &aluno[isFullA].dataBirth.mes, &aluno[isFullA].dataBirth.ano);
      error = ValidarMatricula(aluno[isFullA].matricula, isFullA) +
              ValidarCPF(aluno[isFullA].cpf) +
              ValidarData(aluno[isFullA].dataBirth.ano,
                          aluno[isFullA].dataBirth.mes,
                          aluno[isFullA].dataBirth.dia);
    } while (error != 3);
    isFullA++;
    aluno[isFullA].QuantDisc++;
    puts("Aluno matriculado com sucesso!!!");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    printf("\nLista esta cheia\n");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void ExcluirAluno() {
  int e, j, i, voltar;
  if (isFullA == 0) {
    puts("A lista nao possui alunos matriculados");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    system("clear");
    printf("\n================ALUNOS=================\n");
    for (i = 0; i < isFullA; i++) {
      fflush(stdin);
      printf("%d  Nome: %s, %d\n", i, aluno[i].name, aluno[i].matricula);
    }
    printf("\n=======================================\n");
    printf("Digite a posicao do Aluno que deseja excluir: ");
    scanf("%d", &e);
    for (j = e; j < isFullA - 1; j++) {
      for (i = 0; aluno[j].name[i] != '\0' || aluno[j + 1].name[i] != '\0';
           i++) {
        aluno[j].name[i] = aluno[j + 1].name[i];
      }
      aluno[j].name[i] = '\0';
    }

    for (j = e; j < isFullA - 1; j++) {
      aluno[j].matricula = aluno[j + 1].matricula;
    }
    for (j = e; j < isFullA - 1; j++) {
      aluno[j].sex = aluno[j + 1].sex;
    }
    for (j = e; j < isFullA - 1; j++) {
      for (i = 0; aluno[j].cpf[i] != '\0' || aluno[j + 1].cpf[i] != '\0'; i++) {
        aluno[j].cpf[i] = aluno[j + 1].cpf[i];
      }
      aluno[j].cpf[i] = '\0';
    }
    for (j = e; j < isFullA - 1; j++) {
      aluno[j].dataBirth.dia = aluno[j + 1].dataBirth.dia;
      aluno[j].dataBirth.mes = aluno[j + 1].dataBirth.mes;
      aluno[j].dataBirth.ano = aluno[j + 1].dataBirth.ano;
    }
    isFullA--;
    puts("Aluno excluido com sucesso!!");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}
void AtualizarAluno() {
  int a, i, voltar, erro;
  if (isFullA == 0) {
    puts("nao ha alunos matriculados\n");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    system("clear");
    do {
      printf("\n================ALUNOS=================\n");
      for (i = 0; i < isFullA; i++) {
        fflush(stdin);
        printf("%d  Nome: %s, %d\n", i, aluno[i].name, aluno[i].matricula);
      }
      printf("\n=======================================\n");
      printf("Digite a posicao do Aluno que deseja atualizar: ");
      scanf("%d", &a);
      printf("====================================\n");
      printf("===========Atualizar ALUNO=========\n");
      printf("====================================\n");
      printf("Nome do aluno: ");
      getchar();
      fgets(aluno[a].name, 50, stdin);
      size_t ln = strlen(aluno[a].name) - 1;
      if (aluno[a].name[ln] == '\n')
        aluno[a].name[ln] = '\0';
      printf("Numero de matricula: ");
      scanf("%d", &aluno[a].matricula);
      getchar();
      printf("Sexo do aluno [M/F]: ");
      aluno[a].sex = getchar();
      getchar();
      printf("CPF do aluno: ");
      fgets(aluno[a].cpf, 15, stdin);
      ln = strlen(aluno[a].cpf) - 1;
      if (aluno[a].cpf[ln] == '\n')
        aluno[a].cpf[ln] = '\0';
      printf("Data de nascimento dd MM AAAA: ");
      scanf("%d%d%d", &aluno[a].dataBirth.dia, &aluno[a].dataBirth.mes,
            &aluno[a].dataBirth.ano);
      erro = ValidarMatricula(aluno[a].matricula, isFullA) +
             ValidarCPF(aluno[a].cpf) +
             ValidarData(aluno[a].dataBirth.ano, aluno[a].dataBirth.mes,
                         aluno[a].dataBirth.dia);
    } while (erro != 3);
    puts("Aluno atualizado com sucesso!!");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void ListarAluno() {
  int i, voltar;
  if (isFullA == 0) {
    printf("\nSem alunos matriculados\n");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    system("clear");
    puts("==============LISTA DE ALUNOS==========");
    for (i = 0; i < isFullA; i++) {
      printf("Nome: %s\n", aluno[i].name);
      printf("Matricula: %d\n", aluno[i].matricula);
      printf("Sexo: %c\n", aluno[i].sex);
      printf("CPF: %s\n", aluno[i].cpf);
      printf("Data de Nascimento: %d/%d/%d\n", aluno[i].dataBirth.dia,
             aluno[i].dataBirth.mes, aluno[i].dataBirth.ano);
      puts("____________________________________");
    }
    puts("======================================");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void ListarAlunoPorSexo() {
  int i, voltar;
  if (isFullA == 0) {
    puts("Lista de alunos vazia");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    puts("======LISTAR ALUNO POR SEXO======");
    for (i = 0; i < TAM; i++) {
      if (aluno[i].sex == 'M') {
        printf("%s, %c\n", aluno[i].name, aluno[i].sex);
      }
    }
    for (i = 0; i < TAM; i++) {
      if (aluno[i].sex == 'F') {
        printf("%s, %c\n", aluno[i].name, aluno[i].sex);
      }
    }
    puts("=================================");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void Aniversariantes() {
  int mm, i, voltar, e = 1;
  system("clear");
  printf("Digite o mes mm: ");
  scanf("%d", &mm);
  puts("=======ANIVERSARIANTES DO MES=======");
  for (i = 0; i < TAM; i++) {
    if (aluno[i].dataBirth.mes == mm) {
      printf("ALUNO: %s, %d/%d/%d", aluno[i].name, aluno[i].dataBirth.dia,
             aluno[i].dataBirth.mes, aluno[i].dataBirth.ano);
      e = 0;
    }
  }
  for (i = 0; i < TAM; i++) {
    if (professores[i].dataBirth.mes == mm) {
      printf("PROFESSOR: %s, %d/%d/%d", professores[i].name,
             professores[i].dataBirth.dia, professores[i].dataBirth.mes,
             professores[i].dataBirth.ano);
      e = 0;
    }
  }
  if (e) {
    puts("Nao ha nenhuma pessoa que faz aniversario deste mes");
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}
void Buscar() {
  char busca[50];
  int voltar, c, i, j, a, l;
  printf("Digite a string de busca:");
  getchar();
  fgets(busca, 50, stdin);
  size_t ln = strlen(busca) - 1;
  if (busca[ln] == '\n') {
    busca[ln] = '\0';
  }
  if (strlen(busca) >= 3) {
    for (i = 0; i < isFullA; i++) {
      for (c = 0; aluno[i].name[c] != '\0'; c++) {
        if (busca[0] == aluno[i].name[c]) {
          for (j = c + 1, a = 1, l = 1; a < strlen(busca); j++, a++) {
            if (busca[a] == aluno[i].name[j])
              l++;
            else
              break;
          }
          if (strlen(busca) == l) {
            printf("%s, aluno\n", aluno[i].name);
          }
        }
      }
    }
    for (i = 0; i < isFullP; i++) {
      for (c = 0, a = 1; aluno[i].name[c] != '\0'; c++) {
        if (busca[0] == professores[i].name[c]) {
          for (j = c + 1, a = 1, l = 1; a < strlen(busca); j++, a++) {
            if (busca[j] == professores[i].name[a])
              l++;
            else
              break;
          }
          if (strlen(busca) == l) {
            printf("%s, professor\n", professores[i].name);
          }
        }
      }
    }
  } else {
    puts("String muito pequena");
  }
  puts("=================================");
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}
void ListarAlunoPorOrdemAlfabetico() {
  int c, j, i, k, voltar, t;
  char ordenadoAluno[TAM][50];
  char aux[50];

  if (isFullA == 0) {
    puts("Lista de Alunos vazia");

  } else {
    for (c = 0; c < isFullA; c++) {
      for (i = 0; aluno[c].name[i] != '\0'; i++) {
        ordenadoAluno[c][i] = aluno[c].name[i];
      }
      ordenadoAluno[c][i] = '\0';
    }
    for (c = 0; c < isFullA - 1; c++) {
      for (j = c + 1; j < isFullA; j++) {
        i = 0;
        while (ordenadoAluno[c][i] == ordenadoAluno[j][i] &&
               ordenadoAluno[c][i] != '\0')
          i++;
        if (ordenadoAluno[c][i] - ordenadoAluno[j][i] > 0) {
          for (k = 0; ordenadoAluno[c][k] != '\0'; k++) {
            aux[k] = ordenadoAluno[c][k];
          }
          aux[k] = '\0';
          for (k = 0; ordenadoAluno[j][k] != '\0'; k++) {
            ordenadoAluno[c][k] = ordenadoAluno[j][k];
          }
          ordenadoAluno[c][k] = '\0';
          for (k = 0; aux[k] != '\0'; k++) {
            ordenadoAluno[j][k] = aux[k];
          }
          ordenadoAluno[j][k] = '\0';
        }
      }
    }
    for (c = 0; c < isFullA; c++) {
      printf("%s\n", ordenadoAluno[c]);
    }
  }
  puts("=================================");
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

// Funções da Disciplina======================================

void InserirDisciplina() {
  int voltar, erro;
  system("clear");
  if (isFullD != TAM) {
    printf("====================================\n");
    printf("========MATRICULAR DISCIPLINA=======\n");
    printf("====================================\n");
    do {
      printf("Nome da disciplina: ");
      getchar();
      fgets(disciplinas[isFullD].name, 50, stdin);
      size_t ln = strlen(disciplinas[isFullD].name) - 1;
      if (disciplinas[isFullD].name[ln] == '\n')
        disciplinas[isFullD].name[ln] = '\0';
      printf("Codigo da disciplina: ");
      scanf("%d", &disciplinas[isFullD].codigo);
      getchar();
      printf("Semestre da disciplina: ");
      fgets(disciplinas[isFullD].semestre, 20, stdin);
      ln = strlen(disciplinas[isFullD].semestre) - 1;
      if (disciplinas[isFullD].semestre[ln] == '\n')
        disciplinas[isFullD].semestre[ln] = '\0';
      printf("Professor da disciplina: ");
      fgets(disciplinas[isFullD].professor, 50, stdin);
      ln = strlen(disciplinas[isFullD].professor) - 1;
      if (disciplinas[isFullD].professor[ln] == '\n')
        disciplinas[isFullD].professor[ln] = '\0';
      erro = ValidarMatricula(disciplinas[isFullD].codigo, isFullD);
    } while (!erro);
    isFullD++;
    puts("Disciplina cadastrada com sucesso!!");
  } else {
    printf("\nLista esta cheia\n");
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ExcluirDisciplina() {
  int e, j, i, voltar;
  system("clear");
  if (isFullD == 0) {
    puts("A lista de disciplinas esta vazia");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    printf("\n================DISCIPLINAS=================\n");
    for (i = 0; i < isFullD; i++) {
      fflush(stdin);
      printf("%d  Nome: %s, %d\n", i, disciplinas[i].name,
             disciplinas[i].codigo);
    }
    printf("\n=======================================\n");
    printf("Digite a posicao da Disciplina que deseja excluir: ");
    scanf("%d", &e);

    for (j = e; j < isFullD - 1; j++) {
      for (i = 0;
           disciplinas[j].name[i] != '\0' || disciplinas[j + 1].name[i] != '\0';
           i++) {
        disciplinas[j].name[i] = disciplinas[j + 1].name[i];
      }
      disciplinas[j].name[i] = '\0';
    }
    for (j = e; j < isFullD - 1; j++) {
      for (i = 0; disciplinas[j].professor[i] != '\0' ||
                  disciplinas[j + 1].professor[i] != '\0';
           i++) {
        disciplinas[j].professor[i] = disciplinas[j + 1].professor[i];
      }
      disciplinas[j].professor[i] = '\0';
    }
    for (j = e; j < isFullD - 1; j++) {
      for (i = 0; disciplinas[j].semestre[i] != '\0' ||
                  disciplinas[j + 1].semestre[i] != '\0';
           i++) {
        disciplinas[j].semestre[i] = disciplinas[j + 1].semestre[i];
      }
      disciplinas[j].semestre[i] = '\0';
    }
    for (j = e; j < isFullD - 1; j++) {
      disciplinas[j].codigo = disciplinas[j + 1].codigo;
    }
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void AtualizarDisciplina() {
  int a, i, voltar, erro;
  system("clear");
  if (isFullD == 0) {
    puts("A lista de disciplinas esta vazia");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    do {
      printf("\n================DISCIPLINAS=================\n");
      for (i = 0; i < isFullD; i++) {
        fflush(stdin);
        printf("%d  Nome: %s, %d\n", i, disciplinas[i].name,
               disciplinas[i].codigo);
      }
      printf("\n=======================================\n");
      printf("Digite a posicao do disciplinas que deseja atualizar: ");
      scanf("%d", &a);
      printf("====================================\n");
      printf("======Atualizar DISCIPLINAS=========\n");
      printf("====================================\n");
      printf("Nome da disciplina: ");
      getchar();
      fgets(disciplinas[a].name, 50, stdin);
      size_t ln = strlen(disciplinas[isFullD].name) - 1;
      if (disciplinas[isFullD].name[ln] == '\n')
        disciplinas[isFullD].name[ln] = '\0';
      printf("Codigo da disciplina: ");
      scanf("%d", &disciplinas[a].codigo);
      getchar();
      printf("Professor da Disciplina:");
      fgets(disciplinas[a].professor, 50, stdin);
      ln = strlen(disciplinas[a].professor) - 1;
      if (disciplinas[a].professor[ln] == '\n')
        disciplinas[a].professor[ln] = '\0';
      printf("Semestre da Disciplina:");
      fgets(disciplinas[a].semestre, 50, stdin);
      ln = strlen(disciplinas[a].semestre) - 1;
      if (disciplinas[a].semestre[ln] == '\n')
        disciplinas[a].semestre[ln] = '\0';
      erro = ValidarMatricula(disciplinas[isFullD].codigo, isFullD);
    } while (!erro);
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void ListarDisciplina() {
  int i, voltar;
  system("clear");
  if (isFullD == 0) {
    printf("\nSem disciplinas matriculadas\n");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    for (i = 0; i < isFullD; i++) {
      fflush(stdin);
      printf("\n==========================================\n");
      printf("Nome: %s\n", disciplinas[i].name);
      printf("Codigo: %d\n", disciplinas[i].codigo);
      printf("Semestre: %s", disciplinas[i].semestre);
      printf("Professor: %s", disciplinas[i].professor);
      printf("\n==========================================\n");
    }
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void InserirAlunoNaDisciplina() {
  int d, i, a, voltar, j;
  system("clear");
  if (isFullD == 0) {
    printf("\nSem disciplinas matriculadas\n");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    printf("\n================DISCIPLINAS=================\n");
    for (i = 0; i < isFullD; i++) {
      fflush(stdin);
      printf("%d  Nome: %s, %d\n", i, disciplinas[i].name,
             disciplinas[i].codigo);
    }
    printf("\n=======================================\n");
    printf("Digite a posicao do disciplinas que deseja: ");
    scanf("%d", &d);
    if (isFullA == 0) {
      puts("Nao ha alunos matriculados");
    } else {
      printf("\n================ALUNOS=================\n");
      for (i = 0; i < isFullA; i++) {
        fflush(stdin);
        printf("%d  Nome: %s, %d\n", i, aluno[i].name, aluno[i].matricula);
      }
      printf("\n=======================================\n");
      printf("Digite a posicao do Aluno que deseja: ");
      scanf("%d", &a);
      for (i = 0; aluno[j].name[i] != '\0'; i++) {
        disciplinas[d].ListAluno[disciplinas[d].QuantAluno].name[i] =
            aluno[a].name[i];
      }
      disciplinas[d].ListAluno[disciplinas[d].QuantAluno].name[i] = '\0';
      disciplinas[d].ListAluno[disciplinas[d].QuantAluno].matricula =
          aluno[a].matricula;
      disciplinas[d].ListAluno[disciplinas[d].QuantAluno].sex = aluno[a].sex;
      for (i = 0; aluno[j].cpf[i] != '\0'; i++) {
        disciplinas[d].ListAluno[disciplinas[d].QuantAluno].cpf[i] =
            aluno[a].cpf[i];
      }
      disciplinas[d].ListAluno[disciplinas[d].QuantAluno].cpf[i] = '\0';

      disciplinas[d].ListAluno[disciplinas[d].QuantAluno].dataBirth.dia =
          aluno[a].dataBirth.dia;
      disciplinas[d].ListAluno[disciplinas[d].QuantAluno].dataBirth.mes =
          aluno[a].dataBirth.mes;
      disciplinas[d].ListAluno[disciplinas[d].QuantAluno].dataBirth.ano =
          aluno[a].dataBirth.ano;
    }
    disciplinas[d].QuantAluno++;
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void ExcluirAlunoDaDisciplina() {
  int e, j, i, d, voltar;
  system("clear");
  if (isFullD == 0) {
    printf("\nSem disciplinas matriculadas\n");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    printf("\n================DISCIPLINAS=================\n");
    for (i = 0; i < isFullD; i++) {
      fflush(stdin);
      printf("%d  Nome: %s, %d\n", i, disciplinas[i].name,
             disciplinas[i].codigo);
    }
    printf("\n=======================================\n");
    printf("Digite a posicao do disciplinas que deseja: ");
    scanf("%d", &d);
    if (disciplinas[d].QuantAluno == 0) {
      puts("Sem alunos matriculados");
    } else {
      for (j = 0; j < disciplinas[d].QuantAluno; j++) {
        printf("%d Nome: %s, %d\n", j, disciplinas[d].ListAluno[j].name,
               disciplinas[d].ListAluno[j].matricula);
        puts("________________________________________");
      }
      printf("Digite a posicao do Aluno que deseja excluir: ");
      scanf("%d", &e);
      for (j = e; j < disciplinas[d].QuantAluno - 1; j++) {
        for (i = 0; disciplinas[d].ListAluno[j].name[i] != '\0' ||
                    disciplinas[d].ListAluno[j + 1].name[i] != '\0';
             i++) {
          disciplinas[d].ListAluno[j].name[i] =
              disciplinas[d].ListAluno[j + 1].name[i];
        }
        disciplinas[d].ListAluno[j].name[i] = '\0';
      }

      for (j = e; j < disciplinas[d].QuantAluno - 1; j++) {
        disciplinas[d].ListAluno[j].matricula =
            disciplinas[d].ListAluno[j + 1].matricula;
      }
      for (j = e; j < isFullA - 1; j++) {
        disciplinas[d].ListAluno[j].sex = disciplinas[d].ListAluno[j + 1].sex;
      }
      for (j = e; j < isFullA - 1; j++) {
        for (i = 0; disciplinas[d].ListAluno[j].cpf[i] != '\0' ||
                    disciplinas[d].ListAluno[j + 1].cpf[i] != '\0';
             i++) {
          disciplinas[d].ListAluno[j].cpf[i] =
              disciplinas[d].ListAluno[j + 1].cpf[i];
        }
        disciplinas[d].ListAluno[j].cpf[i] = '\0';
      }
      for (j = e; j < disciplinas[d].QuantAluno - 1; j++) {
        disciplinas[d].ListAluno[j].dataBirth.dia =
            disciplinas[d].ListAluno[j + 1].dataBirth.dia;
        disciplinas[d].ListAluno[j].dataBirth.mes =
            disciplinas[d].ListAluno[j + 1].dataBirth.mes;
        disciplinas[d].ListAluno[j].dataBirth.ano =
            disciplinas[d].ListAluno[j + 1].dataBirth.ano;
      }
      disciplinas[d].QuantAluno--;
    }
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void ListarDisciplinaComAlunos() {
  int i, voltar, j;
  system("clear");
  if (isFullD == 0) {
    puts("Sem disciplinas matriculadas");
  } else {
    printf("\n==========================================\n");
    for (i = 0; i < isFullD; i++) {
      fflush(stdin);
      printf("Nome: %s\n", disciplinas[i].name);
      printf("Codigo: %d\n", disciplinas[i].codigo);
      printf("Semestre: %s", disciplinas[i].semestre);
      printf("Professor: %s", disciplinas[i].professor);
      puts("=========ALUNOS==============================");
      if (disciplinas[i].QuantAluno == 0) {
        printf("Sem alunos matriculados");
      } else {
        for (j = 0; j < disciplinas[i].QuantAluno; j++) {
          printf("Nome: %s", disciplinas[i].ListAluno[j].name);
          printf("Matricula: %d\n", disciplinas[i].ListAluno[j].matricula);
          printf("Sexo: %c\n", disciplinas[i].ListAluno[j].sex);
          printf("CPF: %s\n", disciplinas[i].ListAluno[j].cpf);
          printf("Data de Nascimento: %d/%d/%d\n",
                 disciplinas[i].ListAluno[j].dataBirth.dia,
                 disciplinas[i].ListAluno[j].dataBirth.mes,
                 disciplinas[i].ListAluno[j].dataBirth.ano);
          puts("________________________________________");
        }
      }
      printf("\n==========================================\n");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}
void IniciarTamanho() {
  int i;
  for (i = 0; i < TAM; i++) {
    disciplinas[i].QuantAluno = 0;
  }
  for (i = 0; i < TAM; i++) {
    aluno[i].QuantDisc = 0;
  }
}

// Funções do Professor======================================

void InserirProfessor() {
  int voltar, erro;
  if (isFullP != TAM) {
    system("clear");

    do {
      printf("====================================\n");
      printf("========MATRICULAR PROFESSOR========\n");
      printf("====================================\n");
      printf("Nome do Professor: ");
      getchar();
      fgets(professores[isFullP].name, 50, stdin);
      size_t ln = strlen(professores[isFullP].name) - 1;
      if (professores[isFullP].name[ln] == '\n')
        professores[isFullP].name[ln] = '\0';
      printf("Numero de matricula: ");
      scanf("%d", &professores[isFullP].matricula);
      getchar();
      printf("Sexo do professor [M/F]: ");
      professores[isFullP].sex = getchar();
      getchar();
      printf("CPF do professor: ");
      fgets(professores[isFullP].cpf, 15, stdin);
      ln = strlen(professores[isFullP].cpf) - 1;
      if (professores[isFullP].cpf[ln] == '\n')
        professores[isFullP].cpf[ln] = '\0';
      printf("Data de nascimento dd MM AAAA: ");
      scanf("%d%d%d", &professores[isFullP].dataBirth.dia,
            &professores[isFullP].dataBirth.mes,
            &professores[isFullP].dataBirth.ano);
      erro = ValidarMatricula(professores[isFullP].matricula, isFullP) +
             ValidarCPF(professores[isFullP].cpf) +
             ValidarData(professores[isFullP].dataBirth.ano,
                         professores[isFullP].dataBirth.mes,
                         professores[isFullP].dataBirth.dia);
    } while (erro != 3);

    isFullP++;
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    printf("\nLista esta cheia\n");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void ExcluirProfessor() {
  int e, j, i, voltar;
  if (isFullP == 0) {
    printf("A lista de professores esta vazia\n");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    printf("\n================PROFESSOR=================\n");
    for (i = 0; i < isFullP; i++) {
      fflush(stdin);
      printf("%d  Nome: %s, %d\n", i, professores[i].name,
             professores[i].matricula);
    }
    printf("\n=======================================\n");
    printf("Digite a posicao do professor que deseja excluir: ");
    scanf("%d", &e);
    for (j = e; j < isFullP - 1; j++) {
      for (i = 0;
           professores[j].name[i] != '\0' || professores[j + 1].name[i] != '\0';
           i++) {
        professores[j].name[i] = professores[j + 1].name[i];
      }
      professores[j].name[i] = '\0';
    }

    for (j = e; j < isFullP - 1; j++) {
      professores[j].matricula = professores[j + 1].matricula;
    }
    for (j = e; j < isFullP - 1; j++) {
      professores[j].sex = professores[j + 1].sex;
    }
    for (j = e; j < isFullP - 1; j++) {
      for (i = 0;
           professores[j].cpf[i] != '\0' || professores[j + 1].cpf[i] != '\0';
           i++) {
        professores[j].cpf[i] = professores[j + 1].cpf[i];
      }
      professores[j].cpf[i] = '\0';
    }
    for (j = e; j < isFullP - 1; j++) {
      professores[j].dataBirth.dia = professores[j + 1].dataBirth.dia;
      professores[j].dataBirth.mes = professores[j + 1].dataBirth.mes;
      professores[j].dataBirth.ano = professores[j + 1].dataBirth.ano;
    }
    isFullP--;
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void AtualizarProfessor() {
  int a, i, voltar, erro;
  if (isFullP == 0) {
    printf("A lista de professores esta vazia\n");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  } else {
    do {
      printf("\n================PROFESSORES=================\n");
      for (i = 0; i < isFullP; i++) {
        fflush(stdin);
        printf("%d  Nome: %s, %d\n", i, professores[i].name,
               professores[i].matricula);
      }
      printf("\n=======================================\n");
      printf("Digite a posicao do Professor que deseja atualizar: ");
      scanf("%d", &a);
      system("clear");
      printf("====================================\n");
      printf("===========Atualizar Professor=========\n");
      printf("====================================\n");
      printf("Nome do Professor: ");
      getchar();
      fgets(professores[a].name, 50, stdin);
      size_t ln = strlen(professores[a].name) - 1;
      if (professores[isFullP].name[ln] == '\n')
        professores[isFullP].name[ln] = '\0';
      printf("Numero de matricula: ");
      scanf("%d", &professores[a].matricula);
      getchar();
      printf("Sexo do Professor [M/F]: ");
      professores[a].sex = getchar();
      getchar();
      printf("CPF do Professor: ");
      fgets(professores[a].cpf, 15, stdin);
      ln = strlen(professores[a].cpf) - 1;
      if (professores[a].cpf[ln] == '\n')
        professores[a].cpf[ln] = '\0';
      printf("Data de nascimento dd MM AAAA: ");
      scanf("%d%d%d", &professores[a].dataBirth.dia,
            &professores[a].dataBirth.mes, &professores[a].dataBirth.ano);
      erro = ValidarMatricula(professores[a].matricula, isFullP) +
             ValidarCPF(professores[a].cpf) +
             ValidarData(professores[a].dataBirth.ano,
                         professores[a].dataBirth.mes,
                         professores[a].dataBirth.dia);
    } while (erro != 3);
    puts("==[1] Voltar");
    scanf("%d", &voltar);
  }
}

void ListarProfessor() {
  int i, voltar;
  if (isFullP == 0) {
    puts("Sem professor matriculados");
  } else {
    for (i = 0; i < isFullP; i++) {
      fflush(stdin);
      printf("\n==========================================\n");
      printf("Nome: %s\n", professores[i].name);
      printf("Matricula: %d\n", professores[i].matricula);
      printf("Sexo: %c\n", professores[i].sex);
      printf("CPF: %s\n", professores[i].cpf);
      printf("Data de Nascimento: %d/%d/%d\n", professores[i].dataBirth.dia,
             professores[i].dataBirth.mes, professores[i].dataBirth.ano);
      printf("\n==========================================\n");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ListarProfessorPorSexo() {
  int i, voltar;
  if (isFullP == 0) {
    puts("Lista de professores vazia");
  } else {
    puts("======LISTAR PROFESSORES POR SEXO======");
    for (i = 0; i < TAM; i++) {
      if (professores[i].sex == 'M') {
        printf("%s, %c\n", professores[i].name, professores[i].sex);
      }
    }
    for (i = 0; i < TAM; i++) {
      if (professores[i].sex == 'F') {
        printf("%s, %c\n", professores[i].name, professores[i].sex);
      }
    }
    puts("=================================");
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ListarProfessorPorOrdemAlfabetico() {
  int c, j, i, k, voltar;
  char ordenadoProfessores[TAM][50];
  char aux[50];

  if (isFullP == 0) {
    puts("Sem Professores matriculados");
  } else {
    for (c = 0; c < isFullP; c++) {
      for (i = 0; professores[c].name[i] != '\0'; i++) {
        ordenadoProfessores[c][i] = professores[c].name[i];
      }
      ordenadoProfessores[c][i] = '\0';
    }
    for (c = 0; c < isFullP - 1; c++) {
      for (j = c + 1; j < isFullP; j++) {
        i = 0;
        while (ordenadoProfessores[c][i] == ordenadoProfessores[j][i] &&
               ordenadoProfessores[c][i] != '\0')
          i++;
        if (ordenadoProfessores[c][i] - ordenadoProfessores[j][i] > 0) {
          for (k = 0; ordenadoProfessores[c][k] != '\0'; k++) {
            aux[k] = ordenadoProfessores[c][k];
          }
          aux[k] = '\0';
          for (k = 0; ordenadoProfessores[j][k] != '\0'; k++) {
            ordenadoProfessores[c][k] = ordenadoProfessores[j][k];
          }
          ordenadoProfessores[c][k] = '\0';
          for (k = 0; aux[k] != '\0'; k++) {
            ordenadoProfessores[j][k] = aux[k];
          }
          ordenadoProfessores[j][k] = '\0';
        }
      }
    }
    for (c = 0; c < isFullP; c++) {
      printf("%s\n", ordenadoProfessores[c]);
    }
  }
  puts("=================================");
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

//VALIDAÇÔES ==============================================

int ValidarData(int ano, int mes, int dia) {
  if ((dia > 31 || dia < 0) || (mes > 12 || mes < 0) || ano < 0) {
    puts("ERRO : DATA INVALIDA");
    return 0;
  }
  return 1;
}

int ValidarMatricula(int matricula, int limite) {
  int i;
  if (matricula < 0) {
    puts("Numero de matricula invalida");
    return 0;
  }
  for (i = 0; i < limite; i++) {
    if (aluno[i].matricula == matricula ||
        professores[i].matricula == matricula) {
      puts("Numero ja existente");
      return 0;
    }
  }
  return 1;
}

int ValidarCPF(char cpf[]) {
  if (strlen(cpf) != 14 || cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-') {
    puts("CPF no formato errado");
    return 0;
  }
  return 1;
}