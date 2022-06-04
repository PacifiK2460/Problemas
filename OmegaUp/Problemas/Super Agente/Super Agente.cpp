#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int n = 0,m = 0,d = 0,df = 0;
vector< vector<char>> mapa(2000, vector<char> (2000));
//vector<vector<int> >mapa;

void comprboar(int x, int y)
{
    //cout<<"\n"<<x<<" , "<<y<<" = G\n";
    //arriba
    if (x != 0)
    {    
//        cout<<x<<" : "<<0<<"\n";
        for (int i = x - 1; i > 0-1; i--)
        {
            if (mapa[i][y] != '#' && mapa[i][y] != 'G')
            {
                d++;
  //             cout<<"+1\n";

            }
            else
            {
                //cout<<mapa[i][y]<<" "<<i<<"-"<<y<<" != ,\n";
                break;
            }
            
        }
        //cout<<"[!]"<<d<<" : "<<df<<"\n";
        if (d >= df)
        {
            df = d;
        }
        d = 0;
    }
    //abajo
    if (x != n-1)
    {   
        //cout<<x<<" : "<<n-1<<"\n";
        for (int i = x + 1; i < n; i++)
        {
            if (mapa[i][y] != '#' && mapa[i][y] != 'G')
            {
                d++;
          //      cout<<"+1\n";
            }
            else
            {
            //    cout<<mapa[i][y]<<" == #\n";
                break;
            }   
        }
       // cout<<"[!]"<<d<<" : "<<df<<"\n";
        if (d >= df)
        {
            df = d;
        }
        d = 0;
    }
    //izq
    if (y != 0)
    {   
        //cout<<y<<" : "<<0<<"\n";
        for (int i = y - 1; i > 0 - 1; i--)
        {
            if (mapa[x][i] != '#' && mapa[x][i] != 'G')
            {
                d++;
          //      cout<<"+1\n";
            }
            else
            {
            //    cout<<mapa[x][i]<<" == #\n";
                break;
            }   
        }
        //cout<<"[!]"<<d<<" : "<<df<<"\n";
        if (d >= df)
        {
            df = d;
        }
        d = 0;
    }
    //der
    if (y != m-1)
    {    
        //cout<<y<<" : "<<m-1<<"\n";
        for (int i = y + 1; i < m; i++)
        {
            if (mapa[x][i] != '#' && mapa[x][i] != 'G')
            {
                d++;
          //      cout<<"+1\n";
            }
            else
            {
            //    cout<<mapa[x][i]<<" == #\n";
                break;
            }   
        }
       // cout<<"[!]"<<d<<" : "<<df<<"\n";
        if (d >= df)
        {
            df = d;
        }
        d = 0;
    }
}

int main()
{
    cin>>n>>m;
    pair<vector<int>,vector<int>> pos;

    for (int i = 0; i <= n-1; i++)
    {
        for (int j = 0; j <= m-1; j++)
        {
            cin>>mapa[i][j];
            if (mapa[i][j] == 'G')
            {
                pos.first.push_back(i);
                pos.second.push_back(j);
            }
        }
    }

    
    for (int i = 0; i <= pos.first.size() - 1; i++)
    {   
        comprboar(pos.first[i],pos.second[i]);
    }

    cout<<df;
}