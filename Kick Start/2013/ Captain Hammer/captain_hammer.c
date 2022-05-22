#include <stdio.h>
#include <math.h>

#define ERR 28.64788976

long double MOD = 1.0;

int main(){
    int CANTIDAD = 0;
    scanf("%i", &CANTIDAD);
    for(int ACTUAL = 1; ACTUAL <= CANTIDAD; ACTUAL++){
        long double RESULT = 0;

        {
            double Velocity = 0, Distance = 0;
            scanf("%lf %lf", &Velocity, &Distance);

            if(Velocity == 1.0 && Distance == 1.0){
                RESULT = 9.8;
            } else {
                RESULT = (9.8 * Distance)/(Velocity*Velocity);
            }


            if( RESULT != 0 && RESULT != 1){
                RESULT = modfl(RESULT, &MOD);
            }

            RESULT = asinhl(RESULT) * ERR;
        }

        printf("Case #%i: %lf\n", ACTUAL, RESULT);
    }
}