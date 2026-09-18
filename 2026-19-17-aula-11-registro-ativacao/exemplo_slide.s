
/*
int g(int x);
int f(int i, int n) {
 int a = 0;
 while (n--) {
 a += g(i);
 i *= 2;
 }
 return a;
}
*/

.text

# int g(int x)

// int f(int i, int n) {
.globl f
f:
//  Criar o RA da função chamada
    pushq %rbp
//  int a = 0;
//  while (n--) {
//  a += g(i);
//  i *= 2;
//  }
//  return a;
// }