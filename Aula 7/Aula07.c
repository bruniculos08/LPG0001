/* 
& Ponteiros

• Definição:
– Em programação, um ponteiro ou apontador é um tipo de dado
de uma linguagem de programação cujo valor se refere
diretamente a um outro valor alocado em outra área da memória,
através de seu endereço. Um ponteiro é uma simples
implementação do tipo referência da Ciência da computação.




todo IMPORTANTE RESUMO:

^   *p1 é o que está no endereço apontado (ou seja indica o conteúdo).
^   p1 é o número do endereço, & é um operador para obter um endereço. 
^   a declaração <tipo> *<nome do ponteiro> armazena um endereço.


vetor[2] é como *(p+2)



*/
float *p1; // recebe um endereço de um tipo float

int vetor[100];
int *p = vetor;