#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n[3];
    for(int i = 0;i<=2;i++)
    {
        cin>>n[i];
    }

    sort(n,n+3);

    if(((n[0]*n[0]) + (n[1]*n[1])) == (n[2]*n[2]))
    {
        for (int i = 2; i >= 0; i--)
        {
            cout<<n[i]<<" ";
        }
    }
    else{
        cout<<"imposible";
    }
}