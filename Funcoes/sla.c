#include <stdio.h>

int Sum(int n1, int n2){
  return n1 + n2;
}

int main(){
  
  int v1, v2;
  
  printf("Digite valor 1:");
  scanf("%d", &v1);
  
  printf("Digite valor 2:");
  scanf("%d", &v2);
  
  printf("%d + %d = %d", v1, v2, Sum(v1, v2));
}