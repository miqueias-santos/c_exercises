#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
    int capacity;
} String;

String *read() { 
    String *str = malloc(sizeof(String));
    str->str = NULL;
    str->capacity = 1;
    int len = 0;
    char excerpt[10 + 1];     
    char *aux;
    do {
        scanf("%10[^\n]", excerpt); // Recebe pacotes de 10
        aux = realloc(str->str, (str->capacity + strlen(excerpt)) * sizeof(char)); // ?
        if (aux == NULL) {
            printf("Memory failed");
            return str;
        }
        str->str = aux;
        strcpy(str->str + str->capacity - 1, excerpt);
        str->capacity += strlen(excerpt);
    }
    while (strlen(excerpt) == 10);
    return str;
// QUANDO ALOCAR? QUANDO CAPACITY < LEN + 1
}

int main () {
    String *my_string = read();
    printf("%d\n", strlen(my_string->str));
    // for (int i = 0; i < strlen(my_string->str); i++) printf("%c", my_string->str[i]);
    free(my_string->str);
    free(my_string);
}