#include <stdio.h>

int main(void){
    int div;
    scanf("%d", &div);

    int is_primo = 1;       
    
    //improved and last version
    if(div % 2 == 0 && div != 2) is_primo = 0;
    if(div % 2 == 1) for(int k = 3; is_primo && k <= div/k; k += 2) if(div % k == 0) is_primo = 0;
    
    printf("%d", is_primo);

    return 0;
}

//inicial version of ideia
int is_primo(unsigned num){
    int is_primo = 1;       
    for(int k = 2; is_primo && k <= num/k; k++){
        if(num % k == 0) is_primo = 0;
    }
    return 0;
}