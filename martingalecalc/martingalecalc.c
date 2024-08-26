#include "martingalecalc.h"
#include <stdio.h>
#include <stdlib.h>
/*
struct Aposta {
    double odd;        // Armazena a odd da aposta
    double metaGanho;  // Armazena a meta de ganho
    int rodadas;       // Armazena o número de rodadas
    double stake;      // Armazena o valor da aposta (stake)
};
*/


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

//alocar uma matriz
double ** alocarMatriz(struct Aposta *apostas){
    //alocar memória para linhas
    double **matriz = (double**) malloc((*apostas).rodadas * sizeof(double*));
    for(int i=0; i < (*apostas).rodadas; i++){
        //alocar memória para colunas
        matriz[i] = (double*) malloc(2 * sizeof(double));
    }
    return matriz;
}


//retorna uma matriz
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
