/* 
& Recursividades

• Na linguagem C, assim como na maioria linguagens de programação atuais, uma função
pode chamar a si mesma. Uma função assim é chamada função recursiva.

• Existem muitos problemas que são definidos com base neles mesmos, ou seja, podem ser descritos
por instâncias do próprio problema. Para estas classes de problemas, o conceito de recursividade
torna-se muito útil. 
todo - Ex.: n! = n * (n-1)!

* Deve-se tomar alguns cuidados ao se fazer funções recursivas.

• Um cuidado importante a se verificar, é a existência de um critério de parada para
determinar quando a função deverá parar de chamar a si mesma. Este cuidado serve para
impedir que a função se chame infinitas vezes. */


// ^ No caso da função fatorial, podemos escrevê-la da seguinte forma (que resultara em looping infinito): 

int fatorialerror(int n) {
 return n * fatorial(n-1);
}

// ^ Qual o critério de parada?
// ^ No caso da função fatorial, podemos escrevê-la da seguinte forma, de maneira que tenha critério de parada:

int fatorial(int n) {
 if(n<=1)
 return 1;
 return n * fatorial(n-1);
}

// todo - OBS.: pode se fazer 2 ou mais funções recursivas e uma chamando a outra.