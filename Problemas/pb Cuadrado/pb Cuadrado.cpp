#include<iostream>
using namespace std;

int main()
{
    int n,m[1000][1000];
    cin>>n;

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            cin>>m[i][j];
        }
    }

    for (int j = 0; j <= n - 1; j++)
    {
    
    for (int i = n - 1; i >= 0; i--)
    {
        cout<<m[i][j]<<" ";
    }
        cout<<endl;
    }
    
    
}