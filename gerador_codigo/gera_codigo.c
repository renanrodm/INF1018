#include <stdio.h>
#include <stdlib.h>
#include "gera_codigo.h"

void gera_codigo(FILE *f, unsigned char code[], funcp *entry)
{
    int i = 0;
    int caractere;

    while ((caractere = fgetc(f)) != EOF)
    {
        switch (caractere)
        {
        case 'f':
        { // function
            char c0;
            if (fscanf(f, "unction%c", &c0) != 1)
            {
                printf("Erro ao tentar ler: 'f'");
            }
            break;
        }
        case 'e':
        { // end
            char c0;
            if(fscanf(f, "nd%c", &c0) != 1){
            {
                printf("Erro ao tentar ler: 'e'");
            }
            break;
        }
        case 'r':
        {
            char var0;
            int val0;

            if(fscanf(f, "et %c", &var0) != 1){
                printf("Erro ao tentar ler: 'r'");
            }

            if (var0 == '$')
            {
                fscanf(f, "%d", &val0);

                code[i++] = 0x55; // pushq %rbp

                code[i++] = 0x48; // movq %rsp, %rbp
                code[i++] = 0x89;
                code[i++] = 0xe5;

                code[i++] = 0x48; // subq $32, %rsp
                code[i++] = 0x83;
                code[i++] = 0xec;
                code[i++] = 0x20;

                code[i++] = 0xb8;
                *((int *)(&code[i])) = val0; // inteiro de 4 bytes
                i += 4;

                code[i++] = 0xc9; // leave
                code[i++] = 0xc3; // ret
            }
            break;
        }
        case '\n':
            break;
        default:
            break;
        }
    }

    *entry = (funcp)code;
}