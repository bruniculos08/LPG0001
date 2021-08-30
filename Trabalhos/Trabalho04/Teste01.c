#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main (void){
    FILE *arquivo_vetores;
    arquivo_vetores = fopen("teste01.txt", "r+b");
    int *agenda;
    agenda = NULL;
    int n, aux;

    if (arquivo_vetores == NULL){
        printf("Error\n");
    }
    else{
        for (int i = 0; i < sizeof(*agenda)/sizeof(int); i++) {
            agenda = realloc(agenda, sizeof(*agenda) + sizeof(int));
            fread(&agenda[i], sizeof(int), 1, arquivo_vetores);
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d\n", agenda[i]);
        }
    }
    
    n = sizeof(*agenda)/sizeof(int);
    printf("%d\n", n);

    arquivo_vetores = freopen("teste01.txt", "r+b", arquivo_vetores);

    printf("Type how many new numbers: ");
    scanf("%d", &aux);
    agenda = realloc(agenda, sizeof(*agenda) + aux*sizeof(int)-1);

    for (int i = 0; i < aux; i++){
        scanf("%i", &agenda[i+n-1]);
    }


    for (int i = 0; i <= sizeof(*agenda)/sizeof(int); i++)
    {
        printf("%d\n", agenda[i]);
    }
    
    fclose(arquivo_vetores);
    arquivo_vetores = fopen("teste01.txt", "w+b");
    fseek(arquivo_vetores, 0, SEEK_SET);
    for (int i = 0; i <= sizeof(*agenda)/sizeof(int); i++) {
        fwrite(&agenda[i], sizeof(&agenda[i]), 1, arquivo_vetores);
    }


    fclose(arquivo_vetores);
}