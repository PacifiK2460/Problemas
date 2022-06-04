#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    float a,s,d;
    cin>>a>>s>>d;

    float f = round(a / 4);
    f += round(s / 2);
    f += round(d * 3 / 4);

    cout<<(f);
}