#include <stdio.h>
#include <stdlib.h>

int compareCards(char* CurrentCard, char* topCard);

int main(){
    int CANTIDAD = 0;
    scanf("%i", &CANTIDAD);
    for(int ACTUAL = 1; ACTUAL <= CANTIDAD; ACTUAL++){
        int result = 0;

        {
            int NumberOfCards = 0;
            scanf("%i", &NumberOfCards);

            getchar();

            char *topCard = (char*)calloc(105, 1);
            fgets(topCard, 102, stdin);

            for(int currentCardIndex = 1; currentCardIndex < NumberOfCards; currentCardIndex++){
                char *currentCard = (char*)calloc(105, 1);
                fgets(currentCard, 102, stdin);

                if( compareCards(currentCard, topCard) ){
                    result++;
                    free(currentCard);        
                } else {
                    free(topCard);
                    topCard = currentCard;
                }
            }

            free(topCard);
        }

        printf("Case #%i: %i\n", ACTUAL, result);
    }
}

int compareCards(char* CurrentCard, char* topCard){
    while(1){
        if((*CurrentCard == '\n' || *topCard == '\n') || *CurrentCard > *topCard){
            return 0;
        } else if (*CurrentCard == *topCard){
            CurrentCard++;
            topCard++;
        } else if (*CurrentCard < *topCard){
            return 1;
        }
    }
}