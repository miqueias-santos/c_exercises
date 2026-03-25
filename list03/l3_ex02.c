#include <string.h>
#include <stdio.h>
#define MAX 101
int main(void){
    char string[MAX];
    scanf(" %100[^\n]", string);
    //supondo que existam palavras

    int n_word = 0;
    for(int i = 0; i < (int)strlen(string) + 1; i++){
        if(string[i] == ' ' || string[i] == '\0'){
            n_word++;
        }
    }
    int idx[MAX];
    idx[0] = 0;
    int cont = 1;

    for(int i = 1; i < (int)strlen(string); i++){
        if(string[i] == ' ') {idx[cont] = i+1; cont++;}
    }

    for(int i = 0; i < n_word; i++){
        
    }


    for(int i = 0; i < n_word; i++){
        printf("%d ", idx[i]);
    }


    




}