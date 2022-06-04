#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int f[50][50];

    for (int i = 0; i <= n-1; i++)
    {
        for (int j = 0; j <= m-1; j++)
        {
            cin>>f[i][j];
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j <= m-1; j++)
        {
            cout<<f[i][j]<<" ";
        }
        cout<<"\n";
    }
    

}