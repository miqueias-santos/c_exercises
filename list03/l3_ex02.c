#include <string.h>
#include <stdio.h>
#define MAX 101
int main(void){
    char string[MAX] = "amor roma pato peto";
    //scanf(" %100[^\n]", string);
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
    int len_string = (int)strlen(string);
    for(int i = 0; i < len_string; i++){
        if(string[i] == ' '){
            string[i] = '\0';
        }
    }


    for(int i = 0; i < n_word; i++){
        for(int j = 0; j < n_word; j++){
            if(j == i) continue;
            int is_anagram = 0;

            int idx_analisados[MAX];
            
            for(int k = 0; k < MAX; k++) idx_analisados[k] = -1;
            int correspondencia = 0;

            if(strlen(string+idx[i]) != strlen(string+idx[j])) is_anagram = 0;
            else{
                
                for(int k = 0; k < (int)strlen(string+idx[i]); k++){ //para cada letra no index i, a uma correspondência 1 para 1 com uma letra de index j    
                    for(int l = 0; l < strlen(string+idx[j]); l++){
                        int c = 0;
                        int out = 1;
                        while(idx_analisados[c] >= 0){if(idx_analisados[c] == l) out = 0; c++;} ;
                        if((string+idx[i])[k] == (string+idx[j])[l] && out){
                            idx_analisados[k] = l;
                            correspondencia++;
                        }
                    }
                }
                if(correspondencia == (int)strlen(string+idx[i])) is_anagram = 1;
                else is_anagram = 0;
            }

        }
    }

    for(int i = 0; i < n_word; i++){
        printf("%d ", idx[i]);
    }


}

