#include <stdio.h>
#include <stdlib.h>

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
#define BOB 0
#define ALEX 1
#define TEMPLATE 2

int main(){
    int CANTIDAD = 0;
    scanf("%i", &CANTIDAD);
    for(int ACTUAL = 1; ACTUAL <= CANTIDAD; ACTUAL++){

        {
            int Numbers;
            scanf(" %i", &Numbers);

            int Data[3][Numbers];
            for(int i = 0; i < Numbers; i++){
                Data[0][i] = -1001;
                Data[1][i] = -1001;
                Data[2][i] = -1001;
            }
            int Actual[2] = {0};
            
            for(int NumeroActual = 0; NumeroActual < Numbers; NumeroActual++){
                int Number;
                scanf(" %i", &Number);
                

                int Owner = Number%2;

                Data[TEMPLATE][NumeroActual] = Owner;
                Data[abs(Owner)][ Actual[abs(Owner)] ] = Number;

                Actual[abs(Owner)]++;
            }
            
            qsort(Data[ALEX], Numbers, sizeof(int), comp);
            qsort(Data[BOB], Numbers, sizeof(int), comp);

            Actual[ALEX] = Numbers - Actual[ALEX];
            Actual[BOB] = Numbers - 1;

            printf("Case #%i: ", ACTUAL);

            for(int NumeroActual = 0; NumeroActual < Numbers; NumeroActual++){
                int index;
                int Owner = Data[TEMPLATE][NumeroActual];

                if(abs(Owner) == ALEX){
                    index = Actual[abs(Owner)]++;
                } else {
                    index = Actual[abs(Owner)]--;
                }

                printf("%i ", Data[abs(Owner)][index]);
            }
            printf("\n");
        }

    }
}