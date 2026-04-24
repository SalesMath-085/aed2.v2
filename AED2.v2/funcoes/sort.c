#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../tads/arq.h"

void trocar(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particao(int lista[], int ini, int fim) {
    int pivo = lista[fim];
    int i = (ini - 1);
    for (int j = ini; j <= fim - 1; j++) {
        if (lista[j] <= pivo) {
            i++;
            trocar(&lista[i], &lista[j]);
        }
    }
    trocar(&lista[i + 1], &lista[fim]);
    return (i + 1);
}

void bubbleSort(int lista[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                trocar(&lista[j], &lista[j + 1]);
            }
        }
    }
}

void insertionSort(int lista[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = lista[i];
        j = i - 1;
        while (j >= 0 && lista[j] > chave) {
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = chave;
    }
}

void selectionSort(int lista[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (lista[j] < lista[min_idx]) {
                min_idx = j;
            }
        }
        trocar(&lista[min_idx], &lista[i]);
    }
}

void quickSort(int lista[], int ini, int fim) {
    if (ini < fim) {
        int pi = particao(lista, ini, fim);
        quickSort(lista, ini, pi - 1);
        quickSort(lista, pi + 1, fim);
    }
}

void merge(int lista[], int esq, int m, int dir) {
    int n1 = m - esq + 1;
    int n2 = dir - m;
    int *E = (int*)malloc(n1 * sizeof(int));
    int *D = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) E[i] = lista[esq + i];
    for (int j = 0; j < n2; j++) D[j] = lista[m + 1 + j];
    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        if (E[i] <= D[j]) {
            lista[k++] = E[i++];
        } else {
            lista[k++] = D[j++];
        }
    }
    while (i < n1) lista[k++] = E[i++];
    while (j < n2) lista[k++] = D[j++];
    free(E);
    free(D);
}

void mergeSort(int lista[], int esq, int dir) {
    if (esq < dir) {
        int m = esq + (dir - esq) / 2;
        mergeSort(lista, esq, m);
        mergeSort(lista, m + 1, dir);
        merge(lista, esq, m, dir);
    }
}