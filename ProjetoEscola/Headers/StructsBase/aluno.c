#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Validation/validate.h"
#include "Base.h"
#include "professor.h"


// Funções do Aluno======================================

int InserirAluno(int isFullA, Aluno aluno[]) {
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
      error = ValidarSexo(aluno[isFullA].sex) + ValidarCPF(aluno[isFullA].cpf) +
              ValidarData(aluno[isFullA].dataBirth.ano,
                          aluno[isFullA].dataBirth.mes,
                          aluno[isFullA].dataBirth.dia);
    } while (error);
    aluno[isFullA].matricula = GerarCodigo();
    aluno[isFullA].QuantDisc++;
    puts("Aluno matriculado com sucesso!!!");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
    return -1;
  } else {
    puts("Lista esta cheia");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
    return 0;
  }  
}

int ExcluirAluno(int isFullA, Aluno aluno[]) {
  int e, j, i, voltar, code, c = 1;
  if (isFullA == 0) {
    puts("A lista nao possui alunos matriculados");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
    return 0;
  } else {
    system("clear");
    puts("================ALUNOS=================");
    printf("Digite o numero de matricula do Aluno que deseja excluir: ");
    scanf("%d", &code);
    for (e = 0; e < isFullA; e++) {
      if (code == aluno[e].matricula) {
        c = 0;
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
          for (i = 0; aluno[j].cpf[i] != '\0' || aluno[j + 1].cpf[i] != '\0';
               i++) {
            aluno[j].cpf[i] = aluno[j + 1].cpf[i];
          }
          aluno[j].cpf[i] = '\0';
        }
        for (j = e; j < isFullA - 1; j++) {
          aluno[j].dataBirth.dia = aluno[j + 1].dataBirth.dia;
          aluno[j].dataBirth.mes = aluno[j + 1].dataBirth.mes;
          aluno[j].dataBirth.ano = aluno[j + 1].dataBirth.ano;
        } 
        puts("Aluno excluido com sucesso!!");
      }
    }
    if (c) {
      puts("Numero de matricula nao encontrado");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
  return -1;
}

void AtualizarAluno(int isFullA, Aluno aluno[]) {
  int a, i, voltar, erro, code, c = 1;
  if (isFullA == 0) {
    puts("nao ha alunos matriculados");
  } else {
    system("clear");
    puts("================ALUNOS=================");
    printf("Digite o numero de matricula do Aluno que deseja atualizar: ");
    scanf("%d", &code);
    for (a = 0; a < isFullA; a++) {
      if (code == aluno[a].matricula) {
        c = 0;
        do {
          printf("====================================\n");
          printf("===========Atualizar ALUNO=========\n");
          printf("====================================\n");
          printf("Nome do aluno: ");
          getchar();
          fgets(aluno[a].name, 50, stdin);
          size_t ln = strlen(aluno[a].name) - 1;
          if (aluno[a].name[ln] == '\n')
            aluno[a].name[ln] = '\0';
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
          erro = ValidarCPF(aluno[a].cpf) + ValidarSexo(aluno[a].sex) +
                 ValidarData(aluno[a].dataBirth.ano, aluno[a].dataBirth.mes,
                             aluno[a].dataBirth.dia);
        } while (erro);
        puts("Aluno atualizado com sucesso!!");
        break;
      }
    }
    if (c) {
      puts("Numero de matricula nao encontrado");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ListarAluno(int isFullA, Aluno aluno[]) {
  int i, voltar;
  if (isFullA == 0) {
    puts("Sem alunos matriculados");
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
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ListarAlunoPorSexo(int isFullA, Aluno aluno[]) {
  int i, voltar;
  if (isFullA == 0) {
    puts("Lista de alunos vazia");
  } else {
    puts("======LISTAR ALUNO POR SEXO======");
    for (i = 0; i < isFullA; i++) {
      if (aluno[i].sex == 'F' || aluno[i].sex == 'f') {
        printf("%s, %c\n", aluno[i].name, aluno[i].sex);
      }
    }
    for (i = 0; i < isFullA; i++) {
      if (aluno[i].sex == 'M' || aluno[i].sex == 'm') {
        printf("%s, %c\n", aluno[i].name, aluno[i].sex);
      }
    }
  }
  puts("=================================");
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ListarAlunoPorOrdemAlfabetico(int isFullA, Aluno aluno[]) {
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

void ListarAlunoPorOrdemNascimento(int isFullA, Aluno aluno[]) {
  char AlunoNome[TAM][50];
  char auxNome[50];
  Data data[TAM];
  Data auxData;
  int c, j, k, i, voltar;

  if (isFullA == 0) {
    puts("Sem alunos matriculados");
  } else {
    for (c = 0; c < isFullA; c++) {
      for (i = 0; aluno[c].name[i] != '\0'; i++) {
        AlunoNome[c][i] = aluno[c].name[i];
      }
      AlunoNome[c][i] = '\0';
    }

    for (c = 0; c < isFullA; c++) {
      data[c].ano = aluno[c].dataBirth.ano;
      data[c].dia = aluno[c].dataBirth.dia;
      data[c].mes = aluno[c].dataBirth.mes;
    }

    for (c = 0; c < isFullA - 1; c++) {
      for (j = c + 1; j < isFullA; j++) {
        if ((data[c].ano > data[j].ano) ||
            (data[c].ano == data[j].ano && data[c].mes > data[j].mes) ||
            (data[c].ano == data[j].ano && data[c].mes == data[j].mes &&
             data[c].dia > data[j].dia)) {
          auxData.ano = data[j].ano;
          auxData.mes = data[j].mes;
          auxData.dia = data[j].dia;

          data[j].ano = data[c].ano;
          data[j].mes = data[c].mes;
          data[j].dia = data[c].dia;

          data[c].ano = auxData.ano;
          data[c].mes = auxData.mes;
          data[c].dia = auxData.dia;

          for (k = 0; AlunoNome[c][k] != '\0'; k++) {
            auxNome[k] = AlunoNome[c][k];
          }
          auxNome[k] = '\0';
          for (k = 0; AlunoNome[j][k] != '\0'; k++) {
            AlunoNome[c][k] = AlunoNome[j][k];
          }
          AlunoNome[c][k] = '\0';
          for (k = 0; auxNome[k] != '\0'; k++) {
            AlunoNome[j][k] = auxNome[k];
          }
          AlunoNome[j][k] = '\0';
        }
      }
    }
    for (c = 0; c < isFullA; c++) {
      printf("%s, %d/%d/%d\n", AlunoNome[c], data[c].dia, data[c].mes,
             data[c].ano);
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ListarAlunoComMenosDeTresDisciplinas(int isFullA, Aluno aluno[]) {
  int i, voltar;
  if (isFullA == 0) {
    puts("Sem alunos matriculados");
  } else {
    system("clear");
    puts("==============LISTA DE ALUNOS==========");
    for (i = 0; i < isFullA; i++) {
      if (aluno[i].QuantDisc < 3) {
        printf("Nome: %s\n", aluno[i].name);
        printf("Matricula: %d\n", aluno[i].matricula);
        printf("Sexo: %c\n", aluno[i].sex);
        printf("CPF: %s\n", aluno[i].cpf);
        printf("Data de Nascimento: %d/%d/%d\n", aluno[i].dataBirth.dia,
               aluno[i].dataBirth.mes, aluno[i].dataBirth.ano);
        puts("____________________________________");
      }
    }
    puts("======================================");
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

