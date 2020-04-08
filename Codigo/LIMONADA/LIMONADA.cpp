#include<iostream>
using namespace std;

int main()
{
    unsigned long  d,t,p,c,l;

    cin>>d>>t>>p>>c>>l;

    if (((d-t)+ p*c) >= l)
    {
        cout<<"LIBRO";
    }
    else
    {
        cout<<"LIMONADA";
    }
    
    
}