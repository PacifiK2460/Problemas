#include<iostream>
#include<math.h>
using namespace std;

char r[21];

int b(int n, int i)
{
    if (n >= 2)
    {
        r[i] = (n%2 == 1 ? 'X' : 'A');
        b(n/2, i--);
    }
    else
    {
        r[i] = (n == 1 ? 'X' : 'A');
    }
}


int bin(int n, int i, int f)
{
    if (n <= f)
    {
        b(n,n);
    }
}

int main()
{
    int n;
    cin>>n;
    bin(0,0,pow(2,n));
}