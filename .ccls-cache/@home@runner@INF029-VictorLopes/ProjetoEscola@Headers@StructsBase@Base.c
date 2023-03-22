#include "Base.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

int GerarCodigo() {
  static int count = 0;
  count++;
  return count;
}

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

// Funções da Disciplina======================================

int InserirDisciplina(int isFullP, int isFullD, Disciplinas disciplinas[], Professor professores[]) {
  int voltar, erro;
  system("clear");
  if (isFullD != TAM) {
    if (isFullP != 0) {

      puts("====================================");
      puts("========MATRICULAR DISCIPLINA=======");
      puts("====================================");
      do {
        printf("Nome da disciplina: ");
        getchar();
        fgets(disciplinas[isFullD].name, 50, stdin);
        size_t ln = strlen(disciplinas[isFullD].name) - 1;
        if (disciplinas[isFullD].name[ln] == '\n')
          disciplinas[isFullD].name[ln] = '\0';
        printf("Semestre da disciplina: ");
        fgets(disciplinas[isFullD].semestre, 20, stdin);
        ln = strlen(disciplinas[isFullD].semestre) - 1;
        if (disciplinas[isFullD].semestre[ln] == '\n')
          disciplinas[isFullD].semestre[ln] = '\0';
        printf("Numero de matricula do professor da disciplina: ");
        scanf("%d", &disciplinas[isFullD].matriculaProfessor);
        erro = ValidarExistenciaProfessor(
            disciplinas[isFullD].matriculaProfessor, isFullP, professores);
      } while (erro);
      disciplinas[isFullD].codigo = GerarCodigo();      
      puts("Disciplina cadastrada com sucesso!!");
      puts("==[1] Voltar");
      scanf("%d", &voltar);
      return -1;
    } else {
      puts("Sem professores matriculados para criar disciplina");
      puts("==[1] Voltar");
      scanf("%d", &voltar);
      return 0;
    }
  } else {
    puts("\nLista esta cheia");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
    return 0;
  }  
}

int ExcluirDisciplina(int isFullD, Disciplinas disciplinas[]) {
  int e, j, i, voltar, code, c;
  if (isFullD == 0) {
    puts("A lista de disciplinas esta vazia");
    puts("==[1] Voltar");
    scanf("%d", &voltar);
    return 0;
  } else {
    puts("================DISCIPLINAS=================");
    printf("Digite o codigo da Disciplina que deseja excluir: ");
    scanf("%d", &code);
    for (e = 0; e < isFullD; e++) {
      if (code == disciplinas[e].codigo) {
        for (j = e; j < isFullD - 1; j++) {
          for (i = 0; disciplinas[j].name[i] != '\0' ||
                      disciplinas[j + 1].name[i] != '\0';
               i++) {
            disciplinas[j].name[i] = disciplinas[j + 1].name[i];
          }
          disciplinas[j].name[i] = '\0';
        }
        for (j = e; j < isFullD - 1; j++) {
          disciplinas[j].matriculaProfessor =
              disciplinas[j + 1].matriculaProfessor;
          disciplinas[j].codigo = disciplinas[j + 1].codigo;
        }
        for (j = e; j < isFullD - 1; j++) {
          for (i = 0; disciplinas[j].semestre[i] != '\0' ||
                      disciplinas[j + 1].semestre[i] != '\0';
               i++) {
            disciplinas[j].semestre[i] = disciplinas[j + 1].semestre[i];
          }
          disciplinas[j].semestre[i] = '\0';
        }
        for (c = e; c < isFullD - 1; c++) {
          disciplinas[c].QuantAluno = disciplinas[c + 1].QuantAluno;
          for (i = 0; i < disciplinas[c].QuantAluno; i++) {
            disciplinas[c].ListAluno[i] = disciplinas[c + 1].ListAluno[i];
          }
        }      
        puts("Disciplina excluida com sucesso!!");
        puts("==[1] Voltar");
        scanf("%d", &voltar);
        return -1;
      }
    }
  }  
}

void AtualizarDisciplina(int isFullP, int isFullD, Disciplinas disciplinas[], Professor professor[]) {
  int a, i, j, voltar, code, erro, c = 1;
  if (isFullD == 0) {
    puts("A lista de disciplinas esta vazia");
  } else {
    puts("================DISCIPLINAS=================");
    printf("Digite o codigo da disciplinas que deseja atualizar: ");
    scanf("%d", &code);
    for (a = 0; a < isFullD; a++) {
      if (code == disciplinas[a].codigo) {
        c = 0;
        do {
          puts("====================================");
          puts("======Atualizar DISCIPLINAS=========");
          puts("====================================");
          printf("Nome da disciplina: ");
          getchar();
          fgets(disciplinas[a].name, 50, stdin);
          size_t ln = strlen(disciplinas[a].name) - 1;
          if (disciplinas[a].name[ln] == '\n')
            disciplinas[a].name[ln] = '\0';
          printf("Semestre da Disciplina:");
          fgets(disciplinas[a].semestre, 50, stdin);
          ln = strlen(disciplinas[a].semestre) - 1;
          if (disciplinas[a].semestre[ln] == '\n')
            disciplinas[a].semestre[ln] = '\0';
          printf("Numero de matricula do professor da disciplina: ");
          scanf("%d", &disciplinas[a].matriculaProfessor);
          erro = ValidarExistenciaProfessor(disciplinas[a].matriculaProfessor,
                                            isFullP, professor);
        } while (erro);
      }
    }
    if (c) {
      puts("Codigo de matricula inexistente");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ListarDisciplina(int isFullD, Disciplinas disciplinas[], int isFullP,
                      Professor professores[]) {
  int i, voltar, c;
  if (isFullD == 0) {
    puts("Sem disciplinas matriculadas");
  } else {
    for (i = 0; i < isFullD; i++) {
      puts("==========================================");
      printf("Nome: %s\n", disciplinas[i].name);
      printf("Codigo: %d\n", disciplinas[i].codigo);
      printf("Semestre: %s\n", disciplinas[i].semestre);
      for (c = 0; c < isFullP; c++) {
        if (disciplinas[i].matriculaProfessor == professores[c].matricula) {
          printf("Professor: %s\n", professores[c].name);
          break;
        }
      }
      if (c == isFullP) {
        puts("SEM PROFESSOR");
      }
      puts("==========================================");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void InserirAlunoNaDisciplina(int isFullD, Disciplinas disciplinas[],
                              int isFullA, Aluno aluno[]) {
  int d, a, voltar, j, code, c = 1, i = 0;
  if (isFullD == 0) {
    puts("Sem disciplinas matriculadas");
  } else {
    puts("\n================DISCIPLINAS=================");
    printf("Digite o codigo da disciplinas que deseja: ");
    scanf("%d", &code);
    for (d = 0; d < isFullD; d++) {
      if (code == disciplinas[d].codigo) {
        c = 0;
        if (disciplinas[d].QuantAluno != TAM) {
          if (isFullA == 0) {
            puts("Nao ha alunos matriculados");
          } else {
            puts("================ALUNOS=================");
            printf("Digite a matricula do Aluno que deseja: ");
            scanf("%d", &code);
            for (a = 0, i = 1; a < isFullA; a++) {
              if (code == aluno[a].matricula) {
                i = 0;
                disciplinas[d].ListAluno[disciplinas[d].QuantAluno] =
                    aluno[a].matricula;
                disciplinas[d].QuantAluno++;
                puts("Aluno cadastrado na disciplina com sucesso!!");                
                puts("==[1] Voltar");
                scanf("%d", &voltar);
                break;
              }
            }
          }
        } else {
          puts("Turma cheia");
        }
      }
    }
    if (c) {
      puts("Codigo de disciplina inexistente");
    }
    if (i) {
      puts("Numero de matricula inexistente");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ExcluirAlunoDaDisciplina(int isFullD, Disciplinas disciplinas[],
                              int isFullA, Aluno aluno[]) {
  int e, j, i, d, voltar, code;
  if (isFullD == 0) {
    puts("Sem disciplinas matriculadas");
  } else {
    puts("============EXCLUIR ALUNO DA DISCIPLINA=================");
    printf("Digite o codigo da disciplina que deseja excluir o aluno: ");
    scanf("%d", &code);
    for (d = 0; d < isFullD; d++) {
      if (code == disciplinas[d].codigo) {
        if (disciplinas[d].QuantAluno == 0) {
          puts("Sem alunos matriculados");
        } else {
          puts("________________________________________________");
          printf("Digite a matricula do Aluno que deseja excluir: ");
          scanf("%d", &code);
          for (e = 0; e < isFullA; e++) {
            if (code == aluno[e].matricula) {
              for (j = e; j < isFullD; j++) {
                disciplinas[d].ListAluno[j] = disciplinas[d].ListAluno[j + 1];
              }
              disciplinas[d].QuantAluno--;
              puts("Aluno excluido da disciplina com sucesso!!");
              puts("==[1] Voltar");
              scanf("%d", &voltar);
              break;
            }
          }
          if (e == isFullA) {
            puts("Numero de matricula inexistente");
          }
        }
        break;
      }
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void ListarDisciplinaComAlunos(int isFullD, Disciplinas disciplinas[],
                               int isFullA, Aluno aluno[], int isFullP,
                               Professor professores[]) {
  int i, voltar, j, c, k;
  system("clear");
  if (isFullD == 0) {
    puts("Sem disciplinas matriculadas");
  } else {
    puts("==============DISCIPLINA================");
    for (i = 0; i < isFullD; i++) {
      fflush(stdin);
      printf("Nome: %s\n", disciplinas[i].name);
      printf("Codigo: %d\n", disciplinas[i].codigo);
      printf("Semestre: %s\n", disciplinas[i].semestre);
      for (c = 0; c < isFullP; c++) {
        if (disciplinas[i].matriculaProfessor == professores[c].matricula) {
          printf("Professor: %s\n", professores[c].name);
          break;
        }
      }
      if (c == isFullP) {
        puts("SEM PROFESSOR");
      }
      puts("=========ALUNOS==============================");
      if (disciplinas[i].QuantAluno == 0) {
        puts("\t\tSem alunos matriculados");
      } else {
        for (j = 0; j < disciplinas[i].QuantAluno; j++) {
          for (k = 0; k < isFullA; k++) {
            if (disciplinas[i].ListAluno[j] == aluno[k].matricula) {
              printf("\t\tNome: %s\n", aluno[k].name);
              printf("\t\tMatricula: %d\n", aluno[k].matricula);
              printf("\t\tSexo: %c\n", aluno[k].sex);
              printf("\t\tCPF: %s\n", aluno[k].cpf);
              printf("\t\tData de Nascimento: %d/%d/%d\n",
                     aluno[k].dataBirth.dia, aluno[k].dataBirth.mes,
                     aluno[k].dataBirth.ano);
              puts("________________________________________");
            }
          }
        }
      }
      puts("==========================================");
    }
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}



void ListarDisciplinasComMaisDeQuarenta(int isFullD, Disciplinas disciplinas[], int isFullP, Professor professores[]) {
  int c, i, voltar, a = 0;
  system("clear");
  if (isFullD == 0) {
    puts("\nSem disciplinas matriculadas");
  } else {
    for (i = 0; i < isFullD; i++) {
      if (disciplinas[i].QuantAluno > 4) {
        a = 1;
        fflush(stdin);
        puts("==========================================");
        printf("Nome: %s\n", disciplinas[i].name);
        printf("Codigo: %d\n", disciplinas[i].codigo);
        printf("Semestre: %s\n", disciplinas[i].semestre);
        for (c = 0; c < isFullP; c++) {
          if (disciplinas[i].matriculaProfessor == professores[c].matricula) {
            printf("Professor: %s\n", professores[c].name);
            break;
          }
        }
        if (c == isFullP) {
          puts("SEM PROFESSOR");
        }
        puts("==========================================");
      }
    }
  }
  if (a) {
    puts("Nao ha disciplinas com mais de 40 alunos");
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

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

// VALIDAÇÔES ==============================================

int ValidarData(int ano, int mes, int dia) {
  if ((dia > 31 || dia < 0) || (mes > 12 || mes < 0) ||
      (ano < 0 || ano > 2023)) {
    puts("ERRO : DATA INVALIDA");
    return 1;
  }
  return 0;
}

int ValidarCPF(char cpf[]) {
  if (strlen(cpf) != 14 || cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-') {
    puts("ERRO : CPF NO FORMATO INVALIDO");
    return 1;
  }
  return 0;
}

int ValidarSexo(char sex) {
  if ((sex != 'm' && sex != 'M') && (sex != 'f' && sex != 'F')) {
    puts("ERRO: SEXO INVALIDO");
    return 1;
  }
  return 0;
}

int ValidarExistenciaProfessor(int matricula, int limite, Professor professores[]) {
  int i;
  for (i = 0; i < limite; i++) {
    if (matricula == professores[i].matricula) {
      return 0;
    }
  }
  puts("ERRO: PROFESSOR INEXISTENTE");
  return 1;
}

//=========================================================

void Aniversariantes(int isFullA, Aluno aluno[], int isFullP, Professor professores[]) {
  int mm, i, voltar, e = 1;
  if (isFullA != 0 || isFullP != 0) {
    system("clear");
    printf("Digite o mes mm: ");
    scanf("%d", &mm);
    puts("=======ANIVERSARIANTES DO MES=======");
    for (i = 0; i < isFullA; i++) {
      if (aluno[i].dataBirth.mes == mm) {
        printf("ALUNO: %s, %d/%d/%d\n", aluno[i].name, aluno[i].dataBirth.dia,
               aluno[i].dataBirth.mes, aluno[i].dataBirth.ano);
        e = 0;
      }
    }
    for (i = 0; i < isFullP; i++) {
      if (professores[i].dataBirth.mes == mm) {
        printf("PROFESSOR: %s, %d/%d/%d\n", professores[i].name,
               professores[i].dataBirth.dia, professores[i].dataBirth.mes,
               professores[i].dataBirth.ano);
        e = 0;
      }
    }
    if (e) {
      puts("Nao ha nenhuma pessoa que faz aniversario deste mes");
    }
  } else {
    puts("Sem pessoas matriculadas");
  }
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}

void Buscar(int isFullA, Aluno aluno[], int isFullP, Professor professores[]) {
  char busca[50];
  int voltar, c, i, j, a, l;
  if (isFullA == 0 && isFullP == 0) {
    puts("Sem pessoas para buscar");
  } else {
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
  }
  puts("=================================");
  puts("==[1] Voltar");
  scanf("%d", &voltar);
}