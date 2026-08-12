#include <stdio.h>

void dump (void *p, int n);

int main() {
  char c1 = 1;
  char c2 = '1';
  int i = 1;
  char v[] = "1";

  printf("valor de c1: %d -> na memória: ",c1);
  dump(&c1, sizeof(c1)); //args: endereço de memória e o tamanho do dado;

  printf("\nvalor de c2: %d -> na memória: ",c2);
  dump(&c2, sizeof(c2));

  printf("\nvalor de i: %d -> na memória: ",i);
  dump(&i, sizeof(i));

  printf("\nvalor de v: %s -> na memória: ",v);
  dump(v, sizeof(v));

  printf("\n");
  return 0;
}

//#P: O que você pode concluir sobre o armazenamento das variáveis c e i, e do vetor v?
//c1: um valor char não assinado simples, ocupando 1 byte na memória;
//c2: '1' é a string literal que é representada por 49 na tabela ASCII;
//i: uma variável inteira do tipo int, ocupando 4 bytes na memória;
//v: um vetor, tendo o início da string com 49 = '1' e o fim com 0 = '\o';
