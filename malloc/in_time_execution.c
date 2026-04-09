/* Two exemples. 
    One: The array's size is decided in execution time, with the most obvious way
    Two: The write function expected the adress of string pointer
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STEP 24
int write(char **S) ;

int main()
{
    char *p;
    int size;
    /*
    printf("Type the size of array: ");
    scanf("%d", &size);
    p = malloc(size * sizeof(int));
    if (p == NULL) {
        printf("Erro in alocation\n");
        return 1;
    }
    
    printf("Insert the elements: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", p + i);
    }
    */
    size = write(&p);
    printf("%s\n", p);
    printf("%d", size);
    
    free(p);
}

int write(char **S) 
{
    int stop = 0;
    int len = 0;
    int capacity = STEP + 1; // Always one superior to step
    char excerpt[STEP + 1];
    char *aux = NULL;
    
    *S = NULL;

    scanf(" ");
    while (!stop) {
        scanf("%24[^\n]", excerpt);
        if (strlen(excerpt) < STEP) stop = 1;
        
        if (!stop) capacity += STEP;
        else capacity += strlen(excerpt);
        aux = realloc(*S, capacity * sizeof(char));
        if(aux != NULL) *S = aux;
        else {
            printf("Allocation fail. Lack of memory.");
            free(*S);
            return 0;
        }
        strcpy(*S + len, excerpt);

        len += strlen(excerpt);
    }
    return len;
}