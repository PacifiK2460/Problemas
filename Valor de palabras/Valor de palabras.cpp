#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n,iterador;
    string palabra;
    cin>>n;
    //char abc[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    bool abc[26];
    for (int i = 0; i <= 25; i++)
    {
        abc[i] = false;
    }
    bool completo = true;

    //

    for (int i = 0; i <= n-1; i++)
    {
        cin>>palabra;
        for (int i = 0; i <= palabra.length(); i++)
        {
            iterador = int(palabra[i]) - 97;
            abc[iterador] = true;
        }
        for (int i = 0; i <= 25; i++)
        {
            if (abc[i] == false)
            {
                completo = false;
            }
        }
        if(completo == false)
        {
            cout<<"NO WAY\n";
        }        
        else
        {
            cout<<"PERFECT\n";
        }
            completo = true;
            for (int i = 0; i <= 25; i++)
            {
                abc[i] = false;
            }
        
    }
    
}