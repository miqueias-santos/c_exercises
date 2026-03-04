/* Programa iniciado no dia 04.03.2026. 
   Resolucao da questao 1; lista 1 da matéria de Fundamentos de Programação Imperativa. Miquéias Santos */
#include <stdio.h>

struct Data{
    unsigned char dia;
    unsigned char mes;
    int ano;
};  
void init(struct Data* data){
    data->dia = 0;
    data->mes = 0;
    data->ano = 0;
}

int main(void){
    struct Data aniversario;
    struct Data atual;

    init(&aniversario);
    init(&atual);

    scanf("%c/%c/%d", &aniversario.dia, &aniversario.mes, &aniversario.ano); 
    scanf("%c/%c/%d", &atual.dia, &atual.mes, &atual.ano);

    printf("%d %d %d %d %d %d ", aniversario.dia, aniversario.mes, aniversario.ano, atual.dia, atual.mes, atual.ano);
    
    int amor = (aniversario.dia + aniversario.mes + aniversario.ano + atual.dia + atual.mes + atual.ano) * 7 % 101;
    
    return 0;
}