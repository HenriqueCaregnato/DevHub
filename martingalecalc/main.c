/*****************************************************
 * Programa: Martingale Simulator
 * Autor: Henrique Caregnato
 * Data: 27/08/2024
 * Descrição: Este programa calcula o saldo máximo
 * necessário para uma sequência consecutiva de perdas
 * utilizando a estratégia Martingale.
 *****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "martingalecalc.h"

//Variaveis globais
struct Aposta *dadosAposta; //para ecomizar recursos futuramente

void exibirMenu(){
    double odd, metaGanho, rodadas, stake;
    printf("#####################################\n");
    printf(" Martingale Calc\n");
    printf("#####################################\n");
    printf("Escolha uma opção\n");
    printf("1. Calcular 'n' rodadas\n");
    printf("2. sair\n");
}

int selecionarMenu(){
    int selecao;
    scanf("%d", &selecao);
    return selecao;
}

void pegarDadosAposta(int opcao){
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
}

void travaParaContinuar(){
    printf("Presione ENTER para continuar");
    getchar();//para consumir o '\n' do buffer
    getchar();
}

int controlarFluxoSelecao(int selecao){
    double **matriz;
    switch (selecao)
    {
    case 1:
        pegarDadosAposta(1);
        matriz = calcularXRodadas(dadosAposta);
        exibirTabelaMartingale(matriz,dadosAposta);
        free(matriz);
        travaParaContinuar();
        break;
    case 2:
        exit(0);
        break;
    
    default:
        printf("Nenhuma seleção valida");
        break;
    }
}

int main(){
    int selecao;
    while(1){
        system("clear");
        exibirMenu();
        selecao = selecionarMenu();
        controlarFluxoSelecao(selecao);
    }   
}
