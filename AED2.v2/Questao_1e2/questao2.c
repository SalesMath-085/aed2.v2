#include "../tads/programa.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 1000000

void questao_2(int*vetor_de_1milhao){
    struct timespec start, end;
    int quantidades_de_repeticoes=30;
    int chave;
    int n=quantidades_de_repeticoes;
    double tempo_da_busca_vetor[n];
    double tempo_da_busca_lista[n];
    //int*vetor_de_1milhao=cria_vetor(tam);
    tipoLista lista_de_1milhao;

    criarLista(&lista_de_1milhao);
    insereNaLista(&lista_de_1milhao,vetor_de_1milhao,tam);

    //TESTE BUSCA SEQUENCIAL VETOR DESORDENADO//
    int x=0;
    int y=0;
    for(int repeticoes_acumuladas=0;repeticoes_acumuladas<quantidades_de_repeticoes;repeticoes_acumuladas++){

            if(repeticoes_acumuladas<15){
                chave=vetor_de_1milhao[rand()%tam];
            }else{
                chave= rand() + tam;
            }
            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_sequencial(vetor_de_1milhao,tam,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

            //double tempo_gasto = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

            tempo_da_busca_vetor[y]=calcular_diferenca(start,end);
            y++;
        
            //chave=rand()%tam;
            
            timespec_get(&start, TIME_UTC);//incia o timer//
            buscaSequencial(&lista_de_1milhao,chave);
            timespec_get(&end, TIME_UTC);//finaliza o timer//

            //double tempo_gasto = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

            tempo_da_busca_lista[x]=calcular_diferenca(start,end);
            x++;
        }

    printf("___________________________________________\n");
    printf("################ QUESTAO 2 ################\n");
    printf("\n");
    printf("RODADAS    BUSCA SEQUENCIAL NO VETOR    BUSCA SEQUENCIAL NA LISTA\n");
    for(int i=0;i<30;i++){
        printf("RODADA %i    ",i);
        printf("%.8lf                    ",tempo_da_busca_vetor[i]);
        printf("%.8lf ", tempo_da_busca_lista[i]);
        printf("\n");
        
    }
    //printf("____________________________________________\n");
    
    calcula_estatistica(tempo_da_busca_vetor, n,"Busca Sequencial no vetor");
    calcula_estatistica(tempo_da_busca_lista, n,"Busca Sequencial na lista");

}