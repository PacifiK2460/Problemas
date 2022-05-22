#include<iostream>
using namespace std;

int main()
{
    long n;
    cin>>n;

    long long f = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i < 10) 
        {
            f++;
        }
        else if (i >= 10 and i < 100)
        {
            f += 2;
        }
        else if (i >= 100 and i < 1000)
        {
            f += 3;
        }
        else if (i >= 1000 and i < 10000)
        {
            f += 4;
        }
        else if (i >= 10000 and i < 100000)
        {
            f += 5;
        }
        else if (i >= 100000 and i < 1000000)
        {
            f += 6;
        }
        else if (i >= 1000000 and i < 10000000)
        {
            f += 7;
        }
        else if (i >= 10000000 and i < 100000000)
        {
            f += 8;
        }
        else if (i >= 100000000 and i < 1000000000)
        {
            f += 9;
        }
        else if (i > 10000000000)
        {
            f += 10;
        }
    }

    cout<<f;

}