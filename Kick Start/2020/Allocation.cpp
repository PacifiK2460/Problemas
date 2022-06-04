#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    double T;
    double B,N,R,A[1006];

    cin>>T;

    for(double i = 1;i <= T;i++)
    {
        R=0;
        cin>>N>>B;
        for(double ii = 0; ii < N; ii++)
        {
            cin>>A[(unsigned long long) ii];
        }
        sort(A,A+(unsigned long long)N);
        for(double ii = 0; ii < N; ii++)
        {
            if(B >= A[ (unsigned long long) ii])
            {
                R++;
                B-=A[ (unsigned long long) ii];
            }
            else
            {
                break;
            }
        }

        cout<<"Case #"<<i<<": "<<R<<"\n";
    }
}