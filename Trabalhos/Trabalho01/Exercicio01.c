#include <stdio.h>
#include <math.h>

int main() {
    int money, notes[6] = {50, 20, 10, 5, 2, 1};
    int numberofnotes[6];
    do {scanf("%i", &money);}
    while (money < 0);
    
    for (int i = 0; i < 6; i++)
    {
        numberofnotes[i] = 0.001+money/notes[i]; //0.01 para arredondar caso de algo tipo 1.99999...
        if((money/notes[i])>0){
            money = money - (notes[i]*numberofnotes[i]);
        }
        if (numberofnotes[i] > 1) printf("%i notas de R$ %i,00\n", numberofnotes[i], notes[i]); 
        else if (numberofnotes[i] == 1) printf("%i nota de R$ %i,00\n", numberofnotes[i], notes[i]);
        }
    return 0;
}