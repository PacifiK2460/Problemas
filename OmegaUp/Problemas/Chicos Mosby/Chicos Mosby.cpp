#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n,m,t = 0,area,g = 0;
    cin>>n>>m;    

    do
    {
        if (n <= m)
        {
            g = n;
            n = m;
            m = g;
        }
        if (m%2 == 0)
        {
            
        }
        
        area = n*m - m*m;
        n -=  m;
        t++;
    } while ((n != 0));
    cout<<t;
}