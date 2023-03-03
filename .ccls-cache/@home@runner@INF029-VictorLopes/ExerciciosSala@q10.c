// Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas.
// Ao final imprima tudo. Utilize vetor e struct.
#include <stdio.h>
#define tam 5

typedef struct ficha_de_pessoas {
  char nome[50];
  int idade;
  char sexo[20];
  char cpf[14];
} dados;

int main(void) {
  int i;
  dados pessoas[tam];

  for (i = 0; i < tam; i++) {

    printf("PESSOA %d\n", i + 1);
    printf("Digite o nome:");
    fflush(stdin);
    scanf("%s", pessoas[i].nome);
    printf("Digite a idade:");
    scanf("%d", &pessoas[i].idade);
    printf("Digite o sexo:");
    fflush(stdin);
    scanf("%s", pessoas[i].sexo);
    printf("Digite o cpf:");
    fflush(stdin);
    scanf("%s", pessoas[i].cpf);
  }

  for (i = 0; i < 5; i++) {
    printf("NOME: %s\n", pessoas[i].nome);
    printf("IDADE: %d\n", pessoas[i].idade);
    printf("SEXO: %s\n", pessoas[i].sexo);
    printf("CPF: %s\n", pessoas[i].cpf);
  }
}