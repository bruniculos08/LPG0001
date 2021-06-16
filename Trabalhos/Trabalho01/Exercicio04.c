#include <stdio.h>
#include <math.h>
long double poison(long double k);
long double fat(long double k);

long double poison(long double k){
long double y = 300;
long double e = 2.71828;
long double pot1 = expl(-y);
long double pot2 = powl(y, k);
long double pro1 = pot1*pot2;
long double fatk = fat(k);
long double P = (pro1)/(fatk);
return P;
}
// y = numero de ocorrencias esperadas, nesse caso, em média 300 lampadas por dia
// k = numero de ocorrencia que se queira verificar a possibilidade, sendo 290 ou 320 no proximo dia
long double fat(long double k){
    long double result=1.0;
    int i;
        for(i = 1; i <= k; i++ ) {
        result *= i;
        }
    return result;
}

int main(){
    printf("fat(k) = %Lf \n", fat(290));
    printf("P(2, 300) = %Lf \n", poison(1));
    printf("P(290, 300) = %Lf \n", poison(290));
    printf("P(320, 300) = %Lf \n", poison(320));
}

/* fat(k) = 60316116183878209764664693973407871940365450491543876222394093702502430322334900160525618295333988800339349018783666208313758357440266145584103605878962677174980150825379453462060210009438650202751769374652516117852669939645393147379190593627569901484137621400817882887629256829781786217860710910081088671709929980286919617933445534275227386925305556578680348362114116564733827009054738134359415440013073506224129382577056511938510272634381308005995929900490175109650825323059660003513214318348095846503023690500587249826662641957173100997394275949734815689523497648929187479547113736503296.000000
P(2, 300) = 0.000000
P(290, 300) = 0.019787
P(320, 300) = 0.011612 */