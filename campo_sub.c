#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int qtd_jogos, qtd_jogadas, coluna_jog, linha_jog, mquad;
    char matriz[1000][1000], mat_aux[1000][1000];
    char enter;
    int linha, coluna, i, True, over, flag;
    
    scanf("%d", &qtd_jogos);
    over = 1;
    while(over <= qtd_jogos){
        scanf("%d", &mquad);
        //printf("%d\n%d\n", qtd_jogos, mquad);
        // eliminar o enter
        enter = getchar(); 
        for(linha = 0; linha < mquad; linha++){
            //printf("Digite os numeros da linha %d:\n", linha);
            for(coluna = 0; coluna < mquad; coluna++){
                //usando scanf para retirar espacos das linhas
                scanf("%c", &matriz[linha][coluna]);
                enter = getchar();
            }
            //printf("\n");
        }   
        scanf("%d", &qtd_jogadas);
        True = 1;
        //verificando se existe bomba na posicao da jogada
        for(i = 0; i < qtd_jogadas; i++){
            scanf("%d%d", &linha_jog, &coluna_jog);
            if(matriz[linha_jog][coluna_jog] == 'b'){
                matriz[linha_jog][coluna_jog] = 'A';
                True = 0;
            }
                
            //O RESTO TA CERTO
            //AQUI COMECA A PARTE COMPLICADA
            //fazer uma condicao para cada borda
            else{
                //condicao para borda de cima
                // linha_jog != 0 &&
                if( 0 < coluna_jog < mquad - 1){
                    if(matriz[linha_jog - 1][coluna_jog] != 'b' &&
                    matriz[linha_jog + 1][coluna_jog] != 'b' &&
                    matriz[linha_jog][coluna_jog - 1] != 'b' &&
                    matriz[linha_jog][coluna_jog + 1] != 'b' &&
                    matriz[linha_jog -1][coluna_jog - 1] != 'b' &&
                    matriz[linha_jog + 1][coluna_jog - 1] != 'b' &&
                    matriz[linha_jog + 1][coluna_jog + 1] != 'b' &&
                    matriz[linha_jog - 1][coluna_jog + 1] != 'b'){
                        matriz[linha_jog][coluna_jog] = '0';
                        matriz[linha_jog - 1][coluna_jog] = '0';
                        matriz[linha_jog + 1][coluna_jog] = '0';
                        matriz[linha_jog][coluna_jog - 1] = '0';
                        matriz[linha_jog][coluna_jog + 1] = '0';
                        matriz[linha_jog - 1][coluna_jog - 1] = '0';
                        matriz[linha_jog + 1][coluna_jog - 1] = '0';
                        matriz[linha_jog + 1][coluna_jog + 1] = '0';
                        matriz[linha_jog - 1][coluna_jog + 1] = '0';
                    }else if(matriz[linha_jog][coluna_jog] != 'b'){
                        matriz[linha_jog][coluna_jog] = '0';
                    }

                }
            }
        }
        //loop para mostrar atualizacao do tabuleiro
        //printf("\n");
        //for(linha = 0; linha < mquad; linha++){
            //for(coluna = 0; coluna < mquad; coluna++)
                //printf("%c ", matriz[linha][coluna]);
            //printf("\n");
        //}
        //printf("\n");
        flag = 0;
        if(True != 0){
            for(linha = 0; linha < mquad; linha++){
                for(coluna = 0; coluna < mquad; coluna++)
                    if(matriz[linha][coluna] == 'x')
                        flag = 1;
            }
            if((True == 1) && (flag == 0))
                printf("GANHOU\n");
            else
                printf("FALTOU TERMINAR\n");
        }
        else
            printf("PERDEU\n");
        over++;
    }
    return 0;
}