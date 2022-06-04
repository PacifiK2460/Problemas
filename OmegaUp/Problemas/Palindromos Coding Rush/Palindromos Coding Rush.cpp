#include<iostream>
#include<string>
using namespace std;

int subcadenas;
int limit;
int ActualLimit;

bool polindromo;

string copia;

string GirarPalabra(string palabra)
{   
    //cout<<"             La palabra paso de: "<<palabra;
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

void EsPolindromo(string palabra)
{
    polindromo = true;

    int j = palabra.length() - 1;
    for (int i = 0; i <=  (palabra.length() - 1) / 2; i++)
    {
        if (palabra[i] == palabra[j])
        {
            //cout<<"         [verdadero]: "<<palabra[i]<<" == "<<palabra[j]<<endl;
            j--;
        }
        else
        {
            //cout<<"         [falso]: "<<palabra[i]<<" != "<<palabra[j]<<endl;
            polindromo = false;
            break;
        }
    }
    if (polindromo == false && ActualLimit <= limit)
    {
        //cout<<"         Se esta griando la palabra: "<<palabra<<endl;
        palabra = GirarPalabra(palabra);
        EsPolindromo(palabra);
    }
}

int Subcadenas(string palabra,int rango)
{
    //cout<<"     La palabra a analizar: "<<palabra<<" | Rango de letras: "<<rango<<endl;
    while (rango <= palabra.length() - 1)
    {
        //cout<<"     "<<rango<<endl;
        for (int i = 0; i <= palabra.length() - rango; i ++)
        {
            //cout<<"     El rango a usar va a ser: "<<i<<":"<<i + rango<<endl;

            limit = palabra.substr(i,rango).length() - 1;
            ActualLimit = 0;
            polindromo = true;
            EsPolindromo(palabra.substr(i,rango));

            if(polindromo == true)
            {
                //cout<<"     "<<palabra.substr(i,rango)<<" es polindromo\n";
                subcadenas++;
            }
            else
            {
                //cout<<"     "<<palabra.substr(i,rango)<<" no es polindromo\n";
            }
            
        }
        rango++;
    }
   cout<<subcadenas; 
}

int main()
{
    ios_base::sync_with_stdio(false);

    string palabra;
    cin>>palabra;

    subcadenas = palabra.length();
    EsPolindromo(palabra);
    if (polindromo == true)
    {
        subcadenas = subcadenas + 1;
    }
    
    Subcadenas(palabra,2);
}