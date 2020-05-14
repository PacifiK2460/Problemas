#include<iostream>
#include<string>
using namespace std;

int sumar(string a, int b, int l, int t)
{
    if (b != l)
    {
        t += a.at(b)-48;
        sumar(a,b+1,l,t);
    }
    else
    {
        cout<<t;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    string n;
    getline(cin,n);
    sumar(n,0,n.size(),0);
}