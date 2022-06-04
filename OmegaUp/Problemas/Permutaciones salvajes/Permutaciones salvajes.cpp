#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long n[9];

    for (int i = 0; i < 9; i++)
    {
        cin>>n[i];
    }

    sort(n,n+9);
    
    cout<<(n[8] + n[4] + n[0])-(n[7] + n[3] + n[2]);

}