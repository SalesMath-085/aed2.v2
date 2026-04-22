#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <time.h>

int* cria_vetor(int tam);
void ler_vet(int*vet, int tam);
int busca_sequencial(int*vet, int tam,int chave);
int busca_binaria(int*vet, int tam, int chave);
void calcula_estatistica(double tempo[],int tam,char*algoritmo);
int* cria_vetor_ordenado(int tam);
void questao_1(int* vetor_de_1milhao);
typedef struct tipoNo{
    int dados;
    struct tipoNo* prox;
} tipoNo;

typedef struct tipoLista{
    tipoNo* prim;
    tipoNo* ult;
} tipoLista;

void criarLista(tipoLista*lista); 
void insereNaLista(tipoLista* lista, int vetor[], int tam);
int buscaSequencial(tipoLista* lista, int valor);
void questao_2(int*vetor_de_1milhao);
double calcular_diferenca(struct timespec s, struct timespec e);


#endif