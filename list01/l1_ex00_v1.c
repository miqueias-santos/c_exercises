/* Programa iniciado no dia 04.03.2026. 
   Resolucao da questao 1; lista 1 da matéria de Fundamentos de Programação Imperativa. Miquéias Santos */

#include <stdio.h>

int main(void){
    int aniversario_dia, aniversario_mes, aniversario_ano, atual_dia, atual_mes, atual_ano;

    scanf("%d/%d/%d", &aniversario_dia, &aniversario_mes, &aniversario_ano); 
    scanf("%d/%d/%d", &atual_dia, &atual_mes, &atual_ano);
    
    int amor = (aniversario_dia + aniversario_mes + aniversario_ano + atual_dia + atual_mes + atual_ano) * 7 % 101;
    int sorte;
    if(aniversario_ano - atual_ano >= 0){
        sorte = ((aniversario_dia + atual_dia + aniversario_mes + atual_mes) * 9 + aniversario_ano - atual_ano ) % 101;
    }
    else{
        sorte = ((aniversario_dia + atual_dia + aniversario_mes + atual_mes) * 9 + -(aniversario_ano - atual_ano) ) % 101;
    }
    
    int trabalho = (aniversario_ano + atual_ano - (aniversario_mes + atual_mes + aniversario_dia + atual_dia)*8) % 101;
    int cor = (aniversario_dia * aniversario_dia + atual_dia * atual_dia + aniversario_mes * aniversario_mes + atual_mes * atual_mes + aniversario_ano * aniversario_ano + atual_ano * atual_ano) % 11;
    
    printf("Amor: %d%% ", amor);
    if(amor < 20) printf("Pessimo dia para se apaixonar.");
    else if(amor >= 20 && amor <= 40) printf("Melhor manter o coracao <3 longe de perigo.");
    else if(amor >= 41 && amor <= 69) printf("Se o papo e as ideias baterem, esta liberado pensar em algo.");
    else if(amor >= 70 && amor <= 80) printf("Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.");
    else printf("Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.");

    printf("\nSorte: %d%% ", sorte);
    if(sorte < 30) printf("Nem jogue moedas pra cima hoje.");
    else if(sorte >= 30 && sorte <= 50) printf("Melhor nao arriscar.");
    else if(sorte >= 51 && sorte <= 79) printf("Por sua conta em risco.");
    else if(sorte >= 80 && sorte <= 90) printf("Hoje vale a pena arriscar.");
    else printf("Nao tenha medo de virar cartas hoje.");
    printf(" Sem tigrinho nem jogos de azar, por favor!");

    printf("\nTrabalho: %d%% ", trabalho);
    if(trabalho < 40) printf("Hoje nao sera um dia tao proveitoso, keep calm e faca o basico.");
    else if(trabalho >= 40 && trabalho <= 50) printf("Segura a emocao, nao xinga ninguem, nao esquece de beber agua.");
    else if(trabalho >= 51 && trabalho <= 69) printf("Um dia proveitoso com certeza, leve sua simpatia consigo.");
    else if(trabalho >= 70 && trabalho <= 84) printf("Boas vibracoes hoje, chances podem estar ao seu redor.");
    else printf("Use do maximo de networking possível hoje, dia bom para negocios.");

    printf("\nCor: ");
    switch(cor){
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

    return 0;
}

