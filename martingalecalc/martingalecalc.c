/************************************************************
 * Biblioteca: martingalecalc.c
 * Autor: Henrique Caregnato
 * Data: 27/08/2024
 * Descrição: Esta biblioteca fornece funções para calcular
 * e exibir os valores de apostas usando a estratégia 
 * Martingale. Inclui funções para alocar memória para a 
 * matriz de resultados, calcular valores de apostas em X 
 * rodadas, e exibir uma tabela formatada com os resultados.
 ************************************************************/
#include "martingalecalc.h"
#include <stdio.h>
#include <stdlib.h>

void exibirTabelaMartingale(double **matriz,struct Aposta *aposta){
    int linhas = (*aposta).rodadas;
    system("clear");
    printf("Stake inicial: %.2f\n", (*aposta).stake);
    printf("Odd fixa: %.2f\n", (*aposta).odd);
    printf("Metas de ganhos: %.2f\n", (*aposta).metaGanho);

    printf("+--------+----------------+-----------------+\n");
    printf("| Rodada | Valor Apostado | Perda Acumulada |\n");
    printf("+--------+----------------+-----------------+\n");

     for(int i =0; i < linhas; i++){
        // Linhas da Tabela
        printf("| %-6d | %-14.2f | %-15.2f |\n", i+1, matriz[i][0], matriz[i][1]);
        printf("+--------+----------------+-----------------+\n");
    }
}

//Aloca uma matriz bidimencional
double ** alocarMatriz(struct Aposta *apostas){
    //alocar memória para linhas
    double **matriz = (double**) malloc((*apostas).rodadas * sizeof(double*));
    for(int i=0; i < (*apostas).rodadas; i++){
        //alocar memória para colunas
        matriz[i] = (double*) malloc(2 * sizeof(double));
    }
    return matriz;
}


//Faz os calculos de valores para a estratégia martingale e retorna uma matriz
double** calcularXRodadas(struct Aposta *aposta) {
    (*aposta).metaGanho = ((*aposta).odd * (*aposta).stake) - ((*aposta).stake);

    double perdaAcumulada = 0;
    double valorASerApostado = 0;

    double **matriz = alocarMatriz(aposta);

    for(int i =0; i < (*aposta).rodadas; i++){
       valorASerApostado = ((*aposta).metaGanho + perdaAcumulada) / ((*aposta).odd - 1);
        perdaAcumulada = perdaAcumulada + valorASerApostado;
        matriz[i][0] = valorASerApostado;
        matriz[i][1] = perdaAcumulada;
    }
    return matriz;
}
