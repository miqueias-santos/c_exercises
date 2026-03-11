#include <stdio.h>

int main(void){
    int total, acum;
    int x, y, z;

    scanf("%d %d %d %d", &total,&x, &y, &z);
    acum = total;
    float value_x = (x*total)/100.f;
    float value_y = (y*total)/100.f;
    float value_z = (z*total)/100.f;

    //as porcentagens retornaram inteiros
    if(value_x == (int)value_x && value_y == (int)value_y && value_z == (int)value_z){
        printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", (int)value_x, (int)value_y, (int)value_z);
        int soma = (int)value_x + (int)value_y + (int)value_z;
                
        //sobrou, e Rebeka conseguiu dinheiro
        if((total - soma) >= 4) printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
        //não sobrou
        else printf("E parece que Rebeka vai ter que voltar andando...\n");
        
    }


    else{ //não retornam inteiros. Rebeka vai adicionar
        total += 1; //vai investir até resolver o problema e sobrar
        acum = total;
        value_x = (x*total)/100.f;
        value_y = (y*total)/100.f;
        value_z = (z*total)/100.f;
        //ela pensa em somar 1 e resolveria o problema de divisão
        
        if(value_x == (int)value_x && value_y == (int)value_y && value_z == (int)value_z){
            printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", (int)value_x, (int)value_y, (int)value_z); //print mesmo sem investir
            int soma = (int)value_x + (int)value_y + (int)value_z;

            //sobra 2 ou mais pra ela
            if((total - soma) >= 2){ //investe
                
                if((total - soma) >= 5) {//deu 1, tem 2, precisa de 5
                    printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                }
                else{
                    printf("E parece que Rebeka vai ter que voltar andando...\n");
                }
            }
            else total +=1; //não investe 1
            
        }
        else total += 1; //não resolveu, o jeito é somar 2
        
        if(total - acum == 1){
            acum = total;
            value_x = (x*total)/100.f;
            value_y = (y*total)/100.f;
            value_z = (z*total)/100.f;

            if(value_x == (int)value_x && value_y == (int)value_y && value_z == (int)value_z){
                printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", (int)value_x, (int)value_y, (int)value_z);
                int soma = (int)value_x + (int)value_y + (int)value_z;

                //sobra 3 ou mais pra ela
                if((total - soma) >= 3){ //investe
                    
                    unsigned char l1, l2, l3;
                    scanf(" %c %c %c", &l1, &l2, &l3);
                    printf("%d\n", l1%96 + l2%96 + l3%96);
                    
                    if((total - soma) >= 6) {//deu 2, tem 1, precisa de 7, ou seja, no mínimo 6
                        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                    }
                    else{
                        printf("E parece que Rebeka vai ter que voltar andando...\n");
                    }
                }
                else total +=1; //não investe 2
            }
            else total +=1; //não resolve
        }

        if(total - acum == 1){
            //acum = total; não precisa
            value_x = (x*total)/100.f;
            value_y = (y*total)/100.f;
            value_z = (z*total)/100.f;
            if(value_x == (int)value_x && value_y == (int)value_y && value_z == (int)value_z){//divisão se ajeita adicionando 3
                printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", (int)value_x, (int)value_y, (int)value_z);

                int soma = (int)value_x + (int)value_y + (int)value_z;
                if((total - soma) >= 4){ //ela adiciona por vale pra ela
                    int id1, id2, id3, s;
                    scanf("%d %d %d", &id1, &id2, &id3);
                    if(id1%3 == 0) s +=(id1/3);
                    if(id2%3 == 0) s +=(id2/3);
                    if(id3%3 == 0) s +=(id3/3);
                    printf("%d\n", s);

                    if((total - soma) >= 7){//deu o total
                        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                    }else{ //ainda assim não deu o total
                        printf("E parece que Rebeka vai ter que voltar andando...\n");
                    }

                }
                else{ //ela não adiciona porque não vale
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