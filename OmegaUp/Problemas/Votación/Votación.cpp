#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int candidatos[50][50],c,v,d,d1 = 0,h = 0;
bool t = false;


int main()
{
    ios_base::sync_with_stdio(false);
    
    cin>>c>>v;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>d;
            candidatos[j][d-1] += 1; 
        }
    }

    for (int i = 0; i < c; i++)
    {
        if (t == false)
        {
        
            for (int j = 0; j < c; j++)
            {
                if(candidatos[j][i] >= c / 2 and candidatos[j][i] > d1)
                {
                    //cout<<candidatos[j][i]<<" > "<<c/2<<" y "<<candidatos[j][i]<<" > "<<d1<<endl;
                   // cout<<"y";
                    d1 = candidatos[j][i];
                    h = j+1;
                    t = true;
                }
            }
            if (t)
            {
                cout<<h;
                break;
            }
            
        }
        else
        {
            break;
        }
        
        
    }

    if (t == false)
    {
        cout<<0;
    }
}