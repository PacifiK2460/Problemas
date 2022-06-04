#include<iostream>
using namespace std;

int l = 0;

int cb(int n, int k)
{
    l++;
    if (k == 0 || n == 0|| n == k)
    {
        return 1;
    }
    else
    {
        return (cb(n-1,k) + cb(n-1,k-1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;
    cout<<cb(n,k)<<" "<<l;
}