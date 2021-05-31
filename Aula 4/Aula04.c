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

#include <stdio.h>


