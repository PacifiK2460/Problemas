#include <stdio.h>
#include <math.h>
#define MAX 38

int main(){
    int mem[MAX][MAX][MAX][MAX] = {0};
    int* slot;
    unsigned long int cantidad;
    char tecla;

    scanf("%ul",&cantidad);
    for(int i = 0; i < cantidad; i++){
        slot = &(mem[0][0][0][0]);
        for(int j = 0, k = 3; j < 4; j++, k--){
            tecla = getchar();
            if(tecla == '@'){
                k++;
                continue;;
            }

            if(tecla >= 'a' && tecla <= 'z') tecla -= 39;
            tecla -= 48;

            if(k != 0) slot += (unsigned long int)pow((double)MAX,(double)k) * tecla;
            else slot += tecla;
        }
        *slot += 1;
    }


    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            for(int k = 0; k < MAX; k++){
                for(int l = 0; l < MAX; l++){
                    if(mem[i][j][k][l] != 0) printf("%c%c@%c%c %i", 
                        i + 48, j + 48, k + 48, l + 48, mem[i][j][k][l]
                    );
                }
            }
        }
    }

    // int mem[5][5][5][5];
    // int *p = &(mem[0][0][0][0]);

    // mem[2][4][3][1] = 3;
    // printf("%p | %i\n",&(mem[0][0][0][0]),0);
    // printf("%p | %i\n",&(mem[2][4][3][1]),mem[2][4][3][1]);
    
    // p += 5*5*5*2;
    // p += 5*5*4;
    // p += 5*3;
    // p += 1;

    // printf("%p | %i\n",p,*p);
    // printf("Diff: %i",&(mem[2][4][3][1])-p);
}