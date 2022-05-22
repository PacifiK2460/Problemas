#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int cuarto[102][102];
    for (int i = 0; i <= 101; i++)
    {
        for (int j = 0; j <= 101; j++)
        {
            cuarto[i][j] = 0;
        }
        
    }

    int p=0;
    int a,l,n;
    cin>>a>>l>>n;

    for (int i = 0; i <= a-1; i++)
    {
        for (int j = 0; j <= l-1; j++)
        {
            cuarto[i][j] = 1;
        }
        
    }

    int cord1,cord2;
    for (int i = 1; i <= n; i++)
    {
        cin>>cord1>>cord2;
        cuarto[cord1 - 1][cord2 - 1] = 2;
    }

    for (int i = 0; i <= a - 1; i++)
    {
        for (int j = 0; j <= l - 1; j++)
        {
            if(cuarto[i][j] == 1 && cuarto[i][j+1] == 1 && cuarto[i+1][j] == 1 && cuarto[i+1][j+1] == 1)
            {
                p++;
            }
        }
        
    }
    

    cout<<p;
}