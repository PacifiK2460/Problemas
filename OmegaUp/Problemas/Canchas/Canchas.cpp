#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int cords[8];
    int limit = 0;
    int min = 100000;

    for (int i = 0; i <= 7; i++)
    {
        cin>>cords[i];
        if (limit <= cords[i])
        {
            limit = cords[i];
        }
        if (min >= cords[i])
        {
            min = cords[i];
        }
        
    }
    ///

    int l;
    for (int i = 0; i <= 1; i++)
    {
        if (cords[i]>=cords[i+2])
        {
            l = cords[i];
            cords[i] = cords[i+2];
            cords[i+2] = l;
        }
    }
    
    for(int i = 4; i <= 5; i++)
    {
        if(cords[i] >= cords[i+2])
        {
            l = cords[i];
            cords[i] = cords[i+2];
            cords[i+2] = l;
        }
    }
    

    vector<vector<bool> > patio( 10000 , vector<bool> (10000, 0));
    
    
    for (int i = cords[1]; i <= cords[3]-1; i++)
    {
        for (int j = cords[0]; j <= cords[2]-1; j++)
        {
            patio[i][j] = 1;
        }
    }
    for (int i = cords[5]; i <= cords[7]-1; i++)
    {
        for (int j = cords[4]; j <= cords[6]-1; j++)
        {
            patio[i][j] = 1;
        }
    }
    
    int t=0;

    for (int i = min; i <= limit; i++)
    {
        for (int j = min; j <= limit; j++)
        {
            if (patio[i][j] == 1)
            {
                t++;
            }
            
        }
        
    }
    

    
    
    /*
    for (int i = 0; i <= limit+1; i++)
    {
        for (int j = 0; j <= limit; j++)
        {
            cout<<patio[i][j];
        }
        cout<<"\n";
    } 
    */
    cout<<t;
}