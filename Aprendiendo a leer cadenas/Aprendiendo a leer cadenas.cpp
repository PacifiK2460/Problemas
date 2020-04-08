#include<iostream>
#include<string>
using namespace std;

int main()
{
    string linea;
    getline(cin,linea);
    string reves(linea.rbegin(),linea.rend());     
    cout<<reves;
}