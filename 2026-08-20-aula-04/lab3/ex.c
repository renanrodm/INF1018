#include <stdio.h>

int odd_ones(unsigned int x) {
  /* escreva seu código aqui */
  int total_ligado = 0;
  while (x>0){
    total_ligado += (x & 1);
    x = x >> 1;
  }

  return total_ligado & 1;
}

int main(void) {
  unsigned int x = 0x87654321;
  unsigned int y, z;

  /* o byte menos significativo de x e os outros bits em 0 */
  y = x & 0x000000FF; 

  /* o byte mais significativo com todos os bits em '1' 
     e os outros bytes com o mesmo valor dos bytes de x */
  z = x | 0xFF000000;

  printf("%08x %08x\n", y, z);

  printf("--- QUESTÃO 2 ----\n");
  x = 0x87654321;
  printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
  printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");
}
