#include<iostream>
using namespace std;

char graf[10][20];

int main()
{
    srand(time(0));
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= rand() % 20 + 1; j++)
        {
            graf[i][j] = '*';
        }
    }

    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j <= 19; j++)
        {
            if (graf[j][i]!='*')
            {
                cout<<" ";
            }
            else{
            cout<<graf[j][i]<<"";
            }
        }
        cout<<"\n";
        
    }
      
}