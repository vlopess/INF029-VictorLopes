#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../StructsBase/professor.h"

// VALIDAÇÔES ==============================================

int ValidarData(int ano, int mes, int dia) {
  if ((dia > 31 || dia < 0) || (mes > 12 || mes < 0) ||
      (ano < 1900 || ano > 2023)) {
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