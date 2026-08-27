#include <stdio.h>

/*
unsigned char (1byte) -> faixa de 0 a 255;
char (1byte) -> faixa de -128 a 127;

*/

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
    // char (1byte, 8 bits) -> faixa de -128 a 127;
    signed char c = 150; //esse valor estoura a faixa. Em binário, 150 é 1001 0110, o compilador vai olhar para o bit mais significativo
    //a esquerda (1) e interpretar como negativo, convertendo com o complemento a 2, que resulta em -106.
    //cabe na faixa de char.  
    printf("dump de c: \n");
    dump(&c, sizeof(c)); // resulta 
    printf("valor de c: %d\n", c); // resulta em -106
    
    short s = -3; // "signed short", 2 bytes ou 16 bits (valores de -32.768 até 32.767) e 
    //Logo, para essa situação, o valor -3 será interpretado corretamente. 
    printf("dump de s: \n");
    dump(&s, sizeof(s)); 
    printf("valor de s: %d\n", s); // resulta em -3
    
    int i = -151; //int (4bytes, 32bits) -> faixa de -2.147.483.648 até 2.147.483.647. Armazena uma grande quantidade de valores positivos e negativos.
    printf("dump de i: \n");
    dump(&i, sizeof(i));// olhando para o resultado desse dump, fica claro que o numero propagou 1s nos bits a esquerda para propagar o sinal negativo. 
    printf("valor de i: %d\n", i); //resulta em -151.

    printf("\n");
    printf("================== Q2 =========================\n");
    short l = -32765;
    unsigned short k = 32771; // unsigned short, 2 bytes e 16 bits (valores de 0 até 65.535). 
    printf("l=%d, k=%u \n", l, k);
    printf("dump de l: \n");
    dump(&l, sizeof(l));
        printf("valor de l: %d\n", l);
    printf("dump de k: \n");
    dump(&k, sizeof(k));
    printf("valor de k: %d\n", k);
    //O valor de k, que não cabe em unsigned short, 
    return 0;
}