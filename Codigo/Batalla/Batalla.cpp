#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,h;
    cin>>n;
    vector <int> m,l;

    for (int i = 0; i < n; i++)
    {
        cin>>h;
        m.push_back(h);
    }
    for (int i = 0; i < n; i++)
    {
        cin>>h;
        l.push_back(h);
    }

    sort(m.begin(),m.end());
    sort(l.begin(),l.end());

    h = 0;
}