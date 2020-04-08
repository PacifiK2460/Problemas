#include <iostream>    
using namespace std;

int main()
{   

    long numeros[50];

    int n,f=0,s=1,sig,c;
    cin>>n;
    n = n + 1;
    for (c = 1; c < n; c++)
    {
        if (c <= 1)
        {
            sig = c;
        }
        else
        {
            sig = f + s;
            f = s;
            s = sig;
        }
        numeros[c] = sig;
    }

    int i,j;

    for ( i = 4; i < n; i++)
    {
        for ( j = 4; j < n; j++)
        {
            if (i != numeros[j])
            {
                cout<<i<<" ";
                j =n;
            }
            
        }
        j=4;
    }

}