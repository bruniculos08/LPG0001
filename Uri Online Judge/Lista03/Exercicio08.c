#include <stdio.h>
#include <string.h>

int main(){
    int N;
    scanf("%i", &N);       
    for (int i = 0; i <= N; i++)
    {
        char phrase[50];//, word[50];
        gets(phrase);
        int n = strlen(phrase), k = 0;
        for (int j = 0; j < n; j++){
            if (j == 0 && phrase[j] != ' '){
                //word[j] = phrase[j]; 
                printf("%c", phrase[j]);
            }

            else if (phrase[j] == ' ') k = 1;
            
            else if (phrase[j] != ' ' && k == 1){
                printf("%c", phrase[j]);
                //word[j] = phrase[j];
                k = 0;
            }
        }
        //printf("%s\n", word);
        printf("\n"); 
    }
}