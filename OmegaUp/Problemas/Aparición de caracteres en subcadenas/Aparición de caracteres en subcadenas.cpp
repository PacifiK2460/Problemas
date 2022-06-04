#include<iostream>
#include<string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string palabra,copia;
    int n,k,t;

    getline(cin,palabra);
    cin>>n;

    char letra;

    for (int i = 0; i <= n-1; i++)
    {
        cin>>letra;
        cin>>k>>t;

        copia = palabra.substr(k,t);
        size_t encontrado = copia.find(letra);
        cout<<(encontrado != string::npos ? "1\n":"0\n");
    }
    
        
}