#include<iostream>
#include<vector>
#include<iomanip>
#include<utility>
#define DEF 2.000000000
#define MIN 0.000000000
#define RES 1.000000
#define TIME (minimo + maximo) / 2
using namespace std;

unsigned int cantidad;
float posicion, velocidad;
float minimo = MIN;
float maximo = DEF;

vector < pair <int, int> > Pos;
vector < pair <int, int> > Neg;

int calcular()
{
   // cout<<"Tiempo: "<<minimo<<" + "<<maximo<<" / 2 = "<<((minimo + maximo)/2)<<"\n";
    for (unsigned i = 0; i < Pos.size(); i++)
    {  
        for (unsigned j = 0; j < Neg.size(); j++)
        {

            if ((Pos[i].first + (Pos[i].second * TIME)) == (Neg[j].first + (Neg[j].second * TIME)))
            {
                cout<< fixed << setprecision(10) <<(minimo + maximo) / 2;
                return 0;   
            }
            else if ((Pos[i].first + (Pos[i].second * TIME)) < (Neg[j].first + (Neg[j].second * TIME)))
            {
                maximo = (minimo + maximo) / 2;
                calcular();
            }
        }   
    }

    minimo = (minimo + maximo) / 2;
    calcular();
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>cantidad;

    for (unsigned i = 0; i < cantidad; i++)
    {
        cin>>posicion>>velocidad;

        velocidad < 0 ?  Neg.push_back(make_pair(posicion,velocidad)) : Pos.push_back(make_pair(posicion,velocidad));
    }
   
    if (Neg.empty() || Pos.empty())
    {
        cout<<"-1";
    }
    else
    {
        calcular();
    }
}