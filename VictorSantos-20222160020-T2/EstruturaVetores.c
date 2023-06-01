#include "EstruturaVetores.h"
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

Registro vetorPrincipal[TAM];

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao) {
  if (posicao < 1 || posicao > 10) {
    return 1;
  }
  return 0;
}

int existeEstruturaAuxiliar(int posicao) {
  int i = posicao - 1;
  return vetorPrincipal[i].vetor == NULL;   
}

int temEspacoEstrutura(int i) {
  i--;
  return !(vetorPrincipal[i].tamanho == vetorPrincipal[i].quantidade);
}

int isEmpty(int i) {
  i--;
  return !(vetorPrincipal[i].quantidade == 0);
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {
  int i = posicao - 1;
  int qtd = tamanho;
  
  // se posição é um valor válido {entre 1 e 10}
  if (ehPosicaoValida(posicao))
    return POSICAO_INVALIDA;
  
  // a posicao pode já existir estrutura auxiliar
  if (vetorPrincipal[i].vetor)
    return JA_TEM_ESTRUTURA_AUXILIAR;

  

  // o tamanho nao pode ser menor que 1
  if (tamanho < 1)
    return TAMANHO_INVALIDO;
  // o tamanho ser muito grande
  vetorPrincipal[i].vetor = malloc(sizeof(int) * qtd);

  if (!(vetorPrincipal[i].vetor))
    return SEM_ESPACO_DE_MEMORIA;

  // deu tudo certo, crie
  vetorPrincipal[i].tamanho = qtd;

  return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {
  int existeEstrutura = existeEstruturaAuxiliar(posicao);
  int temEspaco = temEspacoEstrutura(posicao);
  int posicao_invalida = ehPosicaoValida(posicao);

  if (posicao_invalida)
    return POSICAO_INVALIDA;
  else {
    // testar se existe a estrutura auxiliar
    if (!existeEstrutura) {
      if (temEspaco) {
        int i = posicao - 1;
        int j = vetorPrincipal[i].quantidade;
        vetorPrincipal[i].vetor[j] = valor;
        vetorPrincipal[i].quantidade++;
        return SUCESSO;
      } else {
        return SEM_ESPACO;
      }
    } else {
      return SEM_ESTRUTURA_AUXILIAR;
    }
  }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar
da seguinte forma [3, 8, 7,  ,  ,  ]. Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
  int i = posicao - 1;
  int j = vetorPrincipal[i].quantidade - 1;
  int existeEstrutura = existeEstruturaAuxiliar(posicao);
  int posicao_invalida = ehPosicaoValida(posicao);
  int vazio = isEmpty(posicao);

  if (posicao_invalida)
    return POSICAO_INVALIDA;
  else {
    // testar se existe a estrutura auxiliar
    if (!existeEstrutura) {
      if (vazio) {
        vetorPrincipal[i].quantidade--;
        return SUCESSO;
      } else {
        return ESTRUTURA_AUXILIAR_VAZIA;
      }

    } else {
      return SEM_ESTRUTURA_AUXILIAR;
    }
  }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições
anteriores ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o
valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ] Obs. Esta é
uma exclusão lógica Retorno (int) SUCESSO - excluido com sucesso 'valor' da
estrutura na posição 'posicao' ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
  int i = posicao - 1;
  int j = vetorPrincipal[i].quantidade - 1;
  int existeEstrutura = existeEstruturaAuxiliar(posicao);
  int posicao_invalida = ehPosicaoValida(posicao);
  int vazio = isEmpty(posicao);

  if (posicao_invalida)
    return POSICAO_INVALIDA;
  else {
    if (!existeEstrutura) {
      if (vazio) {
        int qtd = vetorPrincipal[i].quantidade;
        
        for (int j = 0; j < qtd; j++) {          
          if (vetorPrincipal[i].vetor[j] == valor) {
            for (int c = j; c < qtd - 1; c++) {
              vetorPrincipal[i].vetor[c] = vetorPrincipal[i].vetor[c + 1];
            }
            vetorPrincipal[i].quantidade--;
            return SUCESSO;
          }
        }
        
        return NUMERO_INEXISTENTE;        
      } else {
        return ESTRUTURA_AUXILIAR_VAZIA;
      }
    } else {
      return SEM_ESTRUTURA_AUXILIAR;
    }
  }
}


int getQuantidadeElementosDeTodasEstruturaAuxiliar(){
  int qtd = 0;
  for(int i = 0; i < TAM; i++){
    qtd += vetorPrincipal[i].quantidade;
  }
  return qtd;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
  int c = 0;
  for (int j = 0; j < TAM; j++) {
    int max = vetorPrincipal[j].quantidade;
    for(int i = 0 ; i < max ; i++){
      vetorAux[c++] = vetorPrincipal[j].vetor[i];
    }
  }
  if(c)
    return SUCESSO;

  return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

  int i = posicao - 1;
  int max = vetorPrincipal[i].quantidade;
  int existeEstrutura = existeEstruturaAuxiliar(posicao);
  int posicao_invalida = ehPosicaoValida(posicao);

  if(posicao_invalida)
      return POSICAO_INVALIDA;
    
  if(existeEstrutura)
    return SEM_ESTRUTURA_AUXILIAR;  
    
  for (int j = 0; j < max; j++) {
    vetorAux[j] = vetorPrincipal[i].vetor[j];
  }

  return SUCESSO;
}

void CopyArray(int dest[], int origem[], int tam){
  for(int i = 0 ; i < tam ; i++){
    dest[i] = origem[i];
  }
}


void insertionSort(int A[], int length)
{
     int j;
     for (j = 1; j < length; j++)
     {
          int key = A[j];
          int i = j - 1;
          while (i >= 0 && A[i] > key)
          {
              A[i + 1] = A[i];
              i--;
          } 
          A[i + 1] = key;
     }
}
/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao
(1..10)'. os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao
(1..10)' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
  int i = posicao - 1;
  int existeEstrutura = existeEstruturaAuxiliar(posicao);
  int posicao_invalida = ehPosicaoValida(posicao);
  int vazio = isEmpty(posicao);
  
  if (posicao_invalida)
    return POSICAO_INVALIDA;
  else {
    if (!existeEstrutura) {
      if (vazio) {
        
        int max = vetorPrincipal[i].quantidade;        
        CopyArray(vetorAux, vetorPrincipal[i].vetor, max);
        insertionSort(vetorAux, max);
        
        return SUCESSO;
        
      } else {
        return ESTRUTURA_AUXILIAR_VAZIA;
      }

    } else {
      return SEM_ESTRUTURA_AUXILIAR;
    }
  }
}


/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

  int tam = getQuantidadeElementosDeTodasEstruturaAuxiliar();
  if(!tam)
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  getDadosDeTodasEstruturasAuxiliares(vetorAux);
  insertionSort(vetorAux, tam);
  return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o
novo tamanho 'novoTamanho' + tamanho atual Suponha o tamanho inicial = x, e novo
tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser
sempre >= 1

Retorno (int)
    SUCESSO - foi modificado correqtdente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
  int i = posicao - 1;
  int tam = vetorPrincipal[i].tamanho + novoTamanho;
  int existeEstrutura = existeEstruturaAuxiliar(posicao);
  
  if (ehPosicaoValida(posicao))
    return POSICAO_INVALIDA;

  if(existeEstrutura)
    return SEM_ESTRUTURA_AUXILIAR;
  
  if (tam < 1)
    return NOVO_TAMANHO_INVALIDO;
  
  vetorPrincipal[i].vetor = realloc(vetorPrincipal[i].vetor, sizeof(int) * tam);

  if (!(vetorPrincipal[i].vetor))
    return SEM_ESPACO_DE_MEMORIA;

  if(tam < vetorPrincipal[i].tamanho)
    vetorPrincipal[i].quantidade += novoTamanho;
  
  vetorPrincipal[i].tamanho = tam;
   

  return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da
posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da
estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {

  int i = posicao - 1;
  int existeEstrutura = existeEstruturaAuxiliar(posicao);
  int posicao_invalida = ehPosicaoValida(posicao);
  int vazio = isEmpty(posicao);

  if (posicao_invalida)
    return POSICAO_INVALIDA;
  else {
    if (!existeEstrutura) {
      if (vazio) {
        return vetorPrincipal[i].quantidade;
      } else {
        return ESTRUTURA_AUXILIAR_VAZIA;
      }
    } else {
      return SEM_ESTRUTURA_AUXILIAR;
    }
  }
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes
em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote() 
{ 

  int tam = getQuantidadeElementosDeTodasEstruturaAuxiliar();
  if(!tam)
    return NULL;
  int numbers[tam];
  getDadosDeTodasEstruturasAuxiliares(numbers);
  No *inicio = NULL;
  No *current = NULL;
  No *next = NULL;
  
  for(int i = 0 ; i < tam ; i++){
    current = malloc(sizeof(No));
    if(!inicio){
      inicio = current;
    }
    current->conteudo = numbers[i];
    current->prox = NULL;
    if(next)
      next->prox = current;
    next = current;
  }
  return inicio; 
}

/*
Objetivo: retorna os números da lista encadeada com cabeçote armazenando em
vetorAux. Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) 
{
  int i = 0;
  while(inicio){
    vetorAux[i++] = inicio->conteudo;
    inicio = inicio->prox;
  }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) 
{  
  No *i = *inicio;
  
  while(i){
    No *next = i->prox;
    free(i);
    i = next;
  }
  *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar() {
  for (int i = 0; i < TAM; i++) {
    vetorPrincipal[i].quantidade = 0;
    vetorPrincipal[i].tamanho = 0;
    vetorPrincipal[i].vetor = NULL;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar() {
  for(int i = 0; i < TAM; i++){
    free(vetorPrincipal[i].vetor);
  }
}

void showme() {
  for (int i = 0; i < TAM; i++) {
    if (vetorPrincipal[i].vetor) {
      int max = vetorPrincipal[i].quantidade;
      for (int j = 0; j < max; j++) {
        printf("%d ", vetorPrincipal[i].vetor[j]);
      }
      puts("\n");
    }
  }
}