#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string txt;
    int comas[101];
    int puntos[101];
    int espacios[101];
    for (int i = 0; i <= 100; i++)
    {
        comas[i] = -1;
        puntos[i] = -1;
        espacios[i] = -1;
    }
    getline(cin,txt);
    int a=0,s=0,d=0;
    for (int i = 0; i < txt.size(); i++)
    {
        if (txt[i] == ' ')
        {
            espacios[a] = i;
            a++;
        }
        else if (txt[i] == '.')
        {
            puntos[s] = i;
            s++;
        }
        else if (txt[i] == ',')
        {
            comas[d] = i;
            d++;
        }
    }
    int t = a+s+d;
    a=0,s=0,d=0;
    sort(txt.begin(),txt.end());
    for (int i = (t==0?0:t); i < txt.size(); i++)
    {
        if (txt[i] != ' ' or txt[i] != '.' or txt[i] != ',')
        {
            if (espacios[a] != -1 && espacios[a] + t == i)
            {
                cout<<" ";
                a++;
                t--;
                i--;
            }
            else if (comas[s] != -1 && comas[s] + t == i)
            {
                cout<<",";
                s++;
                t--;
                i--;
            }
            else if (puntos[d] != -1 && puntos[d] + t == i)
            {
                cout<<".";
                d++;
                t--;
                i--;
            }
            else
            {            
                cout<<txt[i];
            }
        }           
    }
}