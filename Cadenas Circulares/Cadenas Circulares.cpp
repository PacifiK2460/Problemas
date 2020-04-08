#include<iostream>
#include<string>

using namespace std;

int limit;
int ActualLimit = 0;

string copia;

//Funciones

string GirarPalabra(string palabra)
{   
    //cout<<"La palabra paso de: "<<palabra;
    copia = palabra;
    for (int i = 1; i <= palabra.length() - 1; i++)
    {
        palabra[i - 1] = copia[i];
    }
    palabra[palabra.length() - 1] = copia[0];

    ActualLimit = ActualLimit + 1;
    //cout<<" a "<<palabra<<endl;
    return palabra;
}

bool EsPolindromo(string palabra)
{
    bool polindromo = true;

    int j = palabra.length() - 1;
    for (int i = 0; i <=  (palabra.length() - 1) / 2; i++)
    {
        if (palabra[i] == palabra[j])
        {
            //cout<<"[verdadero]: "<<palabra[i]<<" == "<<palabra[j]<<endl;
            j = j - 1;
        }
        else
        {
            //cout<<"[falso]: "<<palabra[i]<<" != "<<palabra[j]<<endl;
            polindromo = false;
            break;
        }
    }

    if (polindromo == true)
    {
        //cout<<"[Final]: Todo salio bien\n";
        cout<<"Circular";
    }
    else if (polindromo == false && ActualLimit == limit )
    {
        //cout<<"[Final]: No es polindromo y ya se giro toda la palabra\n";
        cout<<"No Circular";
    }
    else if (polindromo == false && ActualLimit <= limit)
    {
        palabra = GirarPalabra(palabra);
        EsPolindromo(palabra);
    }
}

int main()
{
    string palabra;
    cin>>palabra;

    limit = palabra.length() - 1;
    //cout<<"Limite: "<<limit<<endl;

    EsPolindromo(palabra);   
}