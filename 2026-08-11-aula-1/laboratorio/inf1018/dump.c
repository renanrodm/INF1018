#include <stdio.h>


void dump(void *p, int n){
    unsigned char  *p1 = p; // char não negativo recebendo o ponteiro passado por parametro;
    while(n--){ //verifica se é diferente de zero, começando a partir de n, decrementando 1 a cada loop.
        printf("%d ", *p1);
        p1++; //incrementa 1 para andar com o ponteiro;
    }
}

//A função itera sobre o tamanho de um dado e retorna o conteúdo de cada posição;