//& Alocação dinâmica de matrizes

//^ criando uma matriz através de ponteiros:

int matriz(){
    //* Vetor de inteiros "estático":
    int v[4] = { 1, 3, 5, 7 };

    //* Vetor de inteiros dinâmico:
    int *p = malloc( sizeof(int) * 4 );

    //* Vetor de ponteiros (para inteiros, equivalente a matriz "int m[4][3];"):    
    int *vp[4];

    for(int i = 0 ; i < 4 ; i++ )
    vp[i] = malloc( sizeof(int) * 3 ); //? alocando uma quantidade de memória para cada endereço (por issso sem "*vp" e sim "vp" apenas)

    //^ • Um ponteiro pode ser usado para alocar um vetor dinamicamente;
    //^ • Um vetor de ponteiros pode ser usado para alocar uma matriz dinamicamente;

    //* Matriz semidinâmica (para inteiros):

    //^ Vetor de ponteiros (para inteiros):
    int *vp[4]; 
    int i, j;

    //^ Alocação:
    for( i = 0 ; i < 4 ; i++ )
    vp[i] = malloc( sizeof(int) * 3 ); //? Alocando espaço de memória para 3 inteiros
    
    //^ Entrada de dados:
    for( i = 0 ; i < 4 ; i++ )
        for( j = 0 ; j < 3 ; j++ )
            scanf("%d", &vp[i][j]);

    //^ Saída dos dados:
    for( i = 0 ; i < 4 ; i++ ){
        for( j = 0 ; j < 3 ; j++ )
            printf("%d ", vp[i][j]);
        printf("\n");
    }

    //^ Liberação da memória:
    for( i = 0 ; i < 4 ; i++ )
        free( vp[i] );

}

//& Parâmetros para main()
/*
* • Um programa em C consegue receber uma entrada de dados diretamente do prompt de comando;
 
* • São armazenados nos parâmetros da função main(int, char*):
^ – int argc : quantidade de palavras digitadas;
^ – char *argv[] : vetor de strings, contém as palavras.

? • Considere que o arquivo executável do programa se chama teste.exe, e que o usuário digitou mais 
?   algumas palavras na linha de comando (parâmetros):
*/
#include <stdio.h>

int main( int argc, char *argv[] ){
 
 //* Mostra o que foi digitado:
 for(int i = 0 ; i < argc ; i++ )
 
 printf("%s\n", argv[i]);
 return 0;
}
/*
* Resultado no terminal:
^ teste
^ alô
^ mundo
^ 123

? • O uso dos parâmetros da main() é feito normalmente por utilitários executados via linha de comando;
? • Um exemplo típico é o GCC, que recebe vários parâmetros, incluindo os arquivos a serem compilados;
? • Note que os valores digitados são strings, sendo necessário converter para outros tipos (int ou float), caso necessário;
^   - Uma função útil para isso é sscanf()
? • O uso de vetores de ponteiros acaba sendo limitado, pois sua capacidade é fixa:
^   – Linhas da matriz;
^   – Quantidade de strings;
*/
//& Ponteiros para ponteiros
/* 
*  • É preciso, portanto, fazer a alocação dinâmica do vetor de ponteiros, o que pode ser feito através de ponteiros 
*    para ponteiros;
*  • Definição óbvia: ponteiro para ponteiros é aquele que aponta para outro ponteiro (ao invés de informação em si);
*  • Ou seja, temos mais um nível de endereçamento;
^     – o que à primeira vista, parece desnecessário;
*  • Porém, é fundamental para a alocação dinâmica de matrizes e vetores de strings;

Todo: Instruções para criar ponteiros para ponteiros:

* • A declaração é feita com "**"", indicando que temos um ponteiro para ponteiros;
* • Na prática, temos uma variável que guarda um endereço (mas agora de outro ponteiro);
* • O operador de indireção (*) deve ser utilizado duas vezes para se chegar à informação;
^   – Alternativamente, pode-se utilizar dois pares de colchetes para a notação de matrizes;
*/
int ponteiros(){
    int a = 3, *p1, **p2;
    p1 = &a; //? endereço de a.
    p2 = &p1; //? endereço de p1.

    //* Mostra endereço da variável p1:
    printf("Endereço de P1 = %d\n", p2 );

    //* Mostra endereço da variável a:
    printf("Endereço de A = %d\n", *p2 ); //? p2[0]

    //* Mostra valor da variável a:
    printf("A = %d\n", **p2 ); //? p2[0][0]

    /*
    * • Ponteiros para ponteiros devem apontar somente para ponteiros (e não para a informação);
    * • São usados para a alocação de vetores de ponteiros;
    * • Depois, cada ponteiro do vetor vai apontar para um vetor alocado dinamicamente (linhas da matriz, contendo os valores);
    */

    //Todo: Matriz de ponteiros para ponteiros:
    
    //* Ponteiro de ponteiro (será a matriz):
    int **p; 
    int lin, col, i, j;
    printf("Digite quantas linhas e colunas:\n");
    scanf("%d %d", &lin, &col);
    
    //* Alocação do vetor de ponteiros:
    p = malloc( sizeof(int*) * lin );
    
    //* Alocação das linhas:
    for( i = 0 ; i < lin ; i++ )
        p[i] = malloc( sizeof(int) * col );

    //* Entrada de dados:
    for( i = 0 ; i < lin ; i++ )
        for( j = 0 ; j < col ; j++ )
            scanf("%d", &p[i][j]);

    //* Saída dos dados:
    for( i = 0 ; i < lin ; i++ ){
        for( j = 0 ; j < col ; j++ )
            printf("%d ", p[i][j]);
            printf("\n");
    }

    //* Liberação da memória:
    for( i = 0 ; i < lin ; i++ )
        free( p[i] );
        free( p );
}
/*
* • Os operadores sobre ponteiros e vetores continuam valendo;
    todo – Neste caso, é preciso utilizar 2 vezes (2 dimensões);
* • Tal como em ponteiros simples, a realocação também funciona com ponteiros para ponteiros;
* • Para cada dimensão a mais na matriz, devemos aumentar o nível de endereçamento;
    todo – Para 3 dimensões, teríamos int ***p;

* • Alocação dinâmica de um vetor de strings;
    todo – Strings são alocadas dinamicamente e adicionadas ao vetor de ponteiros;
    todo – À medida que o usuário digita novas palavras, o vetor de ponteiros vai sendo realocado;
*/