#include <stdio.h>

int odd_ones(unsigned int x) 
{
  /* escreva seu código aqui */

    int cont = 0;
    while(x)
    {
        if(x & 1){
            cont=cont^1; //o xor vai funcionar como interrupetor, alternando entre 0 e 1, dependendo da quantidade de cada valor no numero.
            //se tiver uma maior quantidade de bits 1, termina com interruptor no 1. Caso contrário, termina no 0.
        }
        x = x >> 1;
    }
    
    return cont;
}


int main() {
  printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
  printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");
  return 0;
}