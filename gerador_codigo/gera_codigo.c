#include <stdio.h>
#include <stdlib.h>
#include "gera_codigo.h"

void gera_codigo (FILE *f, unsigned char code[], funcp *entry) {
  int i = 0;
  int c;

  while ((c = fgetc(f)) != EOF) {
    switch (c) {
      case 'f': { // function
        char c0;
        fscanf(f, "unction%c", &c0);
        break;
      }
      case 'e': { // end
        char c0;
        fscanf(f, "nd%c", &c0);
        break;
      }
      case 'r': {
        char var0;
        int val0;

        fscanf(f, "et %c", &var0);

        if (var0 == '$') {
          fscanf(f, "%d", &val0);

          
          code[i++] = 0x55;                       // pushq %rbp
          
          code[i++] = 0x48;                       // movq %rsp, %rbp
          code[i++] = 0x89; 
          code[i++] = 0xe5;
          
          code[i++] = 0x48;                       // subq $32, %rsp
          code[i++] = 0x83; 
          code[i++] = 0xec; 
          code[i++] = 0x20;

          
          code[i++] = 0xb8;
          *((int *)(&code[i])) = val0;            // inteiro de 4 bytes
          i += 4;                                 

          
          code[i++] = 0xc9;                       // leave
          code[i++] = 0xc3;                       // ret
        }
        break;
      }
      case '\n':
        break;
      default:
        break;
    }
  }

  *entry = (funcp) code;
}