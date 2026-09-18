Neste laboratório, estudamos a tradução de programas em C para assembly, focando em acessos a arrays, ponteiros, operações aritméticas e testes bit a bitr. 

1) Foi possível observar que o registrador %r12 armazena o endereço do array (8 bytes - 64 bits), enquanto utilizamos %ebx (4 bytes - 32bits) para controla do índice do loop. 

2) Em seguida, implementando a soma dos elementos, sendo necessário usar um novo registrador para acumular valor e mover a chamada da função print para um outro label.

3) Seguindo as questões, implementamos um programa com filtragem de valor para par. Nesse caso, foi utilizado o operador bit a bit "andl" para verificação E utilizado o jump condicionado "jzn (jump if not zero)" para "pular" a chamada da função print (que deve imprimir apenas valores pares) e seguir o caminho natural do programa. Caso jzn resulte em FALSE, ou seja, o numero é PAR, de fato, a função print lida para imprimir o valor par.

4) A principal dificuldade foi entender que, ao reduzir o tipo de dado para byte, o valor precisa ser estendido para 32 bits antes de ser impresso, utilizando instruções como movsbl. 