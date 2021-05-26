#include <stdio.h>
#include <math.h>


/* Escrever um programa que leia um código e três valores.
Consistir a entrada de dados para que os três valores
sejam diferentes de zero e positivos. Os códigos válidos
são 1, 2, 3, 4 e 5. Se o código for diferente destes,
apresentar a mensagem "Código Inválido" e terminar a
execução do programa.
– código 1: multiplicar os três valores
– código 2: somar os três valores
– código 3: subtrair os três valores
– código 4: somar o cubo dos três valores
– código 5: somar o quadrado dos três valores */


int main(void){
    int n;
    double numbers[3], result;

    for (int i = 0; i < 3; i++)
    {
        printf("Type a number(%i): ", i);
        scanf("%lf", &numbers[i]);
        while (numbers[i] <= 0){
            printf("Invalid Number, type a number(%i) again: ", i);
            scanf("%lf", &numbers[i]);
        }
    }

    printf("codigo 1: multiplicar os tres valores\ncodigo 2: somar os tres valores\ncodigo 3: subtrair os tres valores\ncodigo 4: somar o cubo dos tres valores\ncodigo 5: somar o quadrado dos tres valores\nChoose an operation and type the code of the same: ");
    scanf("%i", &n);


    switch (n)
    {
    case 1:
        result = numbers[0]*numbers[1]*numbers[2];
        printf("result = %lf", result);
        break;
    case 2:
        result = numbers[0]+numbers[1]+numbers[2];
        printf("result = %lf", result);
        break;
    case 3:
        result = -(numbers[0]+numbers[1]+numbers[2]);
        printf("result = %lf", result);
        break;
    case 4:
        result = pow(numbers[0], 3) + pow(numbers[1], 3) + pow(numbers[2], 3);
        printf("result = %lf", result);
        break;
    case 5:
        result = pow(numbers[0], 2) + pow(numbers[1], 2) + pow(numbers[2], 2);
        printf("result = %lf", result);
        break;    
    default:
        printf("Invalid Code");
        break;
    } 
}