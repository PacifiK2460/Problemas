#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bool primo = true;
    for (int i = n-1; i >= 2; i--)
    {
        if(n % i == 0){
            primo = false;
        }
    }

    if(primo == true)
    {
        cout<<"PRIMO";
    }
    else
    {
        cout<<"COMPUESTO";
    }
}