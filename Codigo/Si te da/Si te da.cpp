#include<iostream>
using namespace std;

int problema(int a, int  b, int d, int i1, int i2)
{
    int c = (a + b) % 10;

    cout<<" "<<c;

    if (b == i1 and c == i2)
    {
        cout<<"\n"<<d;
        return 0;
    }
    else
    {
        problema(b,c,d+1,i1,i2);
        return 0;
    } 
}

int main()
{
    int a,b,c=0;
    cin>>a>>b;
    cout<<a<<" "<<b;
    problema(a,b,1,a,b);
}