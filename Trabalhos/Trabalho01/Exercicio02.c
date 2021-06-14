#include <stdio.h>


char *estacao(int day, int month);
char *estacao(int day, int month){
    if((day >= 23 && month == 9) || (day >= 1 && month > 9 && month < 12) || (day < 21 && month == 12)) return "Primavera";
    else if((day >= 21 && month == 12) || (day >= 1 && month >= 1 && month < 3) || (day < 21 && month == 3)) return "Verao";
    else if((day >= 21 && month == 3) || (day >= 1 && month > 3 && month < 6) || (day < 21 && month == 6)) return "Outono";
    else if((day >= 21 && month == 6) || (day >= 1 && month > 6 && month < 9) || (day < 23 && month == 9)) return "Inverno";
    else return "Wrong date!";
}

int main (void){
    int day, month;
    printf("Type the day and month: ");
    scanf("%i %i", &day, &month);
    printf("%s", estacao(day, month));
}