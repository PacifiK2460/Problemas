/*
Martinez Lara Santiago de la cruz
177685
*/
#include <stdio.h>
int main(){
    long long total,tpm;
    register int c;
    c = getchar();
    for(tpm = 0; c != EOF; c=getchar()){
        if(c>47 && c<58)
            tpm = tpm * 10 + c - 48;
        else{
            total+=tpm;z
            if(c == 10){
                printf("%u\n",total);
                total = 0;
            }
            tpm = 0;
        }
    }
}