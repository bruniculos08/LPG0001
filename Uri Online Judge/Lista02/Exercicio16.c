#include <stdio.h>
#include <stdlib.h>

int main(){
    //for (int i = 0; i < 14; i++){
        int ponteiro_hora = 0, ponteiro_min, n = 0, angulo, test_angle, answer = 1;
        double hora = 0;
        do
        {
            scanf("%d", &test_angle);
        } while (test_angle < 0 || test_angle > 180);
        for (ponteiro_min = 0; hora <= 24; ponteiro_min++)
        {
            if (ponteiro_min%12 == 0) {
                ponteiro_hora +=1;
                hora += 0.2;
            } 
            if (ponteiro_min == 60) {
                ponteiro_min = 0;
            }
            angulo = abs(ponteiro_min-ponteiro_hora)*6;
            if (angulo == test_angle) {
                answer = 0; 
                break;
            }
        }
    if (answer == 0) printf("Y");
    else printf("N");
    printf("\n");
    //}
}