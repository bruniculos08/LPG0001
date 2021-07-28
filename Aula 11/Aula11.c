/* 
& Estruturas de dados

*   • As valores armazenados em vetores ou matrizes são todos do mesmo tipo, e por
*     isso são chamados de variáveis compostas homogêneas.

*   • Porém, há casos em que precisamos agrupar variáveis de diferentes tipos. Para estes
*     casos a linguagem C nos fornece as estruturas (structs).

*   • A vantagem em se usar estruturas de dados é que podemos agrupar de forma
*     organizada vários tipos de dados diferentes.

*   • Por exemplo, dentro de uma estrutura de dados usada para armazenar dados de
*     alunos podemos ter nome, número de matrícula, data de nascimento, notas, etc.

^   struct <identificador>
^   {
^       <tipo> <identificador do campo 1>;
^       <tipo> <identificador do campo 2>;
^       . . .
^       <tipo> <identificador do campo n>;
^   } <variaveis>;

*  • Nem sempre os tipos de uma estrutura precisam ser diferentes. Em alguns casos, podemos usar elas
*    para definir dados homogêneos.

~ typedef:

*   • Ao se definir uma estrutura de dados (struct), está se definindo um novo tipo de dado. A linguagem C oferece
*     uma outra forma de se definir um novo tipo de dado. Trata-se da declaração typedef que pode ser utilizado para
*     se definir a estrutura Aluno da seguinte forma:


^   typedef struct
^   {
^       <tipo> <identificador do campo 1>;
^       <tipo> <identificador do campo 2>;
^       . . .
^       <tipo> <identificador do campo n>;
^   } <identificador>;

~ declaração de variáveis: 

*/