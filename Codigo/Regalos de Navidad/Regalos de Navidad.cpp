#include <iostream>
using namespace std;

int main()
{   
    int amigos;
    float dinero,libro;
    cin>>amigos>>dinero>>libro;

    int c = dinero / amigos;
    c = c * amigos;
    dinero = dinero - c;
    if (dinero >= libro)
    {
        cout<<"SI";
    }
    else
    {
        cout<<libro - dinero;
    }
}