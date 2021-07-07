#include <stdio.h>
#include <string.h>

int main(){
    char text[50], new_text[150];
    
    do {
        gets(text);
        if (strcmp(text, "EOF") == 0) return 0;
        int L = strlen(text);
        for (int i = 0, k = 0; i < L; i++){
            if (text[i] == '*' && k==0) {
                printf("<b>");
                k = 1;
            }
            else if (text[i] == '*' && k==1) {
                printf("</b>");
                k = 0;
            }
            else if (text[i] == '_' && k==0) {
                printf("<i>");
                k = 1;
            }
            else if (text[i] == '_' && k==1) {
                printf("</i>");
                k = 0;
            }
            else printf("%c", text[i]);
        }
        printf("\n");        
    } while (strcmp(text, "EOF") == 1);
}