#include <stdio.h>
#include "gera_codigo.h"

void gera_codigo(FILE *f, unsigned char code[], funcp *entry){

    //pushq %rbp
    code[0] = 0x55;

    //mov %rsp, %rbp
    code[1] = 0x48;
    code[2] = 0x89;
    code[3] = 0xe5;

    //sub $32, %rsp
    code[4] = 0x48;
    code[5] = 0x83;
    code[6] = 0xec;
    code[7] = 0x20;

    //mov $100, %eax
    code[8] = 0xb8;
    code[9] = 0x64;
    code[10] = 0x00;
    code[11] = 0x00;
    code[12] = 0x00;

    //leave 
    code[13] = 0xc9;

    //ret
    code[14] = 0xc3;


    *entry = (funcp) code;
}