#include<iostream>
using namespace std;

int main()
{
    int m,x[100][100];
    cin>>m;

    for (int i = 0; i <= m-1; i++)
    {
        for (int j = 0; j <= m-1; j++)
        {
            cin>>x[i][j];
        }
        
    }

    //diagonal: ir por cada i==j; comprobando cada uno
    //diagonal superior~inferior
    bool diagonal = false;
    int yes = 0;
    for (int i = 1; i <= m-1; i++)
    {
        if (x[i-1][i-1] == x[i][i])
        {
            yes++;
        }
        
    }
    if (yes == m-1)
    {
        diagonal == true;
        cout<<"SI";
    }
    else
    {
        yes = 0;
        
        for (int i = m-1; i >= 1; i--)
        {
            if (x[i+1][i+1] == x[i][i])
            {
                yes++;
            }    
        }
        if (yes == m-1)
        {
            diagonal == true;
            cout<<"SI";
        }
        else
        {
            cout<<"NO";
        }
        
        
    }
    
}