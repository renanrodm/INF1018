/*
Dicionario      Var
rbx             p
r8d             max
r9d             i
*/


#include <stdio.h> /* Aqui n precisa traduzir, será pre-processado.*/
#include "dados.h" /* Aqui n precisa traduzir, será pre-processado.*/

.data
Sf: .string "%d\n"

.text /* Tradução indicando o início do código */

# int main() 
.globl main 
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/

#  int i;

#  St *p = dados; /**/
/*  St *p; Não há tradução direta para essa instrução. O que sabemos é que ela tem 8 bytes por ser um ponteiro*/
#   p = dados;
    movq $rdx, %rbx
#  int max = 0;
#  int max;
#  max = 0; 4 bytes = 32bits 
   movl $0, %r8d
#  for (i = 0; i <3; i++) { QUEBRANDO O FOR EM WHILE
#   i = 0 
    movl    $0, %r9d
WHILE:
#   while(i<3) { isso é falso quando i for maior ou igual a 3.
    cmpl    $3, %r9d 
    jge FORA_WHILE /*jump if maior ou igual*/     
#//     if (p->cc && p->ci > max)
#        if (p->cc != 0 && p->ci > max)
#        1º comparar p->cc com 0
        cmpb    $0, (%rbx)
        jz      FORA_IF 
        #2º comparar p->ci > max
        cmpl    %r8d, 4(%rbx)
        jle     FORA_IF

#       max = p->ci;
        movl    4(%rbx), %r8d
FORA_IF:                                 
#     p++;
      addq      $8, %rdx  
#     i++;
      addl      $1, %r9d 
      jmp         WHILE
FORA_WHILE: 



#  printf("%d\n",max);
    movl %r8d, %eax  #para aproveitar o epílogo abaixo, movo o r8d para o eax
/*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/
#  return 0;
/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq    -16(%rbp), %r12 /* recupera r12 */
  movq    -8(%rbp), %rbx  /* recupera rbx */
  leave
  ret      
/***************************************************************/