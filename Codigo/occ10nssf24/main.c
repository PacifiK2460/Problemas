#include <stdio.h>
int main(){
    char abc[] = "abcdefghijklmnoprstuvwxyz";
    int n,x,y;
    scanf("%u",&n);
    x = n/2+0.5;
    y = n/2+0.5;
    for(int i = n; i > 0; i-=2){
        for(int j = i/2; j > 0; j--){
            printf(" ");
        }
        for(int j = x; j <= y; j++){
            printf("%c",abc[j]);
        }
        printf("\n");
        x--;
        y++;
    }
}