#include "../Validation/validate.h"
#include "professor.h"
#include "Base.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

// Funções do Professor======================================

int InserirProfessor(int isFullP, Professor professores[]) {
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
      erro = ValidarSexo(professores[isFullP].sex) +
             ValidarCPF(professores[isFullP].cpf) +
             ValidarData(professores[isFullP].dataBirth.ano,
                         professores[isFullP].dataBirth.mes,
                         professores[isFullP].dataBirth.dia);
    } while (erro); 
    professores[isFullP].matricula = GerarCodigo();
    puts("Professor matriculado com sucesso!!!");
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

int ExcluirProfessor(int isFullP, Professor professores[]) {
  int e, j, i, voltar, code, c = 1;
  if (isFullP == 0) {
    puts("A lista de professores esta vazia");
  } else {
    puts("================PROFESSOR=================");
    printf("Digite a matricula do professor que deseja excluir: ");
    scanf("%d", &code);
    for (e = 0; e < isFullP; e++) {
      if (code == professores[e].matricula) {
        c = 0;
        for (j = e; j < isFullP - 1; j++) {
          for (i = 0; professores[j].name[i] != '\0' ||
                      professores[j + 1].name[i] != '\0';
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
          for (i = 0; professores[j].cpf[i] != '\0' ||
                      professores[j + 1].cpf[i] != '\0';
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
        puts("Professor excluido com sucesso!!");
      }
    }
    if (c) {
      puts("Matricula nao encontrada");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void AtualizarProfessor(int isFullP, Professor professores[]) {
  int a, i, voltar, erro, c = 1, code;
  if (isFullP == 0) {
    puts("A lista de professores esta vazia");
  } else {
    puts("================PROFESSORES=================");
    printf("Digite a posicao do Professor que deseja atualizar: ");
    scanf("%d", &code);
    for (a = 0; a < isFullP; a++) {
      if (code == professores[a].matricula) {
        c = 0;
        do {
          puts("=======================================");
          puts("===========Atualizar Professor=========");
          puts("=======================================");
          printf("Nome do Professor: ");
          getchar();
          fgets(professores[a].name, 50, stdin);
          size_t ln = strlen(professores[a].name) - 1;
          if (professores[a].name[ln] == '\n')
            professores[a].name[ln] = '\0';
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
          erro = ValidarCPF(professores[a].cpf) +
                 ValidarSexo(professores[a].sex) +
                 ValidarData(professores[a].dataBirth.ano,
                             professores[a].dataBirth.mes,
                             professores[a].dataBirth.dia);
        } while (erro);
        puts("Professor atualizado com sucesso!!");
      }
    }
    if (c) {
      puts("Matricula nao encontrada");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ListarProfessor(int isFullP, Professor professores[]) {
  int i, voltar;
  if (isFullP == 0) {
    puts("Sem professor matriculados");
  } else {
    system("clear");
    for (i = 0; i < isFullP; i++) {
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

void ListarProfessorPorSexo(int isFullP, Professor professores[]) {
  int i, voltar;
  if (isFullP == 0) {
    puts("Lista de professores vazia");
  } else {
    puts("======LISTAR PROFESSORES POR SEXO======");
    for (i = 0; i < isFullP; i++) {
      if (professores[i].sex == 'F' || professores[i].sex == 'f') {
        printf("%s, %c\n", professores[i].name, professores[i].sex);
      }
    }
    for (i = 0; i < isFullP; i++) {
      if (professores[i].sex == 'M' || professores[i].sex == 'm') {
        printf("%s, %c\n", professores[i].name, professores[i].sex);
      }
    }
    puts("=================================");
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ListarProfessorPorOrdemAlfabetico(int isFullP, Professor professores[]) {
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

void ListarProfessorPorOrdemNascimento(int isFullP, Professor professores[]) {
  char ProfeNome[TAM][50];
  char auxNome[50];
  Data data[TAM];
  Data auxData;
  int c, j, k, i, voltar;

  if (isFullP == 0) {
    puts("Sem professores matriculados");
  } else {
    for (c = 0; c < isFullP; c++) {
      for (i = 0; professores[c].name[i] != '\0'; i++) {
        ProfeNome[c][i] = professores[c].name[i];
      }
      ProfeNome[c][i] = '\0';
    }

    for (c = 0; c < TAM; c++) {
      data[c].ano = professores[c].dataBirth.ano;
      data[c].dia = professores[c].dataBirth.dia;
      data[c].mes = professores[c].dataBirth.mes;
    }

    for (c = 0; c < isFullP - 1; c++) {
      for (j = c + 1; j < isFullP; j++) {
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

          for (k = 0; ProfeNome[c][k] != '\0'; k++) {
            auxNome[k] = ProfeNome[c][k];
          }
          auxNome[k] = '\0';
          for (k = 0; ProfeNome[j][k] != '\0'; k++) {
            ProfeNome[c][k] = ProfeNome[j][k];
          }
          ProfeNome[c][k] = '\0';
          for (k = 0; auxNome[k] != '\0'; k++) {
            ProfeNome[j][k] = auxNome[k];
          }
          ProfeNome[j][k] = '\0';
        }
      }
    }
    for (c = 0; c < isFullP; c++) {
      printf("%s, %d/%d/%d\n", ProfeNome[c], data[c].dia, data[c].mes,
             data[c].ano);
    }
  }

  puts("=================================");
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}