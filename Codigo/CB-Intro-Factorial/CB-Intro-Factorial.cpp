#include<iostream>
using namespace std;
int fract(unsigned long long int n,unsigned long long int m)
{    
    if (m != 1)
    {
        return fract(m*n,m-1);
    }
    else
    {
        cout<< m*n;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if (n <= 1)
    {
        cout<<1;
    }
    else
    {
        fract(n,n-1);
    }
}