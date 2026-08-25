#include <stdio.h>


int main(void){
    char a;
    unsigned char b;

    short i;
    unsigned short j;
    int x;
    unsigned int y;

    a = 25;
    b = a;
    printf("a = %hhd, b = %hhu\n", a , b);

    a = -25;
    b = a;
    printf("a = %hhd, b = %hhu\n", a , b);
    printf("a = %hhd, a = %hhu\n", a , a);


    x = -129;
    y = x;
    i = x;
    j = x;
    a = x;
    b = x;

    printf("x = %d, y = %u\n", x, y);
    printf("i = %hd, j = %hu\n", i, j);
    printf("a = %hhd, b = %hhu\n", a , b);
    /*
    -129 -> 129
    32bits c/ sinal
    129 = 128 + 1
    128 = 1000 0000
    129 = 1000 0001
    129 -> 0000 0000 0000 0000 0000 0000 1000 0001
(inv)129-> 1111 1111 1111 1111 1111 1111 0111 1110
                                                +1
    ----------------------------------------------
           1111 1111 1111 1111 1111 1111 0111 1111 <- esse é o valor guardado na variavel a,
           que so tem valor para 8 bits. Pegando só 8 bits do valor, ficamos com:
           0111 1110 -> a = 127!!!! positivo por conta do zero!!!

    */
    
    a = 127; // 0111 1111
    printf("a = %hhd, b = %hhu\n", a , a);
    a++; // 1000 0000
    printf("a = %hhd, b = %hhu\n", a , a);

    return 0;
}