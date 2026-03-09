#include <stdio.h>

int main(void){
    int total;
    int x, y, z;

    scanf("%d %d %d %d", &total,&x, &y, &z);

    float value_x = (x*total)/100.f;
    float value_y = (y*total)/100.f;
    float value_z = (z*total)/100.f;

    //as porcentagens retornaram inteiros
    if(value_x == (int)value_x && value_y == (int)value_y && value_z == (int)value_z){
        int soma = (int)value_x + (int)value_y + (int)value_z;
        printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", (int)value_x, (int)value_y, (int)value_z);
        
        //sobrou, e Rebeka conseguiu dinheiro
        if((total - soma) >= 4) printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
        //não sobrou
        else printf("E parece que Rebeka vai ter que voltar andando...\n");
        
    }
    else{ //não retornam inteiros. Rebeka vai adicionar
        total += 2;
        value_x = (x*total)/100.f;
        value_y = (y*total)/100.f;
        value_z = (z*total)/100.f;
        
        //ela pensa em somar 2 e resolveria o problema de divisão
        if(value_x == (int)value_x && value_y == (int)value_y && value_z == (int)value_z){
            int soma = (int)value_x + (int)value_y + (int)value_z;
            //sobra 3 ou mais pra ela
            if((total - soma) >= 3){
                char l1, l2, l3;
                scanf(" %c %c %c", &l1, &l2, &l3);
                printf("%d\n", l1%60 + l2%60 + l3%60);
                
                if((total - soma) >= 6) {//deu 2, tem 1, precisa de 7, ou seja, no mínimo 6
                    printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                }
                else{
                    printf("E parece que Rebeka vai ter que voltar andando...\n");
                }
            }
            else{ //não sobra
                total +=1;
            }
            
        }else{ //não resolveu, o jeito é somar 3
            total += 1;
        }

        if(total == 3){
            value_x = (x*total)/100.f;
            value_y = (y*total)/100.f;
            value_z = (z*total)/100.f;
            if(value_x == (int)value_x && value_y == (int)value_y && value_z == (int)value_z){//divisão se ajeita adicionando 3
                int soma = (int)value_x + (int)value_y + (int)value_z;
                if((total - soma) >= 4){ //ela adiciona por vale pra ela
                    int id1, id2, id3;
                    scanf("%d %d %d", &id1, &id2, &id3);
                    if(id1%3 == 0 || id2%3 == 0 || id3%3 == 0){
                        printf("%d\n", (id1/3)+(id2/3)+(id3/3));
                    }

                    if((total - soma) >= 7){//deu o total
                        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                    }else{ //ainda assim não deu o total
                        printf("E parece que Rebeka vai ter que voltar andando...\n");
                    }

                }
                else{ //ela não adiciona porque não vale
                    printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
                    printf("E parece que Rebeka vai ter que voltar andando...\n");
                }
            }
            else{ //nem assim a divisão se ajeitou
                printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
                printf("E parece que Rebeka vai ter que voltar andando...\n");
            }
        }


        

    }


    return 0;
}