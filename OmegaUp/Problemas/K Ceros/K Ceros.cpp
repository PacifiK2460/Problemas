#include<iostream>
using namespace std;
#define MAX 100000
unsigned long long mem[MAX];

unsigned long long Ceros(unsigned long long n, unsigned long long ceros,unsigned long long final)
{
    if (n % ceros == 0)
    {
        final++;
        return Ceros(n,ceros*10,final);
    }
    else
    {
        return final;
    }
}

unsigned long long f(unsigned long long n)
{   
    if (mem[n] != 0)
    {
        return 0;
    }
    else
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return f(n-1)*n;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long i = 1;

    while (true)
    {
        cout<<i<<" : "<<f(i)<<" ~ "<<Ceros(f(i),10,0)<<endl;
        i++;
    }
    

}