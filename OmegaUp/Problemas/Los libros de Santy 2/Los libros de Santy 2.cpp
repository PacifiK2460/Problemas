#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100000
using namespace std;

unsigned long long mem[MAX];
vector <long> bks;
long minimo = 0,maximo, mid, temp2;
long b,q,temp;

long long pos = 0;

int search()
{
        temp2 = bks.at(mid);
        //cout<<"Buscado en: "<<minimo<<"("<<bks.at(minimo)<<") : "<<mid<<"("<<bks.at(mid)<<") : "<<maximo<<"("<<bks.at(maximo)<<")\n";

        if (temp2 > temp)
        {
            //cout<<"No at mid "<<temp2<<" > "<<temp;
            maximo = mid;
            mid = ((minimo + maximo) / 2);
            return search();
        }
        else if (temp2 < temp)
        {
            //cout<<"No at mid "<<temp2<<" < "<<temp;
            minimo = mid;
            mid = ((minimo + maximo) / 2);
            return search();
        }
        else
        {
            if (temp < MAX)
            {
                mem[temp] = mid-1;
                cout<< mem[temp]<<" ";
            }
            else
            {
                cout<<mid-1;
            }
            
        }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>b>>q;

    bks.push_back(0);

    for (long i = 0; i < b; i++)
    {
        cin>>temp;
        bks.push_back(temp);
    }

    sort(bks.begin(),bks.end());
    
    bks.push_back(0);

    maximo = bks.size() - 1;
    mid = ((minimo + maximo) / 2);

    for (long i = 0; i < q; i++)
    {
        cin>>temp;

        if (temp < MAX)
        {
            if (mem[temp] != 0)
            {
                cout<<mem[temp]<<" ";
            }
            else
            {
                search();
                minimo = 0;
                maximo = bks.size();
                mid = ((minimo + maximo) / 2);   
            }   
        }
        else
        {
            search();
            minimo = 0;
            maximo = bks.size();
            mid = ((minimo + maximo) / 2);
        }
    }
}