#include<iostream>
#include<utility>
using namespace std;

int main()
{
    int n;
    bool c[55],p[55],s[55],q[55],t[55];
    cin>>n;
    for (int i = 0; i <= n-1; i++)
    {
        cin>>c[i];
        p[i] = c[i];
        s[i] = c[i];
        q[i] = c[i];
        t[i] = c[i];
    }
    pair<int,int>m;
    m.first = 0;
    m.second = 0;

    pair<int,int>g;
    g.first = 0;
    g.second = 0;


    for (int i = 0; i <= n-1; i++)
    {
        if (p[i+1] == p[i])
        {
            p[i+1] = !p[i];
            g.first++;
        }        
    }
        for (int i = n-1; i >= 0; i--)
    {
        if (s[i+1] == s[i])
        {
            s[i+1] = !s[i];
            g.second++;
        }        
    }

    m.first = (g.first < g.second ? g.first : g.second);
    g.first = 0;
    g.second = 0;

    for (int i = 0; i <= n-1; i++)
    {
        if (q[i+1] == q[i])
        {
            q[i] = !q[i+1];
            g.first++;
        }        
    }
        for (int i = n-1; i >= 0; i--)
    {
        if (t[i+1] == t[i])
        {
            t[i] = !t[i+1];
            g.second++;
        }        
    }
    m.second = (g.first < g.second ? g.first : g.second);
    cout<<(m.first < m.second ? m.first : m.second);
    
}