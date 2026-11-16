#include <stdio.h>
#include <stdlib.h>
#include "gera_codigo.h"

int main(int argc, char *argv[]) {
  FILE *fp;
  unsigned char code[500];
  funcp funcLBS;
  int res;

  if (argc != 2) {
    printf("Uso: %s <arquivo.lbs>\n", argv[0]);
    return 1;
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("Erro ao abrir arquivo");
    return 1;
  }

  gera_codigo(fp, code, &funcLBS);
  fclose(fp);

  if (funcLBS == NULL) {
    printf("Nenhuma funcao gerada (entry == NULL).\n");
    return 1;
  }

  // Chama a função gerada passando 10 como exemplo de parâmetro p0
  res = (*funcLBS)(10);
  printf("Resultado: %d\n", res);

  return 0;
}