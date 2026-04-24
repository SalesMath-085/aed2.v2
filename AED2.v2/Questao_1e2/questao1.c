#include "../tads/programa.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 1000000


void questao_1(int* vetor_de_1milhao){
    int quantidades_de_repeticoes=30;
    int chave=0;
    double tempo_da_busca_sequencial[quantidades_de_repeticoes], tempo_da_busca_binaria[quantidades_de_repeticoes];
    //vetor_de_1milhao=cria_vetor(tam);
    struct timespec start, end;

    //TESTE BUSCA SEQUENCIAL VETOR DESORDENADO//
    for(int repeticoes_acumuladas=0;repeticoes_acumuladas<quantidades_de_repeticoes;repeticoes_acumuladas++){
        if(repeticoes_acumuladas<15){
            chave=vetor_de_1milhao[rand()%tam];
            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_sequencial(vetor_de_1milhao,tam,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//
            
            //double tempo_gasto = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
            tempo_da_busca_sequencial[repeticoes_acumuladas]=calcular_diferenca(start,end);

        }else{
            chave=rand()+tam;
            
            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_sequencial(vetor_de_1milhao,tam,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

           //double tempo_gasto = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

            tempo_da_busca_sequencial[repeticoes_acumuladas]= calcular_diferenca(start,end);
        }
    }

    ///// CRIA VETOR ORDENADO ////////////
    int*vetor_de_1milhao_ordenado=cria_vetor_ordenado(tam);


    for(int repeticoes_acumuladas=0;repeticoes_acumuladas<quantidades_de_repeticoes;repeticoes_acumuladas++){
        if(repeticoes_acumuladas<15){
            chave=vetor_de_1milhao_ordenado[rand()%tam];
            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_binaria(vetor_de_1milhao_ordenado,tam,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

            //double tempo_gasto = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

            tempo_da_busca_binaria[repeticoes_acumuladas]=calcular_diferenca(start,end);

        }else{
            chave=rand()+tam;

            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_binaria(vetor_de_1milhao_ordenado,tam,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//
            
            //double tempo_gasto = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

            tempo_da_busca_binaria[repeticoes_acumuladas]=calcular_diferenca(start,end);
        }
    }


    //  MOSTRA OS TEMPOS DE EXECUCAO E ESTATISTICAS //
    printf("___________________________________________\n");
    printf("################ QUESTAO 1 ################\n");
    printf("\n");
    printf("RODADAS    BUSCA SEQUENCIAL    BUSCA BINARIA\n");


    for(int i=0;i<quantidades_de_repeticoes;i++){
        printf("RODADA %i    ",i);
        printf("%.8f    ",tempo_da_busca_sequencial[i]);
        printf("%.8f\n",tempo_da_busca_binaria[i]);
    }
    calcula_estatistica(tempo_da_busca_sequencial,quantidades_de_repeticoes,"busca sequencial");
    calcula_estatistica(tempo_da_busca_binaria, quantidades_de_repeticoes,"busca binaria");


}