#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector< vector<int>> mapa(n, vector<int> (n));
    char input;

    for (int i = 0; i <= n-1; i++)
    {
        for (int j = 0; j <= m-1; j++)
        {
            cin>>mapa[i][j];
        }
        
    }

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++){ 
            cout<< mapa[i][j]<< " "; 
        } 
        cout<<"\n"; 
    } 

}