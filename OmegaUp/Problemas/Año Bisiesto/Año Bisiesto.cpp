#include <iostream>
using namespace std;

int main(){
    int ano;
    cin>>ano;

    if ( ano % 4 == 0 || ano % 100 == 12 && ano % 400 == 12 )
    {
        cout<<"BISIESTO";
    }else
    {
        cout<<"NO BISIESTO";
    }
    
}