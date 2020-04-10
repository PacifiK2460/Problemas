#include <iostream>
#include<vector>
using namespace std;

int main()
{
    long long n, k;
    cin>>n>>k;

    vector<float>esp;

    float g;
    float em;
    float em_t = 0;

    for (int i = 0; i <= n-1; i++)
    {
        cin>>g;
        esp.push_back(g);
    }

    float max = (n==k?0:n-k);
    
    for (int i = 0; i <= max; i++)
    {
        int j = i;
        float max1 = (k<=2?j:j+k-2);
        //cout<<"Sig ciclo = "<<i<<":"<<max1<<endl;
        em = 0;
        for (int j = i; j <= max1; j++)
        {
            if (k!=1)
            {
                if (esp[j] >= esp[j+1])
                {
                    //cout<<em<<" : ";
                    em = em - (esp[j]-esp[j+1]);
                    //cout<<esp[j]<<" >= "<<esp[j+1]<<" Emocion = "<<em<<endl;
                }else
                {
                    //cout<<em<<" : ";
                    em = em + (esp[j+1]-esp[j]);
                    //cout<<esp[j]<<" <= "<<esp[j+1]<<" Emocion = "<<em<<endl;
                }
            }
            else
            {
                em = esp[j];   
            }
            }
            
           
        /*if (k!=1)
        {
            em = esp[k - 1 + i] - esp[i];
        }
        else
        {
            em = esp[i];  
        }*/
           
        if (em > em_t)
        {
            em_t = em;
        }        
    }
    cout<<em_t;
}