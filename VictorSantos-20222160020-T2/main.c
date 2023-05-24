#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

int menu();


//void dobrar(int *x);

int menu()
{
    int op;
    //system("clear");
    puts("Digite as opção desejada\n");
    puts("0 - Sair\n");
    puts("1 - Criar\n");
    puts("2 - Inserir\n");
    puts("3 - Excluir Último\n");
    puts("4 - Excluir pela Posição\n");
    puts("5 - Listar uma Estrutura\n");
    puts("6 - Listar todas as estruturas\n");
    puts("7 - Listar uma Estrutura Ordenada\n");
    puts("8 - Listar todas as estruturas Ordenada\n");
    puts("9 - Mudar o tamanho da estrutura\n");
    //puts("6 - Show me\n");
    scanf("%d", &op);
    return op;
}

int main()
{
    inicializar();
    int op;
    int ret;
    do{
        
        op = menu();
        system("clear");
        switch (op)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
          int posicao, tamanho;
          puts("Digite o posição da estrutura:");
          scanf("%d", &posicao);
          puts("Digite o tamanho da estrutura:");
          scanf("%d", &tamanho);
          ret = criarEstruturaAuxiliar(posicao, tamanho);
          if (ret == SUCESSO)
          {
              puts("Criado com sucesso");
          }
          else if (ret == SEM_ESPACO)
          {
              puts("Sem Espaço");
          }
          else if (ret == JA_TEM_ESTRUTURA_AUXILIAR)
          {
              puts("Já tem estrutura Auxiliar nesta posição");
          }
          else if (ret == POSICAO_INVALIDA)
          {
              puts("Posição Invalida");
          }
          else if (ret == TAMANHO_INVALIDO)
          {
              puts("Tamanho Invalida");
          }
          break;
        }
        case 2:
        { 
          int posicao, valor;
          puts("Digite o posição da estrutura:");
          scanf("%d", &posicao);
          puts("Digite o valor:");
          scanf("%d", &valor);
          ret = inserirNumeroEmEstrutura(posicao, valor);
          if (ret == SUCESSO)
          {
            puts("Inserido com sucesso");
          }
          else if (ret == SEM_ESPACO)
          {
            puts("Sem Espaço");
          }
          else if (ret == SEM_ESTRUTURA_AUXILIAR)
          {
            puts("Sem estrutura Auxiliar criada");
          }
          else if (ret == POSICAO_INVALIDA)
          {
            puts("Posição invalida");
          }
          break;
        }

        case 3:
        { 
          int posicao;
          puts("Digite o posição da estrutura que deseja excluir:");
          scanf("%d", &posicao);
          ret = excluirNumeroDoFinaldaEstrutura(posicao);
          if (ret == SUCESSO)
          {
            puts("Excluido com sucesso");
          }
          else if (ret == ESTRUTURA_AUXILIAR_VAZIA)
          {
            puts("Estrutura vazia");
          }
          else if (ret == SEM_ESTRUTURA_AUXILIAR)
          {
            puts("Sem estrutura Auxiliar");
          }
          else if (ret == POSICAO_INVALIDA)
          {
            puts("Posição invalida");
          }
          break;
        }
        case 4:
        {
          int posicao, valor;
          puts("Digite o posição da estrutura:");
          scanf("%d", &posicao);
          puts("Digite o valor que deseja excluir:");
          scanf("%d", &valor);
          ret = excluirNumeroEspecificoDeEstrutura(posicao, valor);
          if (ret == SUCESSO)
          {
            puts("Excluido com sucesso");
          }
          else if (ret == ESTRUTURA_AUXILIAR_VAZIA)
          {
            puts("Estrutura vazia");
          }
          else if (ret == SEM_ESTRUTURA_AUXILIAR)
          {
            puts("Sem estrutura Auxiliar");
          }
          else if (ret == POSICAO_INVALIDA)
          {
            puts("Posição invalida");
          }
          else if (ret == NUMERO_INEXISTENTE)
          {
            puts("Numero inexistente");
          }
          break;  
        }
          
        case 5:
        { 
          int posicao, retorno;
          puts("Qual a estrutura a ser listada (1..10)?");
          scanf("%d", &posicao);

          int qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);
          if (qtd == POSICAO_INVALIDA)
          {
            puts("Posição inválida");
          }
          else if(qtd == SEM_ESTRUTURA_AUXILIAR){
            puts("Sem estrutura auxiliar");
          }
          else if(qtd == ESTRUTURA_AUXILIAR_VAZIA){
            puts("Estrutura Auxiliar Vazia");
          }
          else
          {
            int vetorAux[qtd];

            retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);

            if (retorno == SUCESSO)
            {
              printf("Tamanho da estrutura : %d\n", qtd);
              printf("Elementos da estrutura :");
              for (int i = 0; i < qtd; i++)
              {
                printf("%d ", vetorAux[i]);
              }
              puts("\n");
            }
          }
          break;
        }
        case 6:
        {
          int qtd = getQuantidadeElementosDeTodasEstruturaAuxiliar();
          
          if(qtd){
            
            int vetorAux[qtd];
  
            int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
  
            if (retorno == SUCESSO)
            {
              printf("Elementos de todas as estrutura :");
              for (int i = 0; i < qtd; i++)
              {
                printf("%d ", vetorAux[i]);
              }
              puts("\n");
            }
            else if(retorno == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS)
            {
              puts("Todas as estruturas vazias");
            }
          }
          else
          {
            puts("Todas as estruturas vazias");  
          }
          break;
        }  
        case 7:
        {
          int posicao, retorno;
          puts("Qual a estrutura a ser listada (1..10)?");
          scanf("%d", &posicao);

          int qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);
          if (qtd == POSICAO_INVALIDA)
          {
            puts("Posição inválida");
          }
          else if(qtd == SEM_ESTRUTURA_AUXILIAR){
            puts("Sem estrutura auxiliar");
          }
          else if(qtd == ESTRUTURA_AUXILIAR_VAZIA){
            puts("Estrutura Auxiliar Vazia");
          }
          else
          {
            int vetorAux[qtd];

            retorno = getDadosOrdenadosEstruturaAuxiliar(posicao, vetorAux);

            if (retorno == SUCESSO)
            {
              printf("Tamanho da estrutura : %d\n", qtd);
              printf("Elementos da estrutura ordenados:");
              for (int i = 0; i < qtd; i++)
              {
                printf("%d ", vetorAux[i]);
              }
              puts("\n");
            }
          }
          break;
        } 
        case 8:
        {
          int qtd = getQuantidadeElementosDeTodasEstruturaAuxiliar();
          
          if(qtd){
            
            int vetorAux[qtd];
  
            int retorno = getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorAux);
  
            if (retorno == SUCESSO)
            {
              printf("Elementos de todas as estruturas ordenados:");
              for (int i = 0; i < qtd; i++)
              {
                printf("%d ", vetorAux[i]);
              }
              puts("\n");
            }
            else if(retorno == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS)
            {
              puts("Todas as estruturas vazias");
            }
          }
          else
          {
            puts("Todas as estruturas vazias");  
          }
          break;
        } 
        case 9:
        {
          int posicao, tamanho;
          puts("Digite o posição da estrutura:");
          scanf("%d", &posicao);
          puts("Digite o novo tamanho da estrutura:");
          scanf("%d", &tamanho);
          ret = modificarTamanhoEstruturaAuxiliar(posicao, tamanho);
          if (ret == SUCESSO)
          {
              puts("Modificado com sucesso");
          }
          else if (ret == SEM_ESTRUTURA_AUXILIAR)
          {
              puts("Sem Estrutura auxiliar criada");
          }
          else if (ret == SEM_ESPACO_DE_MEMORIA)
          {
              puts("Sem espaço de memória");
          }
          else if (ret == POSICAO_INVALIDA)
          {
              puts("Posição Invalida");
          }
          else if (ret == NOVO_TAMANHO_INVALIDO)
          {
              puts("Tamanho Invalida");
          }
          break;
        }
        case 10:
        { //dobrar
            //ler um numero
            int valor;
            scanf("%i", &valor);

            //dobrar(&valor);

            //passar para um funcao (void dobrar(...)) que recebe o numero e dobra (EstruturaVetores.c)

            printf("%i", valor);

            break;
        }

        default:
        {
            printf("opcao inválida\n");
        }
      }
    }while (op);


    return 0;
}