#include<iostream>
#include<vector>
using namespace std;

vector <long> x;
vector <long> a;
vector <long> b;
bool paso = true;
bool paso2 = true;
int r;

int main()
{
    long n,m,h;
    cin>>n>>m;


    for (int i = 0; i < n; i++)
    {
        cin>>h;
        a.push_back(h);
    }
    for (int i = 0; i < m; i++)
    {
        cin>>h;
        b.push_back(h);
    }        

    x.reserve(a.size() + b.size());
    x.insert(x.end(), a.begin(),a.end());
    x.insert(x.end(), b.begin(),b.end());

    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            r = x.at(i) % a.at(j);
            if (r != 0)
            {
                paso = false;
                break;
            }
        }

        if (paso)
        {
            for (int j = 0; j < b.size(); j++)
            {
                r = b.at(j) % x.at(i);
                if (r != 0)
                {
                    paso2 = false;
                    break;
                }
            }

            if (paso2)
            {
                cout<<x.at(i)<<" ";
            }
        }
        paso = true;
        paso2 = true;
    }
}