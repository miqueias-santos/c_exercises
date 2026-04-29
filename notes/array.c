#include <stdio.h>

int main(void);
int main(void);
int main(void);
int main(void);
//declaration can occurs multiple times, but it can define only once

int main(void){
    
    
    //int t[]; this isn't allowed
    int v[] ={0, 1, 2};

    //v is of type int[3]. It usually decay to int*
    int* p_to_first = v;

    int (*p_to_array )[] = &v; //it's a pointer to array itself
    printf("%p\n\n", p_to_first);

    printf("%-20s %p    size: %d\n", "v", v, sizeof(v)); 
    printf("%-20s %p    size: %d\n", "p_to_first_element", p_to_first, sizeof(p_to_first));
    printf("%-20s %p    size: %d\n\n", "p_to_array", p_to_array, sizeof(p_to_array));

    //int** p = &v; //warning
    //v++; error. v decay to a const pointer

    //*v -> v[0]
    printf("%p\n", v); //v, of type int[3], decay to int*
    printf("%d\n", *v);

    //*p_to_first -> v[0]
    printf("%p\n", p_to_first); 
    printf("%d\n", *p_to_first); 

    //*p_to_array -> v (which decay). It may be helpful to look at row 10. It receive out of &v; 
    printf("%p\n", p_to_array); //although the adress is as same as p_to_first, the type isn't
    printf("%p\n", *p_to_array);
    printf("%p\n", **p_to_array);

    /* int** p = &v;
    *p = *p + 1; */
    
    //printf("%p e %p\n", v, &v);

    return 0;
}

void see_array(int (*array)[], int len){ //This pointer use is actually kind of unusual, but passible
    for(int i = 0; i < len; i++){

    }
}