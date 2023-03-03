#include <stdio.h>
int n, i, idade;
double media = 0;

int main(void) {
  scanf("%d", &n);
  int vetIdd[n];
  char vetNome[n][30];
  for (i = 0; i < n; i++) {
    printf("Digite o nome: ");
    scanf("%s",vetNome[i]);
    printf("Digite a idade: ");
    scanf("%d", &vetIdd[i]);
    media += vetIdd[i];
  }
  media /= n;
  printf("Acima da média:\n");
  for (i = 0; i < n; i++) {
    if (vetIdd[i] > media)
      printf("%s, %d\n", vetNome[i], vetIdd[i]);
  }
  printf("A media foi : %.2f\n", media);
}