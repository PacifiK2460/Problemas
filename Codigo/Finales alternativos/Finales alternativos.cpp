#include<iostream>
using namespace std;

int main()
{
    int n;
    int mias = 0,hermano = 0;
    for (int i = 1; i <= 64; i++)
    {
        cin>>n;

        if(n == 1)
        {
            mias++;
        }
        else if(n == 2)
        {
            hermano++;
        }
    }
    if (hermano > mias)
    {
        cout<<"PERDI";
    }
    else if (mias > hermano)
    {
        cout<<"GANE";
    }
    else if (mias == hermano)
    {
        cout<<"EMPATE";
    }
    
    
    
}