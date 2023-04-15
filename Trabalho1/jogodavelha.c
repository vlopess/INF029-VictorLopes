#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>



char matriz[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '}, {' ', ' ', ' '}};

int turn = 1;
int count = 0;
char winner;

void mostrarVelha();
int change_matriz(char *xy);
int validarPosicao(int x, int y);
int veia();
// void lastVeia(char winner);


int main(){  
  char xy[2];
  while(1){ 
    mostrarVelha();
    printf("Digite as coordenadas(%c):\n", turn == 1 ? 'X' : 'O');
    printf(">");
    scanf(" %3[^\n]s", xy);
    if(change_matriz(xy)){
      getchar();
      int value = veia();
      if(value)
        break;
    }
    
  }
  return 0;
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

int change_matriz(char *xy){
  int x, y;

  y = tolower(xy[0]) - 97;
  x = xy[1] - 49;
  
  if(validarPosicao(x, y)){
    matriz[x][y] = turn == 1 ? 'X' : 'O';
    turn = turn == 1? 0 : 1;
    count++;
    return 1;
  }
}

int validarPosicao(int x, int y){
  system("clear");
  if(x > 2 || y > 2 || x < 0 || y < 0){
    puts("ERROR -> POSICAO INVALIDA");
    return 0;
  }
  if(matriz[x][y] != ' '){
    puts("ERROR -> POSICAO INVALIDA");
    return 0;
  }
  return 1;
}

int veia(){
  system("clear");
  //as dialogonas
  if(matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != ' '){
    // winner = matriz[0][0];
    // matriz[0][0] = 'a';
    // matriz[1][1] = 'a';
    // matriz[2][2] = 'a';
    // lastVeia(winner);
    mostrarVelha();
    printf("O %c VENCEU!!!!!!!\n", matriz[0][0]);
    return 1;
  }
  if(matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != ' '){
    // matriz[0][2] = 'a';
    // matriz[1][1] = 'a';
    // matriz[2][0] = 'a';
    // lastVeia(winner);
    mostrarVelha();
    printf("O %c VENCEU!!!!!!!\n", matriz[0][2]);
    return 1;
  }
  //horizontais
  if(matriz[0][0] == matriz[0][1] && matriz[0][1] == matriz[0][2] && matriz[0][0] != ' '){
    // lastVeia(matriz[0][0], matriz[0][1], matriz[0][2]);
    mostrarVelha();
    printf("O %c VENCEU!!!!!!!\n", matriz[0][0]);
    return 1;
  }
  if(matriz[1][0] == matriz[1][1] && matriz[1][1] == matriz[1][2] && matriz[1][0] != ' '){
    // winner = matriz[1][0];
    // matriz[1][0] = 'a';
    // matriz[1][1] = 'a';
    // matriz[1][2] = 'a';
    // lastVeia(winner);
    mostrarVelha();
    printf("O %c VENCEU!!!!!!!\n", matriz[1][0]);
    return 1;
  }
  if(matriz[2][0] == matriz[2][1] && matriz[2][1] == matriz[2][2] && matriz[2][0] != ' '){
    // lastVeia(matriz[2][0], matriz[2][1], matriz[2][2]);
    mostrarVelha();
    printf("O %c VENCEU!!!!!!!\n", matriz[2][0]);
    return 1;
  }
  //vertical
  if(matriz[0][0] == matriz[1][0] && matriz[1][0] == matriz[2][0] && matriz[0][0] != ' '){
    // lastVeia(matriz[0][0], matriz[1][0], matriz[2][0]);
    mostrarVelha();
    printf("O %c VENCEU!!!!!!!\n", matriz[0][0]);
    return 1;
  }
  if(matriz[0][1] == matriz[1][1] && matriz[1][1] == matriz[2][1] && matriz[0][1] != ' '){
    // lastVeia(matriz[0][1], matriz[1][1], matriz[2][1]);
    mostrarVelha();
    printf("O %c VENCEU!!!!!!!\n", matriz[1][0]);
    return 1;
  }
  if(matriz[0][2] == matriz[1][2] && matriz[1][2] == matriz[2][2] && matriz[0][2] != ' '){
    // lastVeia(matriz[0][2], matriz[1][2], matriz[2][2]);
    mostrarVelha();
    printf("O %c VENCEU!!!!!!!\n", matriz[2][0]);
    return 1;
  }
  if(count == 9){
    mostrarVelha();
    puts("DEU VELHA!!!");
    return 1;
  }
  return 0;
}

// void lastVeia(int i1, int c1, int i2, int c2, int i3, int c3){
//   for(int i = 0; i < 3; i++){
//     for(int c = 0; c < 3; c++){
//       if(matriz[i][c] == c1 || m)
//         printf("%c", matriz[i][c]);
//       else
//         printf("%c", 219);
//       if(c<2)
//         printf(" |");
//     }
//     if(i<2)
//       printf("\n----------\n");
//   }
//   puts("\n");
// }