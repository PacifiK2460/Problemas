#include<iostream>
using namespace std;
#define MAX 1073741824

int mem[MAX];

int base(int x)
{
    if (mem[x] != 0)
    {
        return mem[x];
    }
    else
    {
        if (x == 0)
        {
            return 1;
        }
        else
        {
            mem[x] += base(x/2);
            return mem[x];    
        }

    }
    return 0;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    for (int  i = 0; i < MAX; i++)
    {
        mem[i] = 1;
    }
    

    int n;
    cin>>n;

    cout<<base(n);
}