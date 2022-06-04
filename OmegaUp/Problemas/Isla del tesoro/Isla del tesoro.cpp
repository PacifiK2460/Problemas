#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n=0;
    string movs;

    getline(cin,movs);

    for (int i = 0; i <= movs.length(); i++)
    {
        if(movs[i] == 'd')
        {
            n++;
        }
    }

    cout<< n;
    
}