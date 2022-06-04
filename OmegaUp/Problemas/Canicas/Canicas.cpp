#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long vasos[1000000];
    long v,c,t;
    cin>>v>>c;

    for (int i = 0; i < c; i++)
    {
        cin>>t;
        vasos[t-1] += 1;
    }

    for (int i = 0; i < v; i++)
    {
        cout<<vasos[i]<<"\n";
    }
}