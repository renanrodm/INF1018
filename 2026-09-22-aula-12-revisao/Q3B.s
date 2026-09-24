/*
struct S
{
int v;
struct S *prox;
};
extern int norma[];
int boo(struct S *s, int n)
{
int acum = 0;
while (s)
{
s->v = acerta(norma, n+acum);
acum += n;
s = s->prox;
}
return acum;
}
Dicionário
Reg     Var 
rdi      s 
esi      n    
*/

.text

# int boo(struct S *s, int n)
.globl boo
boo:

    #criar o RA da função chamada
    pushq %rbp #salvando o RA da função chamadora 
    movq %rsp, %rbp #RBP aponta para a base do RA da função chamada 
    