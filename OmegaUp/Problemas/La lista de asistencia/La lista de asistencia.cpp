#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
    int alumnos,dias;
    cin>>alumnos>>dias;

    pair<int,int>lista[105];
    int falta;

    for (int i = 0; i <= alumnos -1; i++)
    {
        lista[i].second = i;
    }
    

    for (int i = 0; i <= dias-1; i++)
    {
        for (int j = 0; j <= alumnos -1; j++)
        {
            cin>>falta;
            lista[j].first += falta;
        }
        
    }

    for (int j = 0; j <= alumnos -1; j++)
    {
        lista[j].first = 4 - lista[j].first;
    }

    sort(lista,lista+alumnos);

    //al alumno final sumarle 1
    for (int i = 0; i <= alumnos -1 ; i++)
    {
        if (lista[0].first == lista[i].first)
        {
            cout<<lista[i].second + 1<<" ";
        }   
    }
}