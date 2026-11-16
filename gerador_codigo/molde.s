.text
.globl f
f:
    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp
    movl $100, %eax
    leave
    ret