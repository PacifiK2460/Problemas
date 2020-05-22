#include<iostream>
#include<algorithm>
using namespace std;

int m[50],l[50],p;

void Girar(int count)
{
    p = m[count-1];
    for (int i = count - 1; i >= 1; i--)
    {
        m[i] = m[i-1];
    }
    m[0] = p;
}

int main()
{
    int n,h,f=0;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>m[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>l[i];
    }

    sort(m,m+n);
    sort(l,l+n);

    h = 0;

    for (int j= 0; j < n; j++)
    {
    
        for (int i = 0; i < n; i++)
        {
            if (m[i] > l[i])
            {
                h += m[i];
            }
        }
        if (h>=f)
        {
            f = h;
        }
        h = 0;
        Girar(n);
    }
cout<<f;
}