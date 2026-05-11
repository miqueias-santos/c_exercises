#include "my_header.h"

int main()  
{
    int N;
    Game *colecao = read_data(&N);
        
    if (colecao == NULL) {
        printf("Allocation has failed.\n");
        return 1;
    }

    char function[50];
    char c;
    char buffer[100];
    int year;
    
    while (scanf("%s", function) != EOF) {
        if (!strcmp(function, "printAno")) {
            scanf("%d", &year);
            print_ano(colecao, N, year);
        }
        else if (!strcmp(function, "printLetra")) {
            scanf(" %c", &c);
            print_letra(colecao, N, c);
        }
        else if (!strcmp(function, "printStudio")) {
            scanf(" %s", buffer);
            print_studio(colecao, N, buffer);
        }
        else if (!strcmp(function, "printConsole")) {
            scanf(" %s", buffer);
            print_console(colecao, N, buffer);
        }
        else print_colecao(colecao, N);
    }
    printf("Enjoei de jogar, agora vou ver TV.\n");

    free_colecao(colecao, N);
    return 0;
}

void init_struct(Game *game) {
    game->title = NULL;
    game->studio = NULL;
    game->console = NULL;
}

void free_struct(const Game *game) {
    free(game->title);
    free(game->studio);
    free(game->console);
}

void free_colecao(Game *colecao, const int N) {
    for (int i = 0; i < N; i++) free_struct(colecao + i);
    free(colecao);
}

Game *control_data_struct(Game *game) { // Controla a alocação para cada campo da struct
    init_struct(game);
    char word[100];
    
    scanf(" %99s", word); // recebe title
    game->title = malloc(strlen(word) + 1);
    if (game->title == NULL) {
        printf("Allocation has failed.\n");
        return NULL;
    }
    strcpy(game->title, word);
    

    scanf(" %99s", word); // ignora gênero
    

    scanf(" %99s", word); // recebe studio
    game->studio = malloc(strlen(word) + 1);
    if (game->studio == NULL) {
        printf("Allocation has failed.\n");
        return NULL;
    }
    strcpy(game->studio, word);


    scanf(" %99s", word); //console
    game->console = malloc(strlen(word) + 1);
    if (game->console == NULL) {
        printf("Allocation has failed.\n");
        return NULL;
    }
    strcpy(game->console, word);

    scanf("%d", &game->note); 
    if(game->note > 7) printf("AWESOME! Mais um GOTY pra minha coleção!\n");
    else if (game->note < 4) printf("Era melhor jogar mais um jogo de Mahjong.\n");
    
    scanf("%d", &game->year);

    return game;
}

Game *read_data(int *N) { // Cria a coleção de games
    scanf("%d", N);
    
    Game *colecao = malloc(*N * sizeof(Game));
    if (colecao == NULL) return NULL;
    
    for (int i = 0; i < *N; i++) {
        if (control_data_struct(colecao + i) == NULL) {
            for (int j = i; j >= 0; j--) free_struct(colecao + j);
            return NULL;
        }
    }
    
    return colecao;
}

void print_ano(const Game *colecao, const int N, const int year) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if(colecao[i].year == year) {
            printf("%s\n", colecao[i].title);
            count++;
        }
    }
    if (count) printf("Tenho %d jogos || %d.\n", count, year);
    else printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
}

void print_letra(const Game *colecao, const int N, const char c) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if(colecao[i].title[0] == c) {
            printf("%s\n", colecao[i].title);
            count++;
        }
    }
    if (count) printf("Tenho %d jogos || %c.\n", count, c);
    else printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
}

void print_studio(const Game *colecao, const int N, const char* studio) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if(!strcmp(colecao[i].studio, studio)) {
            printf("%s\n", colecao[i].title);
            count++;
        }
    }
    if (count) printf("Tenho %d jogos || %s.\n", count, studio);
    else printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
}

void print_console(const Game *colecao, const int N, const char* console) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if(!strcmp(colecao[i].studio, console)) {
            printf("%s\n", colecao[i].title);
            count++;
        }
    }
    if (count) printf("Tenho %d jogos || %s.\n", count, console);
    else printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
}

void print_colecao(const Game *colecao, const int N) {
    for (int i = 0; i < N; i++) printf("%s %d\n", colecao[i].title, colecao[i].note);
}