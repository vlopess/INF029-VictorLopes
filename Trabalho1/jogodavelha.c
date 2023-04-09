#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

char matriz[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '}, {' ', ' ', ' '}};

int turn = 1;

void mostrarVelha();
void change_matriz(char *xy);



int main(){  
  char xy[2];
  for(int j = 0; j < 9; j++ ){
    mostrarVelha();
    puts("Digite as coordenadas:");
    printf(">");
    scanf(" %3[^\n]s", xy);
    change_matriz(xy);
    mostrarVelha();
    getchar();
  }
}

void mostrarVelha(){
  printf("   A  B  C\n");
  for(int i = 0; i < 3; i++){
    printf("%d   %c|%c|%c", i + 1,matriz[i][0], matriz[i][1], matriz[i][2]);
    if(i!=2)
      printf("\n   -------\n");
  }  
  puts("\n");
}

void change_matriz(char *xy){
  int x, y;
  
  x = tolower(xy[0]) - 97;
  printf("(%c)", xy[1]);
  y = xy[1] - 48;
  
  if(x > 2 || y > 2)
    printf("ERROR");
  else{
    printf(" %d %d\n", x, y);
    matriz[x][y] = turn == 1? 'X' : "O";
    turn = turn == 1? 0 : 1;
  }
}