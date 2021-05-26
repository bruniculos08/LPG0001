#include <stdio.h>


/* Ler dois números. Se os números forem iguais, 
imprimir a mensagem "Números iguais" e 
encerrar a execução. Caso
contrário, imprimir o de maior valor. */


int main(void){
    double numbers[2];

    for (int i = 0; i < 2; i++)
    {
        printf("Type the a number(%i): ", i);
        scanf("%lf", &numbers[i]);

        if (i == 1){
            if (numbers[0] == numbers[1])
            {
                printf("Numeros iguais");
                break;
            }
            else if (numbers[0]>numbers[1]){
                printf("%lf", numbers[0]);
                break;
            }
            else{
                printf("%lf", numbers[1]);
                break;
            }
        }
    }
}