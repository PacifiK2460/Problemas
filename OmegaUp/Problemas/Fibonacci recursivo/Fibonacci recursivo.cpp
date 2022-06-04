#include<iostream>
using namespace std;

unsigned long long int l = 0;

int F(unsigned long long int n)
{
    l++;
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return (F(n-1) + F(n-2));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    cout<<F(n)<<" "<<l;
}