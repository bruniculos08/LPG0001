/* deixar último ganchinho com roupa para não bater a porta
& Repetição por While

while(condição){
    bloco de comandos;
}

* O laço se repete enquanto a condição for verdadeira.
* Testa a condição antes de entrar; se for inicialmente falsa, não executa o laço nenhuma vez.
* Dentro do laço deve haver atualização da variável que controla o laço, a fim de que não se torne um laço infinito
? Obs. 1: perceba que o While testa primeiro a condição antes de executar o comando, logo em certos casos é possível que os comandos não sejam executados nenhuma vez se quer 

& Repetição por Do-While 

do {
    bloco de comandos;
} 
while (condição);

* O laço se repete até que a condição se torne falsa.
* Testa a condição ao final do laço, executando ao menos uma vez todos os comandos. 
? Obs. 1:perceba que o do-While executa e testa depois, ou seja, pelo menos uma vez os comandos serão executados

& Repetição por For

for (inicialização; condição; incremento){
    bloco de comandos;
}

* Inicialização: comando de atribuição usado para inicializar a variável de controle do laço. Mais de uma variável pode ser inicializada.
* Condição: expressão que determina quando o laço acaba.
* Incremento: define como a variável de controle varia cada vez que o laço é repetido.
* A condição é verificada ao iniciar o laço. Se for inicialmente falsa, o código dentro do laço não será executado.
? Obs. 1: as variáveis criadas dentro do estrutura For são válidas apenas dentro nela
? Obs. 2: podem ser utilizadas funções dentro da condição e/ou do bloco de comandos

& Paralização por Break

* Usado para terminar um case em um comando switch ou para forçar a terminação imediata de um laço (for, do-while e while), evitando o teste condicional normal do laço.
* Ao encontrar um break, o compilador encerra o laço e pula para executar o comando seguinte após o laço.
* Só sai do laço mais interno.

& Paralização por Continue

* Desvia o programa para a linha onde é feita a avaliação da condição para o laço (for, dowhile e while).
* Num laço for o comando continue desvia a execução primeiro para a atualização da variável e depois efetua o teste.
* Em laços do-while e while simplesmente desvia a execução para o teste da condição.


*/

//^ Exemplo de While:

#include <stdio.h>
void exemplo_while(){
    int cont, valor, resultado;
    
    printf("Entre com um valor");
    scanf("%d", &valor);
    
    cont = resultado = 1;
    while(cont <= valor) {
        resultado *= cont;
    cont++;
    }

    printf("Resultado: %d", resultado);
}

//^ Exemplo de Do-While:

void exemplo_dowhile() {
    char opcao;
    
    printf("Escolha uma opção: \n\n");

    printf("M – Masculino\n");
    printf("F – Feminino\n\n");
    
    do {
        printf("Opção:");
        scanf("%c", &opcao);
    } 
    while((opcao != 'M') && (opcao != 'F'));
}

//^ Exemplo de For:

void exemplo_for(){
    int cont, valor, resultado;

    printf("Entre com um valor");
    scanf("%d", &valor);

    resultado = 1;

    for(cont=2; cont <= valor; cont++){  
        resultado *= cont; // multiplica o objeto por algo e atribui o valor do objeto ao resultado da multiplicação (objeto *= algo)
    printf("Resultado: %d", resultado);
    }
}

//^ Exemplo de Break:

void exemplo_break(){
    
    int t, cont;

    for(t = 0; t < 100; t++){
    cont = 1;

    for(;;){
        printf("%d ", cont);
        cont++;
        if(t == 10){
            break;
        }
    }
}

//^ Exemplo de Continue:

#include <string.h>
void main( ){
    char str[80];
    int i, espaco;
    
    printf("Digite uma string: ");
    fgets(str, 79, stdin);
    
    for(i = 0, espaco = 0; i < strlen(str); i++){
        if(str[i] != ' ')
            continue;
            espaco++;
        }
    printf("%d espacos", espaco);
}