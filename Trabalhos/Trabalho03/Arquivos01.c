#include <stdio.h>
#include <string.h>

int main(void){
    FILE *entrada;
    entrada = fopen("arquivoentrada01.txt","rt");
    FILE *saida;
    saida = fopen("arquivosaida01.txt","w");

    int v[100], k, l[100], i = 0, j = 0, m = 0, n = 0;
    while(!feof(entrada))
    {
        
        fscanf(entrada, "%i ", &v[i]);

        if (i == 0){ l[j] = v[i]+1; printf("iniciando em l[%i] = %i\n", j, l[j]);}
        //& start in l[0] = 10

        printf("%i ", v[i]);


        if (m == l[j]-1 && i != 0){ 
            j++;
            fscanf(entrada, "%i ", &l[j]);
            l[j] = l[j] + 1;
            m = 0; 
            printf("\npulando linha em l[%i] = %i:\n", j, l[j]);
        }   


        m++;
        i++;
        n = j;
    };
    fclose(entrada);

    i = 0;
    printf("\nn = %i\n", n);
    for (j = 0; j < n; j++)
    {
        printf("linha %i ", j);
        printf("N = %i \n", l[j]);
        for (m = 0; m <= l[j]-1; m++){
            fprintf(saida, "%i ", v[i]);
            i++;
        }
        fprintf(saida, "\n");
    }    
}