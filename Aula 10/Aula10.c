/*
& Realocação dinâmica

* • A alocação dinâmica de memória é um recurso útil quando não se sabe previamente a quantidade de memória 
*   que será utilizada no programa;

* • A função malloc() aloca um novo bloco de memória sempre que é chamada;

* • Todavia, às vezes é necessário aumentar (ou diminuir) uma área previamente alocada, o que pode ser feito via
*   realocação de memória da seguinte forma:

todo: void * realloc ( void *p , size_t n_bytes )

? Entrada:
^ - Endereço da área já alocada (p);
^ - quantos bytes a nova área realocada deve ter (n_bytes);

? Saída: 
^ - o endereço da área realocada;
^ - Caso não seja possível realizar a realocação, a função retorna a constante NULL.

* • A realocação será feita de modo que o bloco de memória atual aumente cobrindo 
*   os endereços adjacentes à área já alocada;

* • Caso não haja espaço suficiente “ao lado” da área já alocada, uma nova área é 
*   encontrada, de modo que realocação possa ser feita;
^       – Todos os dados ali armazenados são copiados;
* • Portanto, um bloco previamente alocado pode mudar de endereço após uma realocação.

? Pode se realocar um vetor:
*/
#include <stdio.h>

int realocavetor(void){
    int *p, n, m, i;
    
    printf("Quantos valores? ");
    scanf("%d", &n);
    
    p = malloc( sizeof(int) * n );

    //^ Entrada de dados:
    for( i = 0 ; i < n ; i++ )
        scanf("%d", p + i);

    //^ Imprime dados do vetor:
    for( i = 0 ; i < n ; i++ )
        printf("P[%d] : %d\n", i, p[i] );

    printf("Quantos valores a mais? ");
    scanf("%d", &m);

    //^ Realocando área: n + m = 5 (20 bytes):
    p = realloc( p , sizeof(int) * (n + m) );

    //^ Entrada de dados somente na parte realocada:
    for( i = n ; i < n + m ; i++ )
        scanf("%d", p + i);

    //^ Imprime dados do vetor todo:
    for( i = 0 ; i < n + m ; i++ )
        printf("P[%d] : %d\n", i, p[i] );

    //^ Libera a memória:
    free(p);

}
/*
? Busca sequencial em um vetor:

* Dados um vetor v, com capacidade n e uma chave de busca;

* A função retorna um vetor (alocado dinamicamente) com os índices em que a chave se encontra (termina com -1);

todo: int * busca( int v[], int n, int chave );

? Entrada:
^ - v = {3, 6, 7, -1, 3, 12, 9, 8, 3, 17}
^ - chave = 3

? Saída:
^ - vetor resultante = {0, 4, 8, -1}

* Dados dois vetores v1 e v2 (e suas capacidades), a função retorna:
^ – O endereço de um vetor (alocado dinamicamente, contendo a intersecção entre v1 e v2;
^ – A capacidade do novo vetor (parâmetro por referência);

^ • Protótipo da função:

todo: int *intersecao(int *v1, int n1, int *v2, int n2, int *p3);

*/

int main(){
    int a[] = { 1, 2, 3, 4, 5 };
    int b[] = { 3, 4, 5, 6, 7, 8 };
    
    int n_a = sizeof( a ) / sizeof( int );
    int n_b = sizeof( b ) / sizeof( int );
    
    int n_c, i;
   
   int *c = interseccao( a, n_a, b, n_b, &n_c );
 
    for( i = 0 ; i < n_c ; i++ ){
        printf("%d : %d\n", i , c[i] );
    }
 
    free( c );
}

int *interseccao(int *v1, int n1, int *v2, int n2, int *p3){
    int *p = NULL; //^ (Ponteiro NULL pode ser realocado)
    int i, j;
 
    *p3 = 0; //^ n_c = 0;
 
    for( i = 0 ; i < n1 ; i++ )
        for( j = 0 ; j < n2 ; j++ )
            if( v1[i] == v2[j] ){
                (*p3)++; //^ n_c++;
                
                p = realloc( p, sizeof(int) * *p3 );
                p[*p3 - 1] = v1[i];
        }
 
    return p;
}