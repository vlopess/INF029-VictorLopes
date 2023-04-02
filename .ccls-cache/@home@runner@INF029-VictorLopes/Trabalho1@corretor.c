// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Victor Lopes Dos Santos
//  email: victorlopes9291@gmail.com
//  Matrícula: 20222160020
//  Semestre: 2023.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021

// #################################################

#include <stdio.h>
#include <string.h>
#include "VictorSantos20222160020.h"

void testSomar();
void testFatorial();
void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();

int main()
{   
    //testFatorial();
    //testSomar();
    //testQ1();
    //testQ2();
    testQ3();
    //testQ4();
    //testQ5();
    // testQ6();
  
}

void testSomar()
{
    printf("%d\n", somar(3, 4) == 7);
    printf("%d\n", somar(-1, -3) == -4);
    printf("%d\n", somar(-6, 6) == 0);
    printf("%d\n", somar(74, 9) == 83);
    printf("%d\n", somar(30, -9) == 21);
    printf("%d\n", somar(-2, 8) == 6);
    printf("%d\n", somar(1000, 99) == 1099);

}

void testFatorial()
{
    printf("%d\n", fatorial(3) == 6);
    printf("%d\n", fatorial(1) == 1);
    printf("%d\n", fatorial(5) == 120);
}

void testQ1()
{
    char str[11];
    strcpy(str, "29/02/2015");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "29/02/2012");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "9/13/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "45/4/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "/9/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "30/02/2015");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "29/02/2012");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "19/1/2014");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "er/er/erer");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "33/9/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "31/02/2015");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "29/a2/2012");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "a/1a3/sdad");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "45/14/0");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "31/1/2014");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "02/03/2015");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "12/1/15");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "1/9/16");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "1/1/11");
    printf("%d\n", q1(str) == 1);
}

void testQ2()
{
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    DiasMesesAnos dma;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 0);
    printf("%d\n", dma.qtdMeses == 0);
    printf("%d\n", dma.qtdAnos == 1);

    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/30/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 2);

    strcpy(datainicial, "01/3/2015");
    strcpy(datafinal, "40/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 3);

    strcpy(datainicial, "01/06/2016");
    strcpy(datafinal, "01/06/2015");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 4);

    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "06/06/2017");
    strcpy(datafinal, "07/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 1);
    printf("%d\n", dma.qtdMeses == 1);
    printf("%d\n", dma.qtdAnos == 0);
}
  
void testQ3()
{
    char str[250];
    strcpy(str, "Renato Lima Novais");
    printf("%d\n", q3(str, 'a', 0) == 3);
    printf("%d\n", q3(str, 'b', 0) == 0);
    printf("%d\n", q3(str, 'l', 1) == 0);
    printf("%d\n", q3(str, 'l', 0) == 1);
    printf("%d\n", q3(str, 'L', 0) == 1);
}

void testQ4()
{
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca, "rato");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n", posicoes[0] == 5);
    printf("%d\n", posicoes[1] == 8);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 37);
    printf("\n");
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca, "mui");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n", posicoes[0] == 16);
    printf("%d\n", posicoes[1] == 18);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 36);
    printf("%d\n", posicoes[4] == 52);
    printf("%d\n", posicoes[5] == 54);
}

void testQ5()
{
    printf("%d\n", q5(345) == 543);
    printf("%d\n", q5(78) == 87);
    printf("%d\n", q5(3) == 3);
    printf("%d\n", q5(5430) == 345);
    printf("%d\n", q5(123) == 321);
    printf("%d\n", q5(10) == 1);
    printf("%d\n", q5(311111) == 111113);
    printf("%d\n", q5(50000) == 5);
}

void testQ6()
{
    printf("%d\n", q6(34567368, 3) == 2);
    printf("%d\n", q6(34567368, 4576) == 0);
    printf("%d\n", q6(3539343, 3) == 4);
    printf("%d\n", q6(3539343, 39) == 1);
}