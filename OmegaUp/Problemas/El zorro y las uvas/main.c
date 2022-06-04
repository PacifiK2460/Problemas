#include <stdio.h>
int main(){
    int Nracimos, Nsaltos, temp;

    scanf("%d", &Nracimos);
    int altura_de_racimos[Nracimos];

    for(int i=0; i < Nracimos; i++){
        scanf("%d", altura_de_racimos[i]);
    }

    scanf("%d", &Nsaltos);
    int cache[Nsaltos][2];

    for(int salto=0; salto < Nsaltos; salto++){
        scanf("%d", &temp);
        for(int racimo = 0; racimo < Nracimos; racimo++){
            if( temp > altura_de_racimos[racimo] && altura_de_racimos[racimo] != -1){
                cache[salto][0] = temp;
                cache[salto][1] += altura_de_racimos[racimo];

                altura_de_racimos[racimo] = -1;
            }
        }
    }

}