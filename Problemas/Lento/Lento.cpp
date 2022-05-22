#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    vector <int> f;
    int g,d;

    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>g;
        f.push_back(g);
    }
    g = 0;
    d = 0;
    int h = 0;

   // cout<<"Se va a repetir por los "<<f.size()<<" numeros\n";
    for (int i = 0; i < f.size() / 2; i++)
    {
        //cin.get();
        g = f.at(i);
        //cout<<"Numero base = "<<f.at(i)<<" ("<<i<<")"<<endl;
        for (int j = i; j < (f.size() - i -1); j++)
        {
           // cin.get();
            //cout<<"     "<<j<<" | Se van a hacer "<<(f.size() - i - 2)<<" Tecnicas de sumas ("<<j<<")\n";
            for (int k = i+1; k < f.size() - d; k++)
            {
              //  cin.get();
              //  cout<<"         "<<k<<" | Esta tecnica abarcara "<<f.size() - d -1<<" sumas\n";//
                for (int l = k; l <= k + d; l++)
                {
                 //   cin.get();
                //   cout<<"              "<<l<<" | Sumando "<<f.at(l);
                    g += f.at(l);
                 //  cout<<", siendo un total de "<<g<<endl;
                }
                
                if (g % 2 == 1 && g >= h)
                {
                    h = g;
                }
                g = f.at(i);
            }
            d++;
        }
        d = 0;           
    }
    cout<<h;
}