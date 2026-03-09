#include <stdio.h>
int main(void){
    short n;
    scanf("%hd", &n);
    long long fatorial = 1;

    for(; n > 0; n--){
        fatorial *= n;
    }
    printf("%lld", fatorial);

    return 0;
}