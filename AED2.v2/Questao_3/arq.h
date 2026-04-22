#ifndef ARQ_H
#define ARQ_H

#define TAM 100000
#define RODADAS 10

void bubbleSort(int lista[], int n);
void insertionSort(int lista[], int n);
void selectionSort(int lista[], int n);
void quickSort(int lista[], int ini, int fim);
void mergeSort(int lista[], int esq, int dir);
int* gerar_vetor(int* vetor, int n);
int* copiar_vetor(int copia[], int orig[], int n);

double medir_tempo(void (*sort_func)(int[], int), int vetor[], int n);
double medir_tempo_2(void (*sort_func)(int[], int, int), int vetor[], int ini, int fim);
void exibir_resultados(int rodadas, double tempos[5][RODADAS], double somas[5]);

#endif
