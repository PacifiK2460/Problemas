#include<iostream>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);

    int l[110],p,a;

    cin>>p>>a;

    for (int i = 0; i < p +5; i++)
    {
        l[i] = 0;
    }
    

    int o;

    for (int i = 1; i <= a; i++)
    {
        cin>>o;
        l[o] = l[o] + 1;
    }
    for (a = 1; a <= p; a++)
    {
        cout<<a<<"-"<<l[a]<<endl;
    }
}