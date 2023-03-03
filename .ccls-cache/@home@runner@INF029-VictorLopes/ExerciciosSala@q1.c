//Faça um programa que imprima o seu nome, sua matrícula, e o seu semestre de ingresso no curso. Cada informação em uma linha.
#include <stdio.h>

char nome[] = "Victor Lopes dos Santos";
long int matricula = 20222160020;
char semestre[] = "2022.2";

int main(void) {
    printf("%s, %ld, %s", nome, matricula, semestre);
}