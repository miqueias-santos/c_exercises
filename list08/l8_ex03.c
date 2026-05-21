#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int ID;
    char nome[50];
    unsigned int quantidade;
    float preço;
} Produto;

typedef struct {
    unsigned int ID;
    char tipo;
    unsigned int quantidade;
} Movimento;


Produto *set_produtos(int *N) {
    *N = 0;
    int capacity = 4;
    Produto *produtos = NULL;
    
    FILE *f = fopen("produtos.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return NULL;
    }
    
    produtos = malloc(capacity * sizeof(Produto));
    if (produtos == NULL) {
        printf("Allocation has failled!\n");
        return NULL;
    }

    Produto *aux = NULL;
    while(fscanf(f, "%d %s %d %f", &produtos[*N].ID, produtos[*N].nome, &produtos[*N].quantidade, &produtos[*N].preço) !=  EOF) {
        (*N)++;
        
        if (*N >= capacity) {
            capacity += 4;
            aux = realloc(produtos, capacity * sizeof(Produto));
            if (aux == NULL) {
                printf("Allocation has failled!\n");
                free(produtos);
                return NULL;
            }
            produtos = aux;
        }
    }

    fclose(f);
    return produtos;
}

Movimento *set_movimentos(int *N) { // Seria possivel uma função genérica para abrir ambos
    *N = 0;
    int capacity = 4;
    Movimento *movimentos = NULL;
    
    FILE *f = fopen("movimentos.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return NULL;
    }
    
    movimentos = malloc(capacity * sizeof(Movimento));
    if (movimentos == NULL) {
        printf("Allocation has failled!\n");
        return NULL;
    }

    Movimento *aux = NULL;
    while(fscanf(f, "%d %c %d", &movimentos[*N].ID, &movimentos[*N].tipo, &movimentos[*N].quantidade) !=  EOF) {
        (*N)++;
        
        if (*N >= capacity) {
            capacity += 4;
            aux = realloc(movimentos, capacity * sizeof(Movimento));
            if (aux == NULL) {
                printf("Allocation has failled!\n");
                free(movimentos);
                return NULL;
            }
            movimentos = aux;
        }
    }

    fclose(f);
    return movimentos;
}

Movimento *set_inconsciencia(Movimento *m, int new_len) {
    Movimento *new = realloc(m, new_len * sizeof(Movimento));
    if (new == NULL) {
        free(m);
        printf("Reallocation has failled\n");
        return NULL;
    }
    return new; 
}

int resolve(Produto *master, int n_master, Movimento *moves, int n_moves) {
    Movimento *inconsistencias = NULL;
    int n_inconsistencias = 0;
    int movimentos_sem_cadastro = 0;
    int saidas_recusadas = 0;
    int produtos_processados = 0;

    for (int i = 0; i < n_moves; i++) { // Ao fim do loop, master é alterado e inconsistências são pegas;
        int j = 0;
        int out = 0; // flag

        while(master[j].ID != moves[i].ID && !out)  {
            j++;
            if (j == n_master) out = 1;
        }
    
        if (!out) {
            if (moves[i].tipo == 'E') master[j].quantidade += moves[i].quantidade;
            else {
                if (master[j].quantidade < moves[i].quantidade) saidas_recusadas++;
                else master[j].quantidade += -moves[i].quantidade;
            }
        }
        else movimentos_sem_cadastro++; 

        if (saidas_recusadas + movimentos_sem_cadastro > n_inconsistencias) {
            inconsistencias = set_inconsciencia(inconsistencias, saidas_recusadas + movimentos_sem_cadastro);
            if (inconsistencias == NULL) return 1;
            inconsistencias[n_inconsistencias] = moves[i]; 
            n_inconsistencias++;
        }

    }
    // estoque (f) e relatorio (g)
    FILE *f, *g;
    f = fopen("estoque_atualizado.txt", "w");
    g = fopen("relatorio.txt", "w");

    fprintf(g, "PRODUTOS PROCESSADOS: %d\n", n_master); 
    fprintf(g, "MOVIMENTOS APLICADOS: %d\n", n_moves - n_inconsistencias);
    fprintf(g, "SAIDAS RECUSADAS: %d\n", saidas_recusadas);
    fprintf(g, "MOVIMENTOS SEM CADASTRO: %d\n", movimentos_sem_cadastro);

    
    fputs("ESTOQUE BAIXO:\n", g);
    
    for (int i = 0; i < n_master; i++) {
        fprintf(f, "%d %s %d %.2f\n", master[i].ID, master[i].nome, master[i].quantidade, master[i].preço);
        if (master[i].quantidade <= 5) fprintf(g, "%d %s %d\n", master[i].ID, master[i].nome, master[i].quantidade);
    }
    
    fputs("INCONSISTENCIAS:\n", g);
    
    for (int i = 0; i < n_inconsistencias; i++) {
        fprintf(g, "%d %c %d ", inconsistencias[i].ID, inconsistencias[i].tipo, inconsistencias[i].quantidade);
        
        int no_exist = 0;
        int j = 0;
        while(master[j].ID != inconsistencias[i].ID && !no_exist)  {
            j++;
            if (j == n_master) no_exist = 1;
        }
        if (no_exist) fputs("PRODUTO_INEXISTENTE\n", g);
        else fputs("ESTOQUE_INSUFICIENTE\n", g);
    }
    
    fclose(f);
    fclose(g);

    return 0;
}


int main() {
    int numero_produtos, numero_movimentos;
    Produto *produtos = set_produtos(&numero_produtos);
    if (produtos == NULL) return 0;

    Movimento *movimentos = set_movimentos(&numero_movimentos);
    if (movimentos == NULL) { free(produtos); return 0; }

    if(resolve(produtos, numero_produtos, movimentos, numero_movimentos))

    free(produtos);
    free(movimentos);
    return 0;
}
