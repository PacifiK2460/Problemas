#include<iostream>
using namespace std;

#define MAX 100

unsigned long long t,t2;
long long mem[MAX][MAX];

int MCD(int x, int y)
{
    return y ? MCD(y, x % y) : x;
}

int resolver(int a, int b)
{
    if (a == 0 or b == 0)
    {
        a = 0;
        b = 0;
        t2++;
    }
    else
    {
        if (a <= MAX or b <= MAX)
        {
            if (mem[(a >= b ? a : b)][(a >= b ? b : a)] == 0)
            {
                mem[(a >= b ? a : b)][(a >= b ? b : a)] = MCD(a,b);
            }

            int mcd = mem[(a >= b ? a : b)][(a >= b ? b : a)];

            t2++;
            a -= mcd;
            b -= mcd;
            resolver(a,b);
        }
        else
        {
            int mcd = MCD(a,b);
            t2++;
            a -= mcd;
            b -= mcd;
            resolver(a,b);
        }
    }

    return 1;

}

int main()
{
    long n,a,b;
    cin>>n>>t;

    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        resolver(a,b);
    }

    if (t2 <= t)
    {
        cout<<t2 - 1;
    }
    else
    {
        cout<<"El Agente A no sera heroe nacional, el Doctor B destruira su pais";
    }
}