#include <stdio.h>


void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

struct X{
  int a; // 4 bytes;
  short b; // 2 bytes;
  int c; // 4 bytes; haverá padding aqui!!! 
} x = {0xa1a2a3a4, 0xb1b2, 0xc1c2c3c4};

struct X1 {
  char c1; // 1 byte
  int i; // 4 bytes (padding para esse cara)
  char c2; // 1 byte
} x1 = {'a', 0xa1a2a3a4, 'b'};

struct X2 {
  long l; // 8 bytes
  char c; // 1 byte + 7 bytes (padding externo) = 16 bytes
} x2;

struct X3 {
  int i; // 4 bytes
  char c1; // 1 byte 
  char c2; // 1 byte + 2 bytes (padding) = 8 bytes
} x3;

struct X4 {
  struct X2 x; // 16 bytes
  char c; // 1 byte + 7 bytes (padding) = 24 bytes.
} x4;


struct X5 {
  char c1;
  char c2;
  char c3;
} x5;

struct X6 {
  short s1; // 2 bytes + 2 bytes (padding para alinhar o int)
  int i; // 4 bytes (maior tipo)
  char c[3]; // 3 byte
  short s2; // 2 bytes + 3 bytes (padding para alinhar tamanho final)
} x6;

union U1 {
  int i;
  char c[5];
} u1;


union U2 {
  short s;
  char c[5];
} u2;

int main(void){
  int i,j;
  int b[2]; //[int, int] = int 4 bytes = 8 bytes;
  short a[2][3]; //[[short, short, short], [short, short, short]] = short = 2 bytes;


  for( i=0; i<2;i++){
    b[i] = i;
    for (j=0; j<3;j++){
      a[i][j] = (3*i) + j;
    }
  }
  // b = [0, 1]
  // a = [[0, 1, 2], [3, 4, 5]]

  printf ("b: \n");
  dump (b, sizeof(b));
  printf ("a: \n");
  dump (a, sizeof(a));

  /*
  Q1 -> 'int b[2]' possui 8 bytes, pois é um array de 2 elementos do tipo int (4 bytes). 'short a[2][3]' possui 12 bytes, pois é um elemento do tipo short (2 bytes) replicado 3 vezes para cada linha, logo, 2 (linhas) x 3 (colunas) = 6 elementos do tipo short = 12 bytes.
  */

  printf("struct x: \n");
  dump(&x, sizeof(x));
  printf("tamanho em bytes da estrutura x: %ld\n", sizeof(x));

  /*
  Q2 -> Existe um buraco nos endereços 0x5841ffba1016 e 0x5841ffba1017. Trata-se de um padding interno, pois o próximo elemento a ser adicionado no array é um int (4 bytes) e, de acordo com a regra de alinhamento do C, onde cada elemento é posicionado em endreços múltiplos do seu próprio tamanho, o próximo endereço que atende esse requesito é o 0x5841ffba1018, onde de fato foi armazenado o int. Dessa forma, a solução para o alinhamento foi preencher com 00's o buraco que vai de 1016 até 1017.
  */

  printf("struct x1: \n");
  dump(&x1, sizeof(x1));
  printf("tamanho em bytes da estrutura x1: %ld\n", sizeof(x1));

  /*
  Q3A -> Para o struct x1 temos 12 bytes. Nesse caso, há dois paddings. O primeiro é interno para preenchimento do próximo int no endereço 0x...4024, e o segundo é no final, para garantir que o tamanho total da struct seja obrigariamente um múltiplo do seu membro mais 'pesado', no caso, o int (4 bytes). Dessa forma, eu posso colocar essa struct dentro de um array respeitando a regra de alinhamento. 
  Caso contrário, se a struct terminasse em 9 bytes, como parece ser inicialmente apenas com o padding interno, em um array o elemtento 1 ocuparia os endereços de 0 a 8, enquanto o segundo elemento começaria no endereço 9, que não é múltiplo de 4, quebrando a regra de alinhamento.
  */

  printf("struct u1: \n");
  dump(&u1, sizeof(u1));
  printf("tamanho em bytes da estrutura u1: %ld\n", sizeof(u1));
  
  
  printf("struct x2: \n");
  dump(&x2, sizeof(x2));
  printf("tamanho em bytes da estrutura x2: %ld\n", sizeof(x2));
  /*
  Q3(b) --> Tamanho 16 bytes. O maior elemento custa 8 bytes, logo, precisamos de um padding de + 7 bytes depois do char para alinhamento.
  */


  printf("struct x3: \n");
  dump(&x3, sizeof(x3));
  printf("tamanho em bytes da estrutura x3: %ld\n", sizeof(x3));
  /*
  Q3(c) --> Tamanho total = 8 bytes. O tamanho inicial da estrutura são 6 bytes, tendo int (4 bytes) como maior elemento. 
  Dessa forma, o múltiplo mais próximo depois de 6 é 8, sendo necessário + 2 bytes de padding.
  */

  printf("struct x4: \n");
  dump(&x4, sizeof(x4));
  printf("tamanho em bytes da estrutura x4: %ld\n", sizeof(x4));
  /*
  Q3(d) --> Tamanho total de 24 bytes. Aqui quem dita o 'fator alinhamento' é o tipo individual do maior elemento, no caso, struct x2. O struct x2 tem como maior elemento individual o long ( 8 bytes), logo, o padding de 7 bytes coloca o próximo endereço no múltiplo de 8 maior que 17.
  */

  
  printf("struct x5: \n");
  dump(&x5, sizeof(x5));
  printf("tamanho em bytes da estrutura x5: %ld\n", sizeof(x5));
  /*
  Q3(3) --> Tamanho total de 3 bytes. Maior tipo char, que custa 1 byte.
  */

  printf("struct x6: \n");
  dump(&x6, sizeof(x6));
  printf("tamanho em bytes da estrutura x6: %ld\n", sizeof(x6));
  /*
  Q3(f) --> Tamanho total de 16 bytes. Aqui temos o padding interno para alinhar o int depois do short e um padding ao final para que a estrutura tenha um tamanho múltiplo do seu maior tipo: int (4 bytes).
  */

  /*
  Q3(g) --> No caso da união, temos 8 bytes. Por que haja um array de 5 posições, o maior tipo dentro dessa union é o int
  Dessa forma, como eles compartilham os mesmos endereços de memória E o array exige 1 byte a mais de tamanho que o int, o alinhamento pula para o próximo endereço múltiplo de 4.*/

  printf("struct u2: \n");
  dump(&u2, sizeof(u2));
  printf("tamanho em bytes da estrutura u2: %ld\n", sizeof(u2));
  /*
  Q3(h) --> Mesma lógica da questão de G, o maior tipo é o short de 2 bytes, logo, o alinhamento será puxado para o próximo multiplo de dois maior ou igual ao tamanho do array 'c[5]'. Nessa regra, teremos a u2 com tamanho de 6 bytes.
  */


  return 0;
}