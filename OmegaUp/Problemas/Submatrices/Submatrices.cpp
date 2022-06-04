#include<iostream>
using namespace std;

int c1[1000][1000];
int c2[1000][1000];
bool f[1000][1000];

void commprobar(int x, int y, int count1, int count2)
{
    bool final = true;
    int k = 0,l = 0;
    for (int i = x; i < count1 + x; i++)
    {
        if (final)
        {
            for (int j = y; j < count2 + y; j++)
            {
                if (c1[i][j] != c2[k][l])
                {
                   // cout<<c1[i][j]<<" != "<<c2[k][l]<<endl; 
                    final = 0;
                    break;
                }
                /*else if (c1[i][j] == c2[k][l])
                {
                   // cout<<c1[i][j] <<" == "<<c2[k][l]<<endl;
                }*/
                l++;
            }
        }
        else
        {
            break;
        }
        
        k++;
        l = 0;
    }

    if (final == 1)
    {
        //cout<<"Manchando de: "<<x<<" ~ "<<count1 +x -1<<" | "<<y<<" ~ "<<count2 + y-1<<endl;
        for (int i = x; i < count1 + x; i++)
        {
            for (int j = y; j < count2 + y; j++)
            {   
                f[i][j] = true;
            }
        }
    }
}
/*
5 5
2 1 0 8 2
4 2 1 8 2
6 4 2 5 3
4 2 3 9 0
0 0 0 0 0
2 2
2 1
4 2
*/

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>c1[i][j];
        }
    }
    int d,g;
    cin>>d>>g;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < g; j++)
        {
            cin>>c2[i][j];
        }
    }
    

    for (int q = 0; q <= (n-d); q++)
    {
        for (int a = 0; a <= (m-g); a++)
        {
            if (c1[q][a] == c2[0][0])
            {
                //cout<<"1: ("<<q<<","<<a<<")"<<endl;
                commprobar(q,a,d,g);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
}