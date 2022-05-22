#include<iostream>
using namespace std;

int MCD(int x, int y)
{
    return (y ? MCD(y, x % y) : x);
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<MCD(n,m);
}