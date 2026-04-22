#include "../q_1e2_aed/programa.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(){
    double tempo_da_busca_sequencial[20], tempo_da_busca_binaria[20];
    int chave;
    int tamanho=100000;
    int i=0,ind1=0,ind2=1;
    struct timespec start, end;
    for(i=1;i<=10;i++){
        tamanho=100000*i;
        int*vetorprincipal = cria_vetor(tamanho);
        chave=vetorprincipal[rand()%tamanho];
            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_sequencial(vetorprincipal,tamanho,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

            tempo_da_busca_sequencial[ind1]=calcular_diferenca(start,end);

       
        chave=rand()+tamanho;
            
            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_sequencial(vetorprincipal,tamanho,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

            tempo_da_busca_sequencial[ind2]=calcular_diferenca(start,end);


        int*vetorordenado = cria_vetor_ordenado(i*100000);
        tipoLista listaordenada;
        criarLista(&listaordenada);
        insereNaLista(&listaordenada,vetorordenado,tamanho);
        chave=vetorordenado[rand()%tamanho];

            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_binaria(vetorordenado,tamanho,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

        tempo_da_busca_binaria[ind1]=calcular_diferenca(start,end);

            timespec_get(&start, TIME_UTC); //incia o timer//
            buscaSequencial(&listaordenada,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

        tempo_da_busca_binaria[ind2]=calcular_diferenca(start,end);
        ind1=ind1+2;
        ind2=ind2+2;

    }

    for(int i=0;i<20;i=i+2){
        printf("%.8f",tempo_da_busca_sequencial[i]);
        printf("    %.8f\n",tempo_da_busca_binaria[i+1]);
    }
    int n=20;
    calcula_estatistica(tempo_da_busca_sequencial,n,"busca sequencial");
    calcula_estatistica(tempo_da_busca_binaria,n,"busca binaria");
}