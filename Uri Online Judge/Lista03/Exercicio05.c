#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char sentence[50];

    //do {
        gets(sentence);
        int n = strlen(sentence);
        for (int i = 0, k = 0; i < n; i++)
        {
            if (k == 0){
                printf("%c", toupper(sentence[i]));
                k = 1;
            }
            else{
                printf("%c", tolower(sentence[i]));
                k = 0;
            }
        }
    //} while (0 == 0);
}