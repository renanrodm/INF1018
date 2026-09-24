/*
int acerta (int u[], int i)
{
return u[i];
}
*/
/*
Dicionário
Reg     Var 
rdi     u   <- obrigatório, 1º arg.
esi     i   <- obrigatório, 2º arg.
*/

# não há .data porque porque não há variáveis globais nem strings constantes

.text

# int acerta (int u[], int i)
# int acerta (int *u, int i)
.globl acerta
acerta:
    #1 - Toda funcao começa criando seu RA 
    pushq %rbp #salvando o RA da funcao chamadora 
    movq %rsp, %rbp #RPB aponta para a base do RA da funcao chamadora 
    subq $???, %rsp #alocando espaço para o RA da funcao chamada 

    #2 - salvar os registradores callee-saved que serão usados

# return u[i];
# temp = 4 * i 
    imull $4, %esi # esi = 4 * i
    movslq %esi, %rsi # rsi = (long) esi
    addq %rsi, %rdi # rdi = u + (4 * i)
    movl (%rdi), %eax #eax = u[i] isso é o nosso return.

    #Para terminar função:

    #Restaurar os registradores callee-saved que foram salvos
    #movq %rbp, %rsp         #Destruir o RA da função chamada 
    #popq %rbp               #Restaurar o RA da função chamadora 
    leave                    #Destruir o RA da função chmada a restaurar o RA da função chamadora
    
    #Retornar para função chamadora
    ret 