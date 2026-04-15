#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STEP 4

char *control_realloc(char *string, int *capacity, int size, int size_excp);
int main()
{
    int N = 4;
    // scanf("%d", &N);

    // Allocation variables
    char *string = NULL;
    int capacity = 1, size = 0;

    int *idx = NULL, *len = NULL;
    char excerpt[STEP + 1];
    int len_excerpt;
    int count_word = 0;
    int end = 0;

    // scanf(" ");
    while (!end) {

        // scanf("%4[^\n]", excerpt);
        len_excerpt = strlen(excerpt);
        
        if (len_excerpt < STEP && count_word != N - 1) {
            count_word++;
            size++;
            capacity++;
        }
        
        end = (count_word == N) ? 1 : 0;
        
        string = control_realloc(string, &capacity, size + len_excerpt, len_excerpt);
        strcpy(string + size - 1, excerpt);        
         
        
        size += strlen(excerpt);
        
    }   
    
    free(string); 
    return 0;
}

void free_them_all(const void *list[]) // Testando algo novo!
{

}

char *control_realloc(char *string, int *capacity, int size, int size_excp) 
{
    char *reallocated = NULL;
    if (*capacity <= size + 1) {
        *capacity = *capacity + size_excp;
        reallocated = realloc(string, *capacity * sizeof(char));
        
        if (reallocated == NULL) {
            printf("Allocation have failed.");
            if(string != NULL) free(string);
        }
    }
    
    return reallocated;
}