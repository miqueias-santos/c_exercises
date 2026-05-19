#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    unsigned int ID : 10;
    unsigned int status : 3;
    unsigned int low_battery : 1;
    signed int temperature : 12; 
    unsigned int control : 6;
} Protocol;

typedef union {
    uint32_t raw;
    Protocol status;
} Package;

// Retorna um ponteiro realocado para Package, se encarregado de liberar o ponteiro passado. Retorna NULL se não consegue realocar.
Package *safe_realloc(Package *packages, int *capacity) {
    Package *aux = NULL;
    
    *capacity *= 2;
    aux = realloc(packages, *capacity * sizeof(Package));
    
    if (aux == NULL) {
        free(packages);
        printf("Memory allocation has failled\n");
        return NULL;
    }

    packages = aux;
    return packages;
}

Package *init_package(int *len, int *capacity) {
    Package *packages = NULL;
    *len = 0; 
    *capacity = 4;
    
    packages = malloc(*capacity * sizeof(Package));
    
    if (packages == NULL) {
        printf("Memory allocation has failled\n");
        return NULL;
    }
    
    return packages;
}

Package *set_data(int *len, int *capacity) {
    Package *packages = init_package(len, capacity);
    if(packages == NULL) return NULL;
    
    uint32_t hex = -1;
    while (hex != 0) {
        scanf("%X", &hex);
        
        if (hex != 0) {
            if (len >= capacity) {
                packages = safe_realloc(packages, capacity);
                if (packages == NULL) return NULL;
            }
            packages[*len].raw = hex;
            (*len)++;
        }
    }
    return packages;

}

void set_output(const Package *packages, const int len) {
    for (int i = 0; i < len; i++) {
        printf("Pacote [%d] - Dado Bruto: 0x%08X\n", i + 1, packages[i].raw);
        printf("ID do Sensor : %d\n", packages[i].status.ID);
        printf("Status : %d\n", packages[i].status.status);
        if (!packages[i].status.low_battery) {
            printf("Bateria Baixa: Nao\n");
        }
        else {
            printf("Bateria Baixa: SIM (ALERTA)\n");
        }
        
        printf("Temperatura : %d graus\n", packages[i].status.temperature);
        puts("--------------------------------------");
        puts("-----------");
        
    }
}

int main() {
    
    int len, capacity;
    Package *packages = set_data(&len, &capacity);
    if (packages == NULL) return 0;
    
    set_output(packages, len);

    free(packages);
    return 0;
}

