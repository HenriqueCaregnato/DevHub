#ifndef MARTINGALECALC_H
#define MARTINGALECALC_H

struct Aposta {
    double odd;        // Armazena a odd da aposta
    double metaGanho;  // Armazena a meta de ganho
    int rodadas;       // Armazena o número de rodadas
    double stake;      // Armazena o valor da aposta (stake)
    double saldoLimite;
};

// Protótipos das funções
double** calcularXRodadas(struct Aposta *aposta);
void exibirTabelaMartingale(double **matriz,struct Aposta *aposta);

#endif
