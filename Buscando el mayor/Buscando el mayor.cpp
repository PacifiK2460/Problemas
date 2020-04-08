#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int m,n[500],f[500];
    cin>>m;

    for (int i = 0; i <= m-1; i++)
    {
        cin>>n[i];
        f[i] = n[i];
    }
    
    sort(f,f+m);

    int i_primero = 0,i_segundo = 0;

    for (int i = 0; i <= m-1; i++)
    {
        if(n[i] == f[0])
        {
            i_primero = i;
        }
        if(n[i] == f[m-1])
        {
            i_segundo  = i;
        }
    }

    n[i_segundo] = n[0];
    n[0] = f[m-1]; 

    n[i_primero] = n[m-1];
    n[m-1] = f[0];
    
    for (int i = 0; i <= m-1; i++)
    {
        cout<<n[i]<<"\n";
    }
    
    
}