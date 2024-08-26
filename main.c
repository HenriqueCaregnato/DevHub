/*
    Martingale Simulator

    Este programa faz calculos para definir valores a apostar em uma 
    estrategia martingale
*/
#include <stdio.h>
#include <stdlib.h>
#include "martingalecalc.h"

//Variaveis globais
struct Aposta *dadosAposta; //para econimizar recursos futuramente

void exibirMenu(){
    double odd, metaGanho, rodadas, stake;
    printf("#####################################\n");
    printf(" Martingale Calc\n");
    printf("#####################################\n");
    printf("Escolha uma opção\n");
    printf("1. Calcular 'x' rodadas\n");
    printf("2. Calcular com saldo limite\n");
    printf("3. sair\n");
}

int selecionarMenu(){
    int selecao;
    scanf("%d", &selecao);
    return selecao;
}

void pegarDadosAposta(){
    //Verificar se a memória já foi alocada
    if (dadosAposta == NULL) {
        dadosAposta = (struct Aposta*) malloc(sizeof(struct Aposta));
        if (dadosAposta == NULL) {
            printf("Erro ao alocar memória!\n");
            exit(1); 
        }
    }
    system("clear");
    printf("Entre com os valores separados por um espaço, ao finalizar de ENTER\n");
    printf("(odd: float) (stake: float ) (rodadas: int)\n");
    printf("Exemplo: 1.5 25.00 5\n");
    printf("-----------------------------------------------------------------------\n");
    scanf("%lf %lf %d", &((*dadosAposta).odd), &((*dadosAposta).stake), &((*dadosAposta).rodadas));
    //teste
    printf("Entradas %lf %lf %d\n",(*dadosAposta).odd, (*dadosAposta).stake, (*dadosAposta).rodadas);
}

int processarSelecao(int selecao){
    switch (selecao)
    {
    case 1:
        pegarDadosAposta();
        calcularXRodadas(dadosAposta);
        break;
    case 2:
        calcularComSaldoLimite(dadosAposta);
        break;
    case 3:
        exit(0);
        break;
    
    default:
        break;
    }
}

int main(){
    int selecao;   
    exibirMenu();
    selecao = selecionarMenu();
    processarSelecao(selecao);
}