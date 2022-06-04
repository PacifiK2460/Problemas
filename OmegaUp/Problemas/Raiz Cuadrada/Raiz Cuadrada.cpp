#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    float n,d;
    cin>>n>>d;
    cout<< fixed << setprecision(d) << sqrt(n);
}