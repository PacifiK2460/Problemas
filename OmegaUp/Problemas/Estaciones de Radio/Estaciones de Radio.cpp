#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n,x1 = 1000,x2;
    bool f; //0adelante 1atras
    cin>>n;
    if (540 <= n && n <= 1520)
    {
        int r[] = {580,980,1190,1250,1420};
        for (int i = 0; i <= 4; i++)
        {
            if (n >= r[i])
            {
                x2 = n - r[i];
                if (x2 <= x1)
                {
                    x1 = x2;
                    f = 1;
                }
            }
            else
            {
                x2 = r[i] - n;
                if (x2<=x1)
                {
                    x1=x2;
                    f=0;
                }
            }            
        }
        cout<<(f == 1 ? "atras ":"adelante ") << x1;
    }
    else
    {
        cout<<"error";
    } 
}