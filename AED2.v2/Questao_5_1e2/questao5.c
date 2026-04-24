#include "programa.h"
#include "../tads/arq.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(){
    double tempo_seq_vetor[10],tempo_bin_vetor[10],tempo_seq_lista[10];
    int chave;
    int tamanho=100000;
    int i=0,ind1=0;
    struct timespec start, end;
    for(i=1;i<=10;i++){
        tamanho=100000*i;
        int*vetorprincipal = cria_vetor(tamanho);
        chave=-1;
            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_sequencial(vetorprincipal,tamanho,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

        tempo_seq_vetor[ind1]=calcular_diferenca(start,end);

        int*vetorordenado = cria_vetor_ordenado(tamanho);

            timespec_get(&start, TIME_UTC); //incia o timer//
            busca_binaria(vetorordenado,tamanho,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

        tempo_bin_vetor[ind1]=calcular_diferenca(start,end);

        tipoLista listaprincipal;
        criarLista(&listaprincipal);
        insereNaLista(&listaprincipal,vetorprincipal,tamanho);

            timespec_get(&start, TIME_UTC); //incia o timer//
            buscaSequencial(&listaprincipal,chave);
            timespec_get(&end, TIME_UTC); //finaliza o timer//

        tempo_seq_lista[ind1]=calcular_diferenca(start,end);

        free(vetorprincipal);
        free(vetorordenado);

        ind1++;

    }

    printf("___________________________________________\n");
    printf("################ QUESTAO 5 (1 e 2) ################\n");
    printf("\n");
    printf("RODADAS    BUSCA SEQUENCIAL VETOR    BUSCA BINARIA VETOR    BUSCA SEQUENCIAL LISTA\n");

    for(int i=0;i<10;i++){
        printf("RODADA %i    ",i+1);
        printf("%.8f",tempo_seq_vetor[i]);
        printf("                   %.8f",tempo_bin_vetor[i]);
        printf("                   %.8f\n",tempo_seq_lista[i]);
    }
    
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
}