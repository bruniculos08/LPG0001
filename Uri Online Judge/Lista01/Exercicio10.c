#include <stdio.h>
 

int main() {
    float salario, imposto;
    
    scanf("%f", &salario);
    if (salario <= 2000.00){ 
        imposto = 0;
        printf("Isento\n");
        return 0;
    }
    else if (salario > 2000.00 && salario <= 3000.00) imposto = (8.00/100.00)*(salario-2000.00);
    else if (salario > 3000.00 && salario <= 4500.00) imposto = (0.08)*(1000) + (0.18)*(salario-3000.00);
    else imposto = (0.08)*(1000) + (0.18)*(1500) + (28.00/100.00)*(salario-4500.00);
 
    
    printf("R$ %.2f\n", imposto);
    return 0;
}