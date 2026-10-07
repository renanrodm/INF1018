#include <stdio.h>

unsigned char switch_byte(unsigned char x)
{
    //A = 1010 e B = 1011, logo, temos AB = 1010 1011

    unsigned char a = x << 4; // movendo 4 bits para esquerda, ficamos com 1011 0000
    unsigned char b = x >> 4; // movendo 4 bits para direita, ficamos com  0000 1010
    unsigned char c = a | b; // fazendo 1011 0000 OU 0000 1010 = 1011 1010 (B A)

    return c;
}


int main() {
    unsigned char x = 0xAB;
    unsigned char y = switch_byte(x);
    printf("%02x - %02x", x, y);
    return 0;
}