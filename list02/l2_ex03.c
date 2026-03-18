    #include <stdio.h>
    
    int main(void){
        int q;
        char* TELA;
        int passos;
        char dir;
        //scanf("%d", &q);
        int correcao;
        int col = 0;
        for (int i = 0; i < q; i++){
            
            //scanf("%d %c", &passos, &dir);
            passos += correcao;
            if(dir == 'E') col -= correcao;
            correcao = 0;

            if(dir == 'E'){
                if(i != 0) TELA = "\n";//printf("\n");
                col -= passos;
                for(int k = 0; k < col; k++){
                    //printf(" ");
                    TELA = " ";
                }
                for(int k = 0; k < passos+1; k++){ //PASSOS+1? SEMPRE?
                    //printf(".");
                    TELA = ".";
                }
                // if(i != q - 1) TELA = "\n"; //printf("\n"); 

            }
            else if(dir == 'D'){
                if(i != 0) TELA = "\n"; //printf("\n");  //a instrução chama a quebra de linha
                for(int k = 0; k < col; k++){
                    //printf(" ");
                    TELA = " ";
                }
                for(int k = 0; k < passos; k++) TELA = "."; // printf("."); 
                //if(i != q - 1) TELA = "\n"; //printf("\n");

            }
        
            else if(dir == 'B'){
                if(i != 0 && passos > 1) TELA = "\n"; //printf("\n"); 

                if(i == q - 1){ //ultima instrução. ENTRAR AQUI
                    for(int k = 0; k < passos; k++){
                        for(int j = 0; j < col; j++){
                            //printf(" ");
                            TELA = " ";
                        }
                        //printf(".");
                        TELA = ".";
                        if(k != passos - 1) TELA = "\n"; //printf("\n");
                    }
                }
                else{
                    
                    for(int k = 0; k < passos - 1; k++){
                        for(int j = 0; j < col; j++){
                            //printf(" ");
                            TELA = " ";
                        }
                        //printf(".");
                        TELA = ".";
                        
                        if(k != passos - 2) TELA = "\n";
                        
                        //printf("\n");
                        
                    }
                    correcao = (passos - 1 == 0) ? 1 : 0;
                    

                }

            }
                //j++;

    
            switch(dir){
                case 'D':
                    col+= (passos-1); 
                    break;
               /* case 'E':
                    col-= (passos-1); 
                    break; */
            }

        }

        return 0;
    }