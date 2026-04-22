#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arq.h"

int main() {
    srand(time(NULL));

    int tamanhos[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    int num_tamanhos = 10;


    for (int t = 0; t < num_tamanhos; t++) {
        int tamanho_atual = tamanhos[t];
        printf("\n  tamanho: %d\n", tamanho_atual);

        int* vetor_original;
        int* vetor_teste;
        double tempos[5][RODADAS];
        double somas[5] = {0};

        vetor_original = gerar_vetor(vetor_original, tamanho_atual);

        vetor_teste = copiar_vetor(vetor_teste, vetor_original, tamanho_atual);
        tempos[0][0] = medir_tempo(bubbleSort, vetor_teste, tamanho_atual);
        free(vetor_teste);

        vetor_teste = copiar_vetor(vetor_teste, vetor_original, tamanho_atual);
        tempos[1][0] = medir_tempo(insertionSort, vetor_teste, tamanho_atual);
        free(vetor_teste);

        vetor_teste = copiar_vetor(vetor_teste, vetor_original, tamanho_atual);
        tempos[2][0] = medir_tempo(selectionSort, vetor_teste, tamanho_atual);
        free(vetor_teste);

        vetor_teste = copiar_vetor(vetor_teste, vetor_original, tamanho_atual);
        tempos[3][0] = medir_tempo_2(quickSort, vetor_teste, 0, tamanho_atual - 1);
        free(vetor_teste);

        vetor_teste = copiar_vetor(vetor_teste, vetor_original, tamanho_atual);
        tempos[4][0] = medir_tempo_2(mergeSort, vetor_teste, 0, tamanho_atual - 1);
        free(vetor_teste);

        for (int i = 0; i < 5; i++) {
            somas[i] = tempos[i][0];
        }

        printf("-------------------------------\n");
        exibir_resultados(1, tempos, somas);

        free(vetor_original);
    }
    return 0;
}
