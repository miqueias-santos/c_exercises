#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char *NAME;
	int AMOUNT;
	int DANGER;
	char *FUN;
} Cidadel;

Cidadel *create_cidadels();
char* read_message();

int main() {
	
	Cidadel *cidadels = create_cidadels();	
    int i = 0;
    


    free(cidadels);
	return 0;
}

Cidadel *create_cidadels() {
	Cidadel *cidadels = NULL;
    char *aux = NULL;
    int n_cidadels; // capacidade de realocação
    int idx; // index da cidadel
    int len;
	
    char *message = read_message();
    if (message == NULL) return NULL;
    len = strlen(message);

    n_cidadels = 5;
    idx = 0;
    cidadels = malloc(n_cidadels * sizeof(Cidadel));
    
    int blanck = 0;
    for (int c = 0; c < len; c++) {
        if (message[c] == '\n') idx++; // ?
        
        else if (isdigit(message[c])) cidadels[idx].AMOUNT = cidadels[idx].AMOUNT * 10 + message[c] - '0';
        else if (isupper(message[c])) {
            int terminator = strlen(cidadels[idx].NAME);
            aux = realloc(cidadels[idx].NAME, strlen(cidadels[idx].NAME) + 2);
            //verificação
            cidadels[idx].NAME = aux;
            cidadels[idx].NAME[terminator + 1] = '\0';
            cidadels[idx].NAME[terminator] = message[c] + 32;
        }
        else if (message[c] == '*') cidadels[idx].DANGER++;
        
        
        
        if (blanck == 2) message[c] // É
        if (message[c] != ' ') blanck = 0;
        else blanck++;
    }
	
    return message;	

}

char* read_message() {
    char buffer[51]; 
    char *message = NULL, *aux = NULL;
    int cap = 1;
    buffer[50] = '\0';
    
    while (scanf("%50[^/]", buffer) != EOF) {
		aux = realloc(message, (cap + strlen(buffer)) * sizeof(char));
		if (aux == NULL) {free(message); return NULL;}
		message = aux;
		strcpy(message + cap - 1, buffer);	
		cap += strlen(buffer);
	} 
    return message;
}

