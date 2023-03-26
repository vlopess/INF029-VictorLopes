#include "Base.h"
#include "aluno.h"
#include "professor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int GerarCodigo() {
  static int count = 0;
  count++;
  return count;
}

//=========================================================

void Aniversariantes(int isFullA, Aluno aluno[], int isFullP,
                     Professor professores[]) {
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