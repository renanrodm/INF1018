/*
int main(void){

    int square = 0;
    
    for(int i = 1; i <= 10; i++) {
        square = i;
        square = square * square;
        printf("%d\n", square);
    }
    return 0;
}
*/

.data
Sf2: .string "\n"    /* segunda string de formato para printf */
Sf:  .string "%d\n"

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/

  movq $1, %r12 /* i = 1 */
  movl $1, %eax /* square = 1 */

L1:
  cmpq  $11, %r12  /* if (i == 11) ? */
  je    L2          /* goto L2 */
  movl  %r12d, %eax /* square = i*/
  imull %eax, %eax  /* square = square * square */ 


/*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/

  addq  $1, %r12  /* r12 += 1; */
  jmp  L1         /* goto L1; */

L2:  
/*************************************************************/
/* este trecho imprime o \n (estraga %eax)                  */
  movq    $Sf2, %rdi    /* primeiro parametro (ponteiro)*/
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/

/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq    -16(%rbp), %r12 /* recupera r12 */
  movq    -8(%rbp), %rbx  /* recupera rbx */
  leave
  ret      
/***************************************************************/