#include <stdio.h>

unsigned char rotate_left(unsigned char x, int n)
{
    //0x61 = 0110 0001

    unsigned char a = x<<n;
    unsigned char b = x>>(8-n);
    unsigned char c = a | b;

    return c;
}


int main() {
    unsigned char x = 0x61;
    unsigned char y = rotate_left(x,1);
    unsigned char z = rotate_left(x,2);
    unsigned char w = rotate_left(x,7);
    printf("%02x\n", y);
    printf("%02x\n", z);
    printf("%02x\n", w);
    return 0;
}