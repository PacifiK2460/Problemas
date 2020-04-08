#include<iostream>
#include<utility>
using namespace std;

int main()
{
    int n;
    bool c[55],p[55],s[55];
    cin>>n;
    for (int i = 0; i <= n-1; i++)
    {
        cin>>c[i];
        p[i] = c[i];
        s[i] = c[i];
    }
    pair<int,int>m;
    m.first = 0;
    m.second = 0;

    for (int i = 0; i <= n-1; i++)
    {
        if (p[i+1] == p[i])
        {
            p[i+1] = !p[i];
            m.first++;
        }        
    }

    for (int i = 0; i <= n-1; i++)
    {
        if (s[i+1] == s[i])
        {
            s[i] = !s[i+1];
            m.second++;
        }        
    }
    cout<<(m.first < m.second ? m.first : m.second);
    
}