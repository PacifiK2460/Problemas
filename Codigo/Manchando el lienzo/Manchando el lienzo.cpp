#include <iostream>
#include<utility>
using namespace std;

int main()
{
    int tam,colores;
    cin>>tam>>colores;

    int lienzo[55][55];

    for(int i=0;i<=tam-1;i++){
        for(int g=0;g<=tam-1;g++){
            lienzo[i][g] = 0;
        }
    }
    
    int x,y,color;


    for (int i = 0; i <= colores-1; i++)
    {
        cin>>x>>y>>color;
        pair<int,int>cords[5];
        cords[0].first = x;
        cords[0].second = y;

        cords[1].first = x+1;
        cords[1].second = y;
        
        cords[2].first = x-1;
        cords[2].second = y;
        
        cords[3].first = x;
        cords[3].second = y+1;
        
        cords[4].first = x;
        cords[4].second = y-1;

        for (int i = 0; i <= 4; i++)
        {
            if (0 <= cords[i].first <= tam-1 && 0 <= cords[i].second <= tam-1)
            {
                lienzo[cords[i].first][cords[i].second] = color;
            }
            
        }
        
        
    }
    
    for (int i = 0; i <= tam-1; i++)
    {
        for (int g = 0; g <= tam-1; g++)
        {
            cout<<lienzo[g][i]<<" ";
        }
        cout<<"\n";
    }
    

}