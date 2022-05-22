#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n[3];

    for (int i = 0; i <= 2; i++)
    {
        cin>>n[i];
    }

    sort(n,n+3);

    for (int i = 0; i <= 2; i++)
    {
        cout<<n[i]<<" ";
    }
    

}