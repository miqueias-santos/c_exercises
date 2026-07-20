#include <stdio.h>

enum exemplo { A, B, C };
int main() {
    printf("hello, world\n");
    int a = 0Xa7DUL;
    float b = 0.31e-1F;
    char c = '\010';

    char *d = "hello"

    ", " "wor"
    "ld!\n";
    enum exemplo e = B;

    printf("%d\n", e == A); // permite comparações
}

/*
constantes inteiras

 constantes inteiras são do tipo int por padrão, a menos que não caibam em taL
 1000L -> torna long
 1000U -> torna unsigned
 1000UL -> torna unsigned long
- Podem ser u/l;
- Um número que comece com 0 é octal
- Um que comece com 0x ou 0X é hexadecimal. 0xA, 0xa, 0XA, 0Xa são os mesmos números

constantes ponto-fluantes
 são por padrão double e contem um . ou e. ex: 64.3 ou 643e-1 ou 0.643e2
 0.64F -> torna float
 0.64L-> torna long

constante de caracteres
 é um inteiro. Portanto, participa de operações como qualquer outro.
 seu valor depende do machine's set character
 /ooo ou /xhh especifica um padrão de bits do tamanho de um byte. Não /Xhh
 '/0' -> caracter cujo valor é 0. The null caracter.

expressões constantes
 expressões que só envolvem constantes. Avaliadas em tempo de compilação

string constants
 conjunto de constante de caracteres. Sequência de caracteres cercadas por "";
 concatenadas em tempo de execução

constantes de enumeração
 são, por definição, uma lista de constantes inteiras
 É uma forma mais conviniente que define para associar nomes com constantes
 Valores não precisam ser distintos, porém nomes no mesmo enum sim

*/
