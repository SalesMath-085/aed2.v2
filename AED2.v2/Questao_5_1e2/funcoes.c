#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "programa.h"
#include <time.h>
#include <math.h>

void insereNaLista(tipoLista* lista, int vetor[], int tam){
    int i = 0;
    tipoNo* aux;
    
    aux = (tipoNo*)malloc(sizeof(tipoNo));
    aux->prox = NULL;

    if (lista->prim == NULL){
        lista->prim = aux;
        lista->ult = aux;
        aux->dados = vetor[i];
    }

    for (i = 1; i < tam; i++){
    aux = (tipoNo*)malloc(sizeof(tipoNo));
    aux-> dados = vetor[i];
    aux->prox = NULL;
    lista->ult->prox = aux;
    lista->ult = aux;;
    }
}

int buscaSequencial(tipoLista* lista, int chave){
    tipoNo* aux = lista->prim;
    while (aux != NULL){
        if (aux->dados == chave){
        return chave;
       }
       else{aux = aux->prox;}
    }
    return 0;
}

void criarLista(tipoLista*lista){
    lista->prim=NULL;
    lista->ult=NULL;
}

int busca_sequencial(int*vet, int tam,int chave){
    for(int x=0;x<tam;x++){
        if(vet[x]==chave){
            return 1;
        }
    }
    return 0;
}

int busca_binaria(int*vet, int tam, int chave){
    int inicio=0, fim=tam-1, meio;
    while(inicio<=fim){
        meio=(inicio+fim)/2;
        if(vet[meio]==chave){
            return 1;
        }
        if(vet[meio]<chave){
            inicio=meio+1;
        }else{
            fim=meio-1;
        }
    }
    return 0;
}

int* cria_vetor(int tam){
    int *vet;
    srand(time(NULL));
    vet=(int*)malloc(tam * sizeof(int));
    for(int x=0;x<tam;x++){
        vet[x]=rand();
    }
    return(vet);
}

int* cria_vetor_ordenado(int tam){
    int atual=0,aleatorio;
    int *vet=(int*)malloc(tam*sizeof(int));
    srand(time(NULL));
    for(int i=0;i<tam;i++){
        atual+=(rand() % 10)+1;
        vet[i]=atual;
    }
    return(vet);
}

void ler_vet(int*vet, int tam){
    for(int n=0;n<tam;n++){
        printf("%d ",vet[n]);
    }
    printf("------------------");
}

void calcula_estatistica(double tempo[],int tam,char*algoritmo){
    double media=0,desvio_padrao=0,soma=0;

    for(int i=0;i<tam;i++){
        soma=tempo[i]+soma;
    }
    media=soma/tam;

    soma=0;

    for(int i=0;i<tam;i++){
        soma += pow(tempo[i]-media,2);
    }
    desvio_padrao=sqrt(soma/tam);;
    
    printf("____________________________________________________\n");
    printf("\n");
    printf("Media do tempo de execucao do %s: %.8f segundos\n",algoritmo,media);
    printf("Desvio padrao do tempo de execucao do %s: %.8f segundos\n",algoritmo,desvio_padrao);
    //printf("-------------------------------\n");
}

double calcular_diferenca(struct timespec s, struct timespec e) {
    if (e.tv_nsec < s.tv_nsec) {
        e.tv_sec -= 1;
        e.tv_nsec += 1000000000;
    }
    return (double)(e.tv_sec - s.tv_sec) + (double)(e.tv_nsec - s.tv_nsec) / 1e9;
}