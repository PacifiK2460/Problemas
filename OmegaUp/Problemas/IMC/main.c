/*
Martinez Lara Santiago de la cruz
177685
*/
#include <stdio.h>

void fscan(float* number); // Maquetación, fast-scan

int main(){
    float peso,altura,imc;
    fscan(&peso);
    fscan(&altura);
    imc = ( peso / (altura*altura) );

    if (imc <= 18.4){
        printf("Bajo de peso\n");
    }
    else if(imc >= 18.5 && imc <=24.9){
        printf("Normal\n");
    }
    else if(imc >= 25 && imc <= 29.9){
        printf("Sobrepeso\n");
    }
    else{
        printf("Obesidad\n");
    }

}

void fscan(float* number){
    //Obtenemos la direccion de la variable
    //Creamos una variable temporal;
    register int c;
    unsigned long long d = 1;
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
    if(c == 46){ //Decimal
        c = getchar();
        for(; (c>47 && c<58);c=getchar()){
            d *= 10;
            *number = *number  + (( (float)c - 48)/d);
        }
    }
}