#include<iostream>
using namespace std;

int b(int n)
{
    if (n >= 2)
    {
        b(n/2);
        cout<<n%2<<" ";
    }
    else
    {
        cout<<n<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    b(n);
}