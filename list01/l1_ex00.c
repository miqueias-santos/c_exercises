/* Programa iniciado no dia 04.03.2026. 
   Resolucao da questao 1; lista 1 da matéria de Fundamentos de Programação Imperativa. Miquéias Santos */

#include <stdio.h>
#include <math.h>
//#define é bom para constantes, alias, diretica ifdef e funções macros (possivelmente genérica)
#define mpow(p) (p*p) //função macro. Não aqui, mas parênteses podem ser necessarios por precedência
#define mabs(a) ((a) >= 0 ? (a) : -(a)) //um exagero de parentesis necessarios

//justificando: optei em vez de criar 6 variaveis separadas ou um array de 6 inteiros ou 2 arrays e 3 inteiros, etc...
struct Data{
    int dia;
    int mes;
    int ano;
};  

void evaluate(int a, int s, int t, int c);

int main(void){

    struct Data aniversario;
    struct Data atual;

    scanf("%d/%d/%d", &aniversario.dia, &aniversario.mes, &aniversario.ano); 
    scanf("%d/%d/%d", &atual.dia, &atual.mes, &atual.ano);
    
    int amor = (aniversario.dia + aniversario.mes + aniversario.ano + atual.dia + atual.mes + atual.ano) * 7 % 101;
    int sorte = ((aniversario.dia + atual.dia + aniversario.mes + atual.mes) * 9 + mabs(aniversario.ano - atual.ano) ) % 101;
    int trabalho = (aniversario.ano + atual.ano - (aniversario.mes + atual.mes + aniversario.dia + atual.dia)*8) % 101;
    int cor = (mpow(aniversario.dia) + mpow(atual.dia) + mpow(aniversario.mes) + mpow(atual.mes) + mpow(aniversario.ano) + mpow(atual.ano)) % 11;
    
    evaluate(amor, sorte, trabalho, cor);

    return 0;
}

void evaluate(int a, int s, int t, int c){
    printf("Amor: %d%% ", a);
    if(a < 20) printf("Pessimo dia para se apaixonar.");
    else if(a >= 20 && a <= 40) printf("Melhor manter o coracao <3 longe de perigo.");
    else if(a >= 41 && a <= 69) printf("Se o papo e as ideias baterem, esta liberado pensar em algo.");
    else if(a >= 70 && a <= 80) printf("Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.");
    else printf("Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.");

    printf("\nSorte: %d%% ", s);
    if(s < 30) printf("Nem jogue moedas pra cima hoje.");
    else if(s >= 30 && s <= 50) printf("Melhor nao arriscar.");
    else if(s >= 51 && s <= 79) printf("Por sua conta em risco.");
    else if(s >= 80 && s <= 90) printf("Hoje vale a pena arriscar.");
    else printf("Nao tenha medo de virar cartas hoje.");
    printf(" Sem tigrinho nem jogos de azar, por favor!");

    printf("\nTrabalho: %d%% ", t);
    if(t < 40) printf("Hoje nao sera um dia tao proveitoso, keep calm e faca o basico.");
    else if(t >= 40 && t <= 50) printf("Segura a emocao, nao xinga ninguem, nao esquece de beber agua.");
    else if(t >= 51 && t <= 69) printf("Um dia proveitoso com certeza, leve sua simpatia consigo.");
    else if(t >= 70 && t <= 84) printf("Boas vibracoes hoje, chances podem estar ao seu redor.");
    else printf("Use do maximo de networking possível hoje, dia bom para negocios.");

    printf("\nCor: ");
    switch(c){
        case 0: printf("Cinza."); break;
        case 1: printf("Vermelho."); break;
        case 2: printf("Laranja."); break;
        case 3: printf("Amarelo."); break;
        case 4: printf("Verde."); break;
        case 5: printf("Azul."); break;
        case 6: printf("Roxo."); break;
        case 7: printf("Marrom."); break;
        case 8: printf("Rosa."); break;
        case 9: printf("Preto."); break;
        case 10: printf("Branco."); break;
    }

}