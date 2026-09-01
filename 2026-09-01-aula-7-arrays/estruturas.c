#include <stdio.h>



struct s1 {
    int a;
    char b;
    int c;
};


struct s2 {
    int a;
    int c;
    char b;
};

struct s3 {
    int i1;
    char c1;
    int i2;
    char c2;
};

struct s4 {
    int i1;
    char c1;
    char c2;
    int i2;
};


int main (void)
{
    printf("tamanho de struct s1 = %ld\n", sizeof(struct s1)); // apesar da estrutura ter 9 bytes, o paddging faz com que o tamanho seja 12 bytes, pois o compilador adiciona 3 bytes de padding entre o char b e o int c, para garantir que o int c esteja em um endereço multiplo de 4 bytes.
    printf("tamanho de struct s2 = %ld\n", sizeof(struct s2)); // apesar da estrutura ter 9 bytes, o paddging faz com que o tamanho seja 12 bytes, pois o compilador adiciona 3 bytes de padding entre o char b e o int c, para garantir que o int c esteja em um endereço multiplo de 4 bytes.
    printf("tamanho de struct s3 = %ld\n", sizeof(struct s3)); // apesar da estrutura ter 10 bytes, o paddging faz com que o tamanho seja 16 bytes, pois o compilador adiciona 2 bytes de padding entre o char c1 e o int i2, para garantir que o int i2 esteja em um endereço multiplo de 4 bytes. E depois adiciona mais 2 bytes de padding entre o char c2 e o final da estrutura, para garantir que a estrutura inteira esteja em um endereço multiplo de 4 bytes. Ou seja, a posição dos elementos da estrutura é importante para o tamanho final da estrutura, e o compilador adiciona padding para garantir que os elementos estejam alinhados na memória.
    printf("tamanho de struct s4 = %ld\n", sizeof(struct s4)); // apesar da estrutura ter 10 bytes, o paddging faz com que o tamanho seja 12 bytes, pois o compilador adiciona 2 bytes de padding entre o char c2 e o int i2, para garantir que o int i2 esteja em um endereço multiplo de 4 bytes. Ou seja, a posição dos elementos da estrutura é importante para o tamanho final da estrutura, e o compilador adiciona padding para garantir que os elementos estejam alinhados na memória.

    //A REGRA É: A ESTRUTURA PRECISAR TER CAMPOS ALOCADOS EM ENDEREÇOS MÚLTIPLOS DO TAMANHO DO TIPO DE DADO. E O COMPILADOR ADICIONA PADDING PARA GARANTIR ISSO.

    return 0;
}