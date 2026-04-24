#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "../tads/arq.h"

void exibir_resultados(int rodadas, double tempos[5][RODADAS], double somas[5]) {
    printf("\n  resultado por tecnica \n");

    printf("\nBubbleSort\n");
    for (int r = 0; r < rodadas; r++) {
        printf("rodada %d : %.6f\n", r + 1, tempos[0][r]);
    }

    printf("\nInsertionSort\n");
    for (int r = 0; r < rodadas; r++) {
        printf("rodada %d : %.6f \n", r + 1, tempos[1][r]);
    }

    printf("\nSelectionSort\n");
    for (int r = 0; r < rodadas; r++) {
        printf("rodada %d : %.6f\n", r + 1, tempos[2][r]);
    }

    printf("\nQuickSort\n");
    for (int r = 0; r < rodadas; r++) {
        printf("rodada %d : %.6f\n", r + 1, tempos[3][r]);
    }

    printf("\nMergeSort\n");
    for (int r = 0; r < rodadas; r++) {
        printf("rodada %d : %.6f\n", r + 1, tempos[4][r]);
    }
    if(rodadas>1){
        printf("\n=== MEDIAS FINAIS ===\n");
        printf("BubbleSort:    %.6f\n", somas[0] / rodadas);
        printf("InsertionSort: %.6f\n", somas[1] / rodadas);
        printf("SelectionSort: %.6f\n", somas[2] / rodadas);
        printf("QuickSort:     %.6f\n", somas[3] / rodadas);
        printf("MergeSort:     %.6f\n", somas[4] / rodadas);

        double resQ = 0;
        double resS = 0;
        double resM = 0;
        double resB = 0;
        double resI = 0;

        for (int r = 0;r<rodadas;r++){
            resB += (pow(tempos[0][r] - (somas[0]/rodadas), 2)/(rodadas-1));
        }
        resB = sqrt(resB);
        for (int r = 0;r<rodadas;r++){
            resI += (pow(tempos[1][r] - (somas[1]/rodadas), 2)/(rodadas-1));
        }
        resI = sqrt(resI);
        for (int r = 0;r<rodadas;r++){
            resS += (pow(tempos[2][r] - (somas[2]/rodadas), 2)/(rodadas-1));
        }
        resS = sqrt(resS);
        for (int r = 0;r<rodadas;r++){
            resQ += (pow(tempos[3][r] - (somas[3]/rodadas), 2)/(rodadas-1));
        }
        resQ = sqrt(resQ);
        for (int r = 0;r<rodadas;r++){
            resM += (pow(tempos[4][r] - (somas[4]/rodadas), 2)/(rodadas-1));
        }
        resM = sqrt(resM);

        printf("QuickSort desvio padrao %.6f\n", (resQ));
        printf("Selection desvio padrao %.6f\n", (resS));
        printf("MergeSort desvio padrao %.6f\n", (resM));
        printf("BubbleSort desvio padrao %.6f\n", (resB));
        printf("InsertionSort desvio padrao %.6f\n", (resI));
    }
}

int* gerar_vetor(int*vetor, int n) {
    vetor=(int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 1000000; 
    }
    return(vetor);
}

int* copiar_vetor(int*copia, int*orig, int n) {
    copia=(int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        copia[i] = orig[i];
    }
    return(copia);
}

double medir_tempo(void (*sort_func)(int[], int), int vetor[], int n) {
    clock_t start = clock();
    sort_func(vetor, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

double medir_tempo_2(void (*sort_func)(int[], int, int), int vetor[], int ini, int fim) {
    clock_t start = clock();
    sort_func(vetor, ini, fim);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}