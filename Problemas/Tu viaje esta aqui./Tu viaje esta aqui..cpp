#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector <string> q;

int ovni(string s, string d)
{
    unsigned long long t1=1,t2=1;
    cin>>s;
    cin>>d;

    for (unsigned long long i = 0; i < s.size(); i++)
    {
        t1 *= (int(s.at(i)) - 64);
    }

    for (unsigned long long i = 0; i < d.size(); i++)
    {
        t2 *= (int(d.at(i)) - 64);
    }

    if ((t1 % 47) == (t2 % 47))
    {
        q.push_back("GO");
        return 1;
    }
    else
    {
        q.push_back("STAY");
        return 1;
    }
}

int main()
{
    string s,d;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        ovni(s,d);
    }

    for (int i = 0; i < q.size(); i++)
    {
        cout<<q.at(i)<<endl;
    }
}