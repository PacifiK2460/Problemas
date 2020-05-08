#include<iostream>
using namespace std;

int main()
{
    int n,c;
    cin>>n>>c;

    int t = 0, l;


    for (int i = 0; i < n; i++)
    {
        if (t < c)
        {
            cin>>l;
          //cout<<t<<" < "<<c<<endl;
          t += l;
          //cout<<"t += "<<t<<endl;
        }
        else if (t >= c)
        {
            //cout<<t<<" >= "<<c<<"Dia: "<<i<<endl;
            l = i;
            c = i;
            break;
        }
    }

    for (c; c < n; c++)
    {
        cin>>t;
    }
    

    cout<<l;
}