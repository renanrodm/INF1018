/*
 * Cabe�alho para o trabalho de software b�sico
 * N�O modifique esse arquivo
 */

// tipo ponteiro para fun��o que recebe um inteiro e retorna um inteiro
typedef int (*funcp) (int x);

// prot�tipo da fun��o que recebe um arquivo previamente aberto e preenche o vetor de bytes (char) com o c�digo gerado
void gera_codigo (FILE *f, unsigned char code[], funcp *entry);
