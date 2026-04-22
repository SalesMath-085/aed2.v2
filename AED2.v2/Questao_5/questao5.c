#include "../Questao_1e2/programa.h"
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

    for(int i=0;i<10;i++){
        printf("%.8f",tempo_seq_vetor[i]);
        printf("    %.8f",tempo_bin_vetor[i]);
        printf("    %.8f\n",tempo_seq_lista[i]);
    }
    
}