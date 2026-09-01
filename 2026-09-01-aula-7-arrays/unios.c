#include <stdio.h>


union u {
    char c;
    long l;
};

int main(void){
    union u x;
    printf("&x.l = %p\n &x.c = %p\n", &(x.l), &(x.c)); //comprova que eles tem o mesmo endereço, ou seja, ocupam o mesmo espaço na memória.
    x.c = 1;
    x.l = 2;

    printf("x.c = %hhd\nx.l = %ld\n", x.c, x.l); //aqui o valor de x.c é 2, pq o valor de x.l sobrescreveu o valor de x.c, pois eles ocupam o mesmo espaço na memória.

    x.l = 0xABCDEF0987654321;
    printf("x.c = %hhd\nx.l = %ld\n", x.c, x.l); //aqui o valor de x.c é 33, pq o valor de x.l sobrescreveu o valor de x.c, e o valor de x.c é o último

    return 0;
}