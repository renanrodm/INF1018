#include <stdio.h>

int main(void){
    int v[10];
    int *p;

    printf("Tamanho de v = %ld\n", sizeof v);
    printf("Tamanho de p = %ld\n", sizeof p);
    printf("Tamanho de int = %ld\n", sizeof(int));
    
    // Isso pode?

    p = v; // SIM!! Operação válida que está atribuindo o início do vetor v, ao ponteiro p. Agora o vetor v passa a ser acessível por p.
    // v = p; NÃO!! Porque v é uma constante. Nesse caso, estaria tentando variar o valor de uma constante!!

    // Isso pode?
    v[0] = 55; //Sim!!
    v[1] = 'A'; //Sim!! Pq apesar de ser um caracetere, por debaixo dos panos ela é um int
    //v[2] = "b"; //WARNING!!! Aqui tem 2 bytes, do 'b' + '\o'. E o valor "b" é endereço da string, ou seja, é do tipo char *. Não está errado, compila, mas tb n está certo. O correto seria colocar um cast para avisar ao compilador que você sabe o que está fazendo, por exemplo: v[2] = (int) "b";
    
    printf("v[0] = %d, v[1] = %d\n", v[0], v[1]);
    printf("v[0] = %c, v[1] = %c\n", v[0], v[1]); //Na tabela ASCII, a posição 55 tem o caractere '7'!!

    *p = 66; //o conteúdo apontado por p recebe 66;
    // printf();

    p = (int*) 1000; //p passa a receber o endereço 1000. Aqui vc está fazendo um cast para avisar ao compilador que vc sabe o que está fazendo, pq 1000 é um inteiro e p é um ponteiro para int. Então vc está dizendo: "olha, eu sei que 1000 é um inteiro, mas eu quero que vc trate ele como um endereço de memória, então faça o cast para int*"

    printf("p = %ld\n", p); //
    p = p + 4; //aritméticas de ponteiros!! aqui vc está andando 4 posições de tamanho int (4 bytes);
    printf("p = %ld\n", p); //logo, o resultado aqui será 1016!!

    p = v;
    
    *(v+3) = 33;
    *(p+3) = 333; //ambos estão corretos. Verificar o porque.

    v[0] = 44;
    p[0] = 444; //ambos estão corretos. Explicação: p[0] é o mesmo que *(p+0), ou seja, o conteúdo apontado por p. E como p aponta para v, então p[0] é o mesmo que v[0].

    // v++; <- ERRADO porque v é uma constante.
    p++; //CERTO porque p é uma variável do tipo ponteiro para int, e pode variar o valor do endereço que ele aponta.


    //por uma questao de eficiencia, o tipo precisa estar em endereços multiplos do seu tamanho, para que vc garanta alinhamento na memoria. Por exemplo, um int precisa estar em endereços multiplos de 4 bytes, um double em endereços multiplos de 8 bytes, etc. Isso é importante para que o processador consiga acessar a memoria de forma eficiente.

    //com isso, existe o conceito de padding, que é quando o compilador adiciona bytes extras para garantir que os dados estejam alinhados na memoria. Por exemplo, se vc tem uma struct com um char e um int, o compilador vai adicionar 3 bytes de padding entre eles para garantir que o int esteja em um endereço multiplo de 4 bytes.




    return 0;
}