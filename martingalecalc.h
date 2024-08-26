#ifndef MARTINGALECALC_H
#define MARTINGALECALC_H

struct Aposta {
    double odd;        // Armazena a odd da aposta
    double metaGanho;  // Armazena a meta de ganho
    int rodadas;       // Armazena o número de rodadas
    double stake;      // Armazena o valor da aposta (stake)
};

// Prototipos das funções
void calcularXRodadas(struct Aposta *aposta);
void calcularComSaldoLimite(struct Aposta *aposta);

#endif