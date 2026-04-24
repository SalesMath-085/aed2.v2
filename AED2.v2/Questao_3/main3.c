#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../tads/arq.h"

int main() {
    srand(time(NULL));

    int* vetor_original;
    int* vetor_teste;
    double tempos[5][RODADAS];
    double somas[5] = {0};

    for (int r = 0; r < RODADAS; r++) {
        printf("Rodada %d\n", r + 1);
        vetor_original = gerar_vetor(vetor_original, TAM);

        vetor_teste = copiar_vetor(vetor_teste, vetor_original, TAM);
        tempos[0][r] = medir_tempo(bubbleSort, vetor_teste, TAM);
        free(vetor_teste);

        vetor_teste = copiar_vetor(vetor_teste, vetor_original, TAM);
        tempos[1][r] = medir_tempo(insertionSort, vetor_teste, TAM);
        free(vetor_teste);

        vetor_teste = copiar_vetor(vetor_teste, vetor_original, TAM);
        tempos[2][r] = medir_tempo(selectionSort, vetor_teste, TAM);
        free(vetor_teste);

        vetor_teste = copiar_vetor(vetor_teste, vetor_original, TAM);
        tempos[3][r] = medir_tempo_2(quickSort, vetor_teste, 0, TAM - 1);
        free(vetor_teste);

        vetor_teste = copiar_vetor(vetor_teste, vetor_original, TAM);
        tempos[4][r] = medir_tempo_2(mergeSort, vetor_teste, 0, TAM - 1);
        free(vetor_teste);

        for (int i = 0; i < 5; i++) {
            somas[i] += tempos[i][r];
        }

        free(vetor_original);
    }

    printf("-------------------------------\n");
    exibir_resultados(RODADAS, tempos, somas);

    return 0;
}