#include <stdio.h>


/* 
Num frigorífico existem 10 bois. Cada boi traz preso
no seu pescoço um cartão contendo um número de
identificação e seu peso. Implementar um algoritmo
que escreva o número e o peso do boi mais gordo e do
boi mais magro (não é necessário armazenar os dados
de todos os bois). 
*/


int main(void){
    double ox_weight[10], heaviest_weight = 0;
    int ox_id[10], heaviest_id;
    
    for(int i = 0; i < 10; i++){
        printf("Type the ox[%i] id number: ", i);
        scanf("%i", &ox_id[i]);
        printf("Type the ox[%i] weight: ", i);
        scanf("%lf", &ox_weight[i]);

        if (ox_weight[i] > heaviest_weight){
            heaviest_weight = ox_weight[i];
            heaviest_id = ox_id[i];
        } 
    }

    printf("Id of the heaviest ox: %i\nWeight of the heaviest: %2.lf Kg", heaviest_id, heaviest_weight);
}