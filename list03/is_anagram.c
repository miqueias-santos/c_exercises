#include <stdio.h>
#include <string.h>
#define MAX 101

int is_anagram(char* str1, char* str2);

int main(void){
    char str1[51] = "patos";
    char str2[51] = "pato";
    /*scanf(" %50[^\n]", str1);
    scanf(" %50[^\n]", str2);*/
    printf("%d\n", is_anagram(str1, str2));

    return 0;
}

int is_anagram(char* str1, char* str2){
    int idx_analisados[MAX];
    for(int i = 0; i < MAX; i++)idx_analisados[i] = -1;
    int correspondencia = 0;

    if(strlen(str1) != strlen(str2)) return 0;
    else{
        
        for(int i = 0; i < (int)strlen(str1); i++){ //para cada letra no index i, a uma correspondência 1 para 1 com uma letra de index j    
            for(int j = 0; j < strlen(str2); j++){
                int c = 0;
                int out = 1;
                while(idx_analisados[c] >= 0){if(idx_analisados[c] == j) out = 0; c++;} ;
                if(str1[i] == str2[j] && out){
                    idx_analisados[i] = j;
                    correspondencia++;
                }
            }
        }
        if(correspondencia == (int)strlen(str1)) return 1;
        else return 0;
    }
}