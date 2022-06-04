#include<iostream>
using namespace std;

unsigned long long int mem[100000];

unsigned long long int f(unsigned long long int n)
{
    if (mem[n] != 0)
    {
        return mem[n];
    }
    else
    {
        if (n < 4)
        {
            mem[n] = 10;
            return mem[n];
        }
        else if (n >= 4)
        {
            mem[n] = f(n-2) + f(n-4) + 30;
            return mem[n];
        }      
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    unsigned long long int  n;
    cin>>n;
    cout<<f(n);
}