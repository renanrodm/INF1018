#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
  signed char c = 150; //150 em binário é 1001 0110. O tipo char representa valores de -128 a +127. Isso significa que 150 não cabe dentro desse tipo, ocasionando um overflow. Por ser um tipo que representa valores negativos, o C vai interpretar o bit mais significativo (mais a esquerda) como indicativo de sinal, utilizando -128 durante a conversão. Sendo assim, ao fim da conversão, o resultado será -106 decimal. Em hexa, 1001 = 9 e 0110 = 6. Logo, será impresso, considerando little-endian, 0x96.

  signed short s = -3; //-3 com complemento a 2 em binário é 1111 1111 1111 1101. O tipo com sinal está adequado para o numero. Sendo assim, será impresso seu valor sem problemas. Em hexa, 1111 = F e 1101 = D. Logo, considerando little-endian, será impresso 0xFDFF.

  signed int i = -151; //-151, em 32 bits, com complementos a 2 = 1111 1111 1111 1111 1111 1111 0110 1001. O tipo com sinal está adequado para o numero. Sendo assim, será impresso seu valor sem problemas. Logo, considerando little-endian, será impresso 0x69FFFFFF


  printf("dump de c: \n");
  dump(&c, sizeof(c));
  printf("dump de s: \n");
  dump(&s, sizeof(s));
  printf("dump de i: \n");
  dump(&i, sizeof(i));

  return 0;
}