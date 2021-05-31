/* 
& Funções em C 

<tipo retornado> <nome>(<parâmetro 1>,...,<parâmetro n >)
{
 <declaração das variáveis locais>
 <comandos>
}


* É uma coleção de comandos identificados por um nome (identificador);
* As funções executam ações e podem retornar valores;
* main, printf e scanf são exemplos de funções.


^ Tipo retornado: 
- pode ser qualquer um dos tipos
  que já vimos (int, short int, long int, char, ...) ou
  então void, que indica que a função não retornará nenhuma informação.

^ Nome:
- é o identificador da função, servindo para referenciar a mesma.

^ Parâmetros:
- são as informações para trabalhar. Constituem-se de variáveis locais à função, 
  que são declarados individualmente, separados por vírgula.

todo - VOID
? Quando uma função é definida com o tipo de retorno void, ela também pode ser chamada de 
? procedimento pois somente executa um conjunto de comandos e não retorna nenhum valor;

todo - RETURN
? Quando o tipo de retorno é diferente de void, precisamos retornar um valor para o trecho de
? código que chamou a função. Isto é feito por meio do comando return.
*/

int soma(int a, int b)
{
 int resultado;
 resultado = a + b;
 return resultado;
}

/*
* Passagem de Parâmetros

^ Por valor: 
- são fornecidas cópias dos valores dos parâmetros na expressão que chama a função. A
  função pode alterar o valor dos parâmetros, mas esta mudança não é refletida às variáveis
  originais. É o tipo padrão na linguagem C. */

void ImprimirValor (float v) {
 printf("%.2f", v);
}

/* 
^ Por referência: 
- este tipo permite que se altere o conteúdo das variáveis passadas como parâmetro. 
  A função recebe um endereço de memória como parâmetro. É exatamente o que acontece quando utilizamos a função scanf. 
  É informado que os dados lidos deverão ser armazenados em variáveis passadas por parâmetro. */

// ? scanf("%f", &valor); note o &

/* 
& Variáveis Locais

* Variáveis declaradas dentro de uma função.
* Não são reconhecidas fora de seu próprio bloco de código.
* Existem apenas enquanto o bloco de código em que foram declaradas está sendo executado, ou seja, é criada na entrada de seu bloco e destruída na saída.


& Variáveis Globais

* São reconhecidas pelo programa inteiro e podem ser usadas por qualquer pedaço de código.
* Guardam seus valores durante toda a execução.
* Devem ser declaradas fora de qualquer função.
* Ocupam memória durante todo o tempo de execução do programa.
* Tornam as funções menos gerais.
* Podem levar a erros no programa devido a efeitos colaterais.


& Protótipo de Funções

• É a repetição da declaração da função, porém não necessita dos nomes das variáveis
que recebem os parâmetros, encerrando com ponto e vírgula (;).
• Isto ajuda o compilador a verificar se os parâmetros que estão sendo passados nas funções estão de acordo com os tipos que
elas esperam receber
? É feita extraindo-se:
* - Tipo retornado pela função
* - Nome da função;
* - Tipo dos parâmetros entre parênteses
*/

void ImprimirValor(float);
int soma(int, int);