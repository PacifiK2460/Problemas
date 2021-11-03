#include <stdio.h>

unsigned long n,m,t,i,j,c;
unsigned long nx[100000];

void fscan(unsigned long* number);

int main(){
    fscan(&n);
    for(i = 0; i<n;i++){
        fscan(&nx[0] + i);
    }

    fscan(&m);
    for(i = 0;i<m;i++){
        fscan(&t);
        for(j = 0;j<n;j++){
            if(t >= nx[j]){
                c++;
            }
        }
        printf("%u ",c);
        c = 0;
    }
}

void fscan(unsigned long* number){
    //Obtenemos la direccion de la variable
    //Creamos una variable temporal;
    register int c;
    /*
        Asignamos 0 a la variable a leer, esto para
        prevenir que esta este iniciada con otro valor
    */
    *number = 0;
    //Leemos el primer caracteer
    c = getchar();
    /*
        Mientras que lo que estemos leeyendo
        sea un numero, continuamos
    */
    for(; (c>47 && c<58); c=getchar())
        // Vamos incrementando la variable conforme a lo leido
        *number = *number * 10 + c - 48;
}