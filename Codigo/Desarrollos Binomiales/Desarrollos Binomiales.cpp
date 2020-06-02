#include<iostream>
using namespace std;

long long int mem[60][60];

long long int pascal(int i, int j)
{
    if (j == 1 || j == i)
    {
        return 1;
    }

    if (mem[i][j] != 0)
    {
        return mem[i][j];
    }
    
    mem[i][j] = (pascal(i-1,j-1) + pascal(i-1,j));

    return mem[i][j];
}

int main()
{
    long long int n,j = 0;
    cin>>n;
    long long int m = n;

    if (n > 1)
    {    

        for (long long int i = 1; i < n+1; i++)
        {
            if (pascal(n+1,i) >= 2)
            {
                cout<<pascal(n+1,i);
            }
            
            if (m != 0)
            {
                cout<<"x";
                if (m != 1)
                {
                    cout<<"^"<<m;
                }
                
            }

            if (j != 0)
            {
                cout<<"y";
                if (j > 1)
                {
                    cout<<"^"<<j;
                }
            }

            if (m != 0)
            {
                cout<<"+";
            }
            j++;
            m--;
        }

        cout<<"b^"<<n;

    }
    else
    {
        cout<<"x+y";
    }
    

}