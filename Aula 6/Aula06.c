/* 
& Matrizes

• Pode ser definido como sendo um conjunto de variáveis
do mesmo tipo. São também conhecidos por vetores ou array;

• Sua declaração segue o mesmo formato de variáveis,
porém acrescenta-se o número de elementos desejados entre colchetes ([ e ]). 

<tipo> <identificador>[<quantidade>]               
*/

int posicao_mouse[2][2];
float vet3d[3];
char nome[60];

/* 
* Os elementos são enumerados de 0 (zero) até o número especificado como quantidade menos 1 (n-1);

• Para matrizes multidimensionais, são fornecidos tantos índices quanto o número de dimensões;

* Para referenciar uma das variáveis, devemos fornecer o índice do elemento entre colchetes.

• A linguagem C não verifica se o índice é inválido, permitindo a leitura de "lixo" e
alteração de outras posições de memória. */

int main(void)
{

    double valor, matriz[3][3];
    matriz[2][1] = 2.00;
    valor = matriz[2][1];
}


/* 
? Inicialização na declaração:

• A inicialização pode ser feita apenas na declaração.

• Se o num de elementos é menor que o tamanho do vetor, os elementos restante são inicializados com zero.

• Podemos omitir o tamanho do vetor quando ele é inicializado (mas somente quando inicializado!). No caso de matrizes 
de mais de uma dimensão, somente a primeira dimensão pode ser omitida. */

int vet[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
float Mat3x3[3][3] = {{ 1, 0, 0 },
                      { 0, 1, 0 },
                      { 0, 0, 1 }};

char nome[60] = "Curso de C"; // ^ isso é o equivalente à: char nome[60] = {'C', 'u', 'r',...}

/* 
& String em C

* Chamamos de string um vetor de caracteres (também chamado de cadeia de caracteres).

* Como são muito usados, existe um conjunto de funções para manipulação de strings em C:

! OBS.: é recomendado importar a biblioteca string.h para evitar warnings
    
    ? gets(<variável>): 
      - lê uma “frase” do teclado (a função scanf para no primeiro espaço);
    
    ? strlen(<variavel>): 
      - informa o tamanho de caracteres;
    
    ? strcmp(<variavel 1>, <variavel 2>): 
      - compara o conteúdo de duas variáveis retornando 0 (zero) se o conteúdo é idêntico,
        +1 se a primeira for maior ou -1 se for menor;
    
    ? strcpy(<variavel 1>, <variavel 2>): 
      - copia o conteúdo da variável 2 para a variável 1.


& EXTRA: endereços apontados por uma matriz 
*/

int matriz(void){
    int matriz[3][3], matriz[1][1] = 10;
}

/*
* perceba que: matriz[1][1] == *(matriz + 3*2 + 2) == *(1004)

* sendo matriz == 1000 (inicia endereço no número 1000)

^    | 1000 | 1001 | 1002 |
^    | 1003 | 1004 | 1005 |
^    | 1006 | 1007 | 1008 | 

* logo o número 10 está armazendo no endereço de número 1004

*/

