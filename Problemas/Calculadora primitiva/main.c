#include <stdio.h>

int main(){
    unsigned short input, total = 0, ops;
    scanf("%hu", &input);

    while (input >= 2)
    {
        ops = 0;
        for(int i=0; i < 3; i++ ){
            //ops[i] = (unsigned short)((3 - i) % input);
            if(input%(3-i) == 0){
                if((3-i)%input == 0){
                    ops = 0;
                    break;
                } else if( ((3-i)%input) >= ops){
                    ops = (3-i)%input;
                }
            }
        }

        if(ops == 0){
            total++;
            break;
        } else if(ops == 1){
            input -= 1;
        } else {
            input /= ops;
        }

        total++;
    }

    printf("%hu", total);
}