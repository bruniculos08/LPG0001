#include <stdio.h>
#include <string.h>

int main(void){
    FILE *entrada;
    entrada = fopen("arquivoentrada01.txt","rt");
    FILE *saida;
    saida = fopen("arquivosaida01.txt","w");

    int v[100], m, k, l[100], i = 0, j = 0, n = 100;
    do
    {
        /* if (j==n+1){                                    //& quando j = n+1 significa que já foram lidos N números          
            j = 0;                                      //& j = 0 pois volta para início de linha
            fscanf(entrada, "\n%i ", &v[i]);            //& scan na próxima linha
        }
        if (j == 0){                                    //& verificando primeiro N da linha
            fscanf(entrada, "%i ", &n);
            v[i] = n;
            l[i] = v[i];                                //& armazenando o primeiro N em n
            printf("%i\n", n);
        }
        j++;                                            //& se j = 0 é começo de linha
        if (j!=0) fscanf(entrada, "%i ", &v[i]);        //& se j diferente de 0 então está no meio da linha
        i++;
        k = i;  */
        fscanf(entrada, "%i ", &v[i]);
        i++;
        k = i;
    } while (!feof(entrada));
    
    fclose(entrada);
    m = l[0];
    for (i = 0, j = 0; i < k ; i++)
    {   
        if (i == m){ 
            fprintf(saida, "%i\n", v[i]);
            m = m + l[j];
        } 
        else
        {
            fprintf(saida, "%i ", v[i]);
        }
        
    }
    
}