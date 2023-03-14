#include <stdio.h>
#include <string.h>
#include "../StructsBase/Base.c"

// int ValidarData(int ano, int mes, int dia) {
//   if ((dia > 31 || dia < 0) || (mes > 12 || mes < 0) || ano < 0) {
//     puts("ERRO : DATA INVALIDA");
//     return 0;
//   }
//   return 1;
// }

// int ValidarMatricula(int matricula, int limite) {
//   int i;
//   if (matricula < 0) {
//     puts("Numero de matricula invalida");
//     return 0;
//   }
//   for (i = 0; i < limite; i++) {
//     if (aluno[i].matricula == matricula ||
//         professores[i].matricula == matricula) {
//       puts("Numero ja existente");
//       return 0;
//     }
//   }
//   return 1;
// }

// int ValidarCPF(char cpf[]) {
//   if (strlen(cpf) != 14 || cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-') {
//     puts("CPF no formato errado");
//     return 0;
//   }
//   return 1;
// }