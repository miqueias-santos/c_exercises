#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct { 
    char *title;
    char *studio;
    char *console;
    int note;
    int year;
} Game;

void init_struct(Game *game);
void free_struct(const Game *game);
void free_colecao(Game *colecao, const int N);
Game *control_data_struct(Game *game);
Game *read_data(int *N);

void print_ano(const Game *colecao, const int N, const int year);
void print_letra(const Game *colecao, const int N, const char c);
void print_studio(const Game *colecao, const int N, const char* studio);
void print_console(const Game *colecao, const int N, const char* console);
void print_colecao(const Game *colecao, const int N);

#endif