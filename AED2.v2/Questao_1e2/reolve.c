#include "programa.h"
#include "stdlib.h"
#include "stdio.h"

#define tam 1000000

int main(){
    int*vetor1milhao=cria_vetor(tam);
    questao_1(vetor1milhao);
    questao_2(vetor1milhao);
}