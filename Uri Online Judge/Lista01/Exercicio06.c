#include <stdio.h>
#include <math.h>

int main() {
    double money, notes[2][6] = {{100, 50, 20, 10, 5, 2}, {1, 0.50, 0.25, 0.10, 0.05, 0.01}};
    int numberofnotes [2][6];
    do {scanf("%lf", &money);}
    while (money < 0 || money > 1000000.00);
    
    for (int i = 0; i < 2; i++)
    {
        if (i==0) printf("NOTAS:\n");
        if (i==1) printf("MOEDAS:\n");
        for (int j = 0; j < 6; j++)
        {
            numberofnotes[i][j] = 0.001+money/notes[i][j]; //0.01 para arredondar caso de algo tipo 1.99999...
            if((money/notes[i][j])>0){
                money = money - (notes[i][j]*numberofnotes[i][j]);
            }
            if (i==0) printf("%i nota(s) de R$ %.2lf\n", numberofnotes[i][j], notes[i][j]);
            if (i==1) printf("%i moeda(s) de R$ %.2lf\n", numberofnotes[i][j], notes[i][j]);
        }
    }
    return 0;
}