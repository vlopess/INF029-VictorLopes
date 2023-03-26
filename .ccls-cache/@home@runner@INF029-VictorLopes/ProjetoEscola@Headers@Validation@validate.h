#ifndef _VALIDATE_H
#define _VALIDATE_H

#include "../StructsBase/professor.h"

int ValidarData(int ano, int mes, int dia);
int ValidarCPF(char cpf[]);
int ValidarSexo(char sex);
int ValidarExistenciaProfessor(int matricula, int limite, Professor professores[]);


#endif
