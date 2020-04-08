#include<iostream>
using namespace std;

int main()
{
    int m,n,f[25][25];
    int k = 1;

    cin>>m>>n;
    f[0][0] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n-1; j++)
        {
            if (i % 2 != 0)
            {
                //cout<<"1"<<endl;
                if (j == 0)
                {
                    k = f[i-1][j] + 1;
                    
                }
                f[i][j] = k;
                k++;
            }
            else
            {
                //cout<<"2"<<endl;
                if (j == 0)
                {
                    k = k + n - 1;
                }
                f[i][j] = k;
                k--;
            }
            
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n-1; j++)
        {
            cout<<f[i][j]<<" ";
        }
        cout<<"\n";
    }
}