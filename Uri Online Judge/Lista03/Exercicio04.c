#include <stdio.h>
#include <string.h>

int main(){
    int N, L, C; //^ nº de palavras, nº máx. de linhas por pág., nº máx. de caracteres por linha.

    scanf("%i %i %i ", &N, &L, &C);

    int p = 0, l = 0;

    char text[2100];// words[N][C];
    
    gets(text);
    int len = strlen(text);
    for (int i = 0, k= 0, c = 0; i < len; i++){   
        c++;
        //if (text[i] != ' ') k++;
        //else k = 0;
        if (c == C){
            l++;
            if (l == L){
                l = 0;
                p++;
            }
            c = 0;
           // if (text[i] != ' ' && text[i-1] != ' ') i = i-k;
        }
    }
    //if (l < L && l > 0) p++;
    printf("%i\n", p+1);
}