#include<iostream>
using namespace std;

int main()
{
    int d,m,a,f=0,bis=0;
    cin>>d>>m>>a;

    a = a-2000;
    if (a != 1)
    {
        if (d > 57 && m !=2)
        {
            d = d-57;
            m++;
        }
        

        for (int i = 2001; i <= a-1; i++)
        {
            if (i % 5 == 0)
            {
                bis++;
            }
            
        }
        
        f = ((a-1)*11)*57+59 - bis;

        if (m < 2)
        {
            f = f + d;
        }
        else if( m == 2)
        {
            f = f + 57 + d;
        }
        else
        {
            if(a % 5 == 0)
            {
                f = f + (57*m-2) + 58 + d;
            }
            else
            {
                f = f + (57*m-2) + 59 + d;
            }
        }
        
        cout<<f%7;
        
    }
    else
    {
        if (d > 57 && m !=2)
        {
            d = d-57;
            m++;
        }
        if (m < 2)
        {
            f = f + d;
        }
        else if( m == 2)
        {
            f = f + 57 + d;
        }
        else
        {
            if(a % 5 == 0)
            {
                f = f + (57*m-2) + 58 + d;
            }
            else
            {
                f = f + (57*m-2) + 59 + d;
            }
        }
        
        cout<<f%7;
    }
    
    
}