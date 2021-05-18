// a linguagem C: 
// 1.a) Tipos da Dados Primitivos
 
// • char
// • int
// • float
// • double
// • void

// 1.b) Modificadores
 
// • signed: com sinal
// • unsigned: sem sinal (apenas valores positivos)
// • long
// • short


// 2) Identificadores

//  • Nomes utilizados para fazer referência às
//   variáveis, funções, rótulos e vários tipos de
//   objetos definidos pelo usuário.
//  • Podem ter de um a vários caracteres.
//  • Devem iniciar com letra ou sublinhado.
//  • Demais caracteres devem ser letras, números ou
//  sublinhado.
//  • C diferencia letras maiúsculas de minúsculas.
//  • As regras servem para melhor desempenho.


// 3) Declaração de variáveis: 

//  • <tipo> <nome>

// 4) Constantes

//   • Um número escrito explicitamente no programa é uma constante
//   pois não irá modificar-se durante sua execução. Assim como os
//   números escritos explicitamente, qualquer um dos tipos de dados
//   podem ser constantes.
//   • O modificador const expressa que o valor de um identificador não
//   pode ser alteradas durante o programa.
//   • Precede o tipo e o identificador: const <tipo> <identificador>


// 5) Operadores Aritméticos

// 5.a) Operadores:

//   = Atribuição
//   - Subtração
//   + Adição
//   * Multiplicação
//   / Divisão
//   % Módulo (resto da divisão)
//   -- Decremento
//   ++ Incremento

// 5.b) Operadores "=":

//   x += valor;
//   y /= valor;
//   int v, w, i = 0;
//   v = ++i;
//   w = i++;

// 5.c)

//  > (Maior que)
//  >= (Maior que ou igual)
//  < (Menor que)
//  <= (Menor que ou igual)
//  == (Igual)
//  != (Diferente)


// 5.d) Operadores Lógicos

// && E lógico (AND)
// || OU lógico (OR)
// ! Negação (NOT)


// 5. e) Operadores Bit a Bit

// & E bit a bit (AND)
// | OU bit a bit (OR)
// ^ OR exclusivo (XOR)
// ~ Complemento de um
// << Deslocamento à esquerda
// >> Deslocamento à direita
// int v = 2;
// v = v << 1;
// v <<= 2;

// 6. Pré-Compilador

// • Trabalha sobre o programa antes de enviá-lo
// ao compilador.
// • Todas as diretivas do pré-compilador
// começam com o símbolo #.

// 6.a) Diretiva "#include":

// • A diretiva #include indica uma solicitação de
// inserção de um outro arquivo no programa.
// • stdio.h será procurado no diretório criado para
// arquivos de inclusão.
// • meu_arquivo.h será procurado no diretório corrente.
// #include <stdio.h>
// #include “meu_arquivo.h”

// 7) Entradas e saídas:

//    • Entrada/saída efetuadas por funções de biblioteca.
//    • Utilizar #include para incluir biblioteca.
//    • Biblioteca padrão stdio.h.
//    int printf (char *formato, ...);
//    int scanf (char *formato, ...);
//    int getchar (void);
//    int putchar (int c);
//