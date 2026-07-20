#include <stdio.h>

#include "extern.h"
int sum();

int main () {
    int media = sum();
}

int sum() {
    int soma = 0, parcelas;
    for (int i = 0; i < quant; ++i) {
        scanf("%d", &parcelas);
        soma += parcelas;
    }
    return soma;
}
