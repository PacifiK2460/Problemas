#include<iostream>
using namespace std;

int alumnos[1000000];
int alumnos2[1000000];
int n,q;
int t;//temporaal
char tmp;

void M(int n)
{
    
    switch (n)
    {
    case 1:
        alumnos2[n-1] = alumnos[0]

        for (int i = 0; i < n; i++)
        {
            alumnos2[i-1] = alumnos[i];
        }
        
        break;
    
    default:
        alumnos2[0] = alumnos[n-1];

        for (int i = 1; i < n; i++)
        {
            alumnos2[i] = alumnos[i-1];
        }
        
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>alumnos[i];
    }

    cin>>q;

    for (int i = 0; i < q; i++)
    {
        cin>>tmp>>t;

        switch (tmp)
        {
        case 'M':
                M(t);
            break;
        case 'Q':
            break;
        case 'L':

            break;
        }
    }   
}