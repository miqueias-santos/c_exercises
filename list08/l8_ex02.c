#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned int sepal_length : 3;
    unsigned int sepal_width : 3;
    unsigned int petal_length : 3;
    unsigned int petal_width : 3;
    unsigned int specie : 3;
} Pos;


typedef struct {
    float sepal_length;
    float sepal_width;
    float petal_length;
    float petal_width;
} Data;

void treat_files(const int N) {
    char buffer[] = "irisX.csv";
    char scan[50];

    Pos pos;
    Data data;

    FILE *f = NULL;

    int setosa, versicolor, virginica;
    float dimensao;
    int flag;

    for (int i = 0; i < N; i++) { // por arquivo
        setosa = 0;
        versicolor = 0;
        virginica = 0;
        
        data.sepal_length = 0;
        data.sepal_width = 0;
        data.petal_length = 0;
        data.petal_width = 0;

        sprintf(buffer, "iris%d.csv", i + 1);
        f = fopen(buffer, "r+");
        
        int n_flores = 0;

        for (int i = 0; i < 5; i++) { // para a primeira linha
            fscanf(f, "%[^,^\n]", scan);
            fgetc(f);

            if (!strcmp(scan, "species")) pos.specie = i;
            else if (!strcmp(scan, "petal_width")) pos.petal_width = i;
            else if (!strcmp(scan, "petal_length")) pos.petal_length = i;
            else if (!strcmp(scan, "sepal_width")) pos.sepal_width = i;
            else pos.sepal_length = i;
        }
        
        flag = 1;
        n_flores = 0;
        while (flag) {    
            for (int i = 0; i < 5 && flag; i++) { // per line
                
                if (pos.specie == i) {
                    if (fscanf(f, "%[^,^\n]", scan) != EOF) {
                        fgetc(f);
                        if (!strcmp(scan, "Iris-setosa")) setosa++;
                        else if (!strcmp(scan, "Iris-versicolor")) versicolor++;
                        else virginica++;
                        n_flores++;
                    }
                    else flag = 0;
                }

                else if (pos.petal_width == i) {
                    if (fscanf(f, "%f", &dimensao) != EOF) {
                        fgetc(f);
                        data.petal_width += dimensao;
                    }
                    else flag = 0;
                }

                else if (pos.petal_length == i) {
                    if (fscanf(f, "%f", &dimensao) != EOF) {
                        fgetc(f);
                        data.petal_length += dimensao;
                    }
                    else flag = 0;
                }

                else if (pos.sepal_width == i) {
                    if (fscanf(f, "%f", &dimensao) != EOF) {
                        fgetc(f);
                        data.sepal_width += dimensao;
                    }
                    else flag = 0;
                }

                else {
                    if (fscanf(f, "%f", &dimensao) != EOF) {
                        fgetc(f);
                        data.sepal_length += dimensao;
                    }
                    else flag = 0;
                }
            }
            
        }
        fputs("\n\n[MEDIAS]\n", f);
        fprintf(f, "Media de 'sepal_length': %.2f\n", data.sepal_length/(float)n_flores);
        fprintf(f, "Media de 'sepal_width': %.2f\n", data.sepal_width/(float)n_flores);
        fprintf(f, "Media de 'petal_length': %.2f\n", data.petal_length/(float)n_flores);
        fprintf(f, "Media de 'petal_width': %.2f\n", data.petal_width/(float)n_flores);

        

        fprintf(f, "[MODA: X]");  // <---- FALTOU MODA


        fclose (f);
        
    }   
}

int main() {
    int N; // Quantidade de arquivos    
    scanf("%d", &N);

    treat_files(N);

    return 0;
}
