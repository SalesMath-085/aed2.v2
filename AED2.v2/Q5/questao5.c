#include "../q_1e2_aed/programa.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(){
    double time_seq_ch_certeza[10],time_seq_ch_talvez[10], time_bin_ch_certeza[10], time_bin_ch_talvez[10];
    double time_seq_ch_certeza_2[10], time_seq_ch_talvez_lista[10];
    int chave;
    int tamanho=100000;
    int i=0,ind1=0;
    struct timespec start, end;
    for(i=1;i<=10;i++){
        tamanho=100000*i;
        int*vetorprincipal = cria_vetor(tamanho);
        chave=vetorprincipal[rand()%tamanho];
            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_sequencial(vetorprincipal,tamanho,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

            time_seq_ch_certeza[ind1]=calcular_diferenca(start,end);

       
        chave=rand()+tamanho;
            
            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_sequencial(vetorprincipal,tamanho,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

            time_seq_ch_talvez[ind1]=calcular_diferenca(start,end);


        int*vetorordenado = cria_vetor_ordenado(tamanho);

        chave=vetorordenado[rand()%tamanho];
            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_binaria(vetorordenado,tamanho,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

            //double tempo_gasto = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

            time_bin_ch_certeza[ind1]=calcular_diferenca(start,end);

        chave=rand()+tamanho;

            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_binaria(vetorordenado,tamanho,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//
            
            //double tempo_gasto = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

            time_bin_ch_talvez[ind1]=calcular_diferenca(start,end);

        tipoLista listaprincipal;
        criarLista(&listaprincipal);
        insereNaLista(&listaprincipal,vetorprincipal,tamanho);
        chave=vetorprincipal[rand()%tamanho];

            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_binaria(vetorordenado,tamanho,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

        time_seq_ch_certeza_2[ind1]=calcular_diferenca(start,end);

            timespec_get(&start, TIME_UTC); //incia o timer//
            buscaSequencial(&listaprincipal,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

        time_seq_ch_talvez_lista[ind1]=calcular_diferenca(start,end);
        ind1++;

    }

    for(int i=0;i<10;i++){
        printf("%.8f",time_seq_ch_certeza[i]);
        printf("    %.8f",time_seq_ch_talvez[i]);
        printf("    %.8f",time_bin_ch_certeza[i]);
        printf("    %.8f",time_bin_ch_talvez[i]);
        printf("    %.8f",time_seq_ch_certeza_2[i]);
        printf("    %.8f\n",time_seq_ch_talvez_lista[i]);
    }
   
    int n=10;

    calcula_estatistica(time_seq_ch_certeza,n,"busca sequencial no vetor, com chave no vetor");
    calcula_estatistica(time_seq_ch_talvez,n,"busca sequencial no vetor, chave pode nao existir");
    calcula_estatistica(time_bin_ch_certeza,n,"busca binaria no vetor, chave dentro do vetor");
    calcula_estatistica(time_bin_ch_talvez,n,"busca binaria vetor, chave pode nao exisitr");
    calcula_estatistica(time_seq_ch_certeza_2,n,"busca binaria na lista, com chave no vetor");
    calcula_estatistica(time_seq_ch_talvez_lista,n,"busca binaria na lista, chave pode nao existir");
    
}