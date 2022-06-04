#include<iostream>
#include<utility>
using  namespace std;


char tablero[3][3];

pair<int,int>mis_cords[9];
pair<int,int>bro_cords[9];
int apunta1;
int apunta2;

int comprobar(int i)
{   
    if (tablero[(mis_cords[i].first) - 1][(mis_cords[i].second) - 1] == 'x' && 'x' == tablero[(mis_cords[i].first) + 1][(mis_cords[i].second) + 1])
    {
        cout<<"GANO1";
    }
    else if (tablero[(mis_cords[i].first) - 1][(mis_cords[i].second) + 1] == 'x' && 'x' == tablero[(mis_cords[i].first) + 1][(mis_cords[i].second) - 1])
    {
        cout<<"GANO2";
    }
    else if (tablero[(mis_cords[i].first) - 1][(mis_cords[i].second)] == 'x' && 'x' == tablero[(mis_cords[i].first) + 1][(mis_cords[i].second)])
    {
        cout<<"GANO3";
    }
    else if (tablero[(mis_cords[i].first)][(mis_cords[i].second) - 1] == 'x' && 'x' == tablero[(mis_cords[i].first)][(mis_cords[i].second) + 1])
    {
        cout<<"GANO4";
    }
    
    
        
}

int main()
{

    ios_base::sync_with_stdio(false);

    apunta1 = 0;
    apunta2 = 0;

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            cin>>tablero[i][j];
            if (tablero[i][j] == 'x')
            {
                mis_cords[apunta1].first = i;
                mis_cords[apunta1].second = j;

                apunta1++;
            }else if (tablero[i][j] == 'o')
            {
                bro_cords[apunta2].first = i;
                bro_cords[apunta2].second = j;

                apunta2++;
            }
            
        }
    }

    for (int i = 0; i <= apunta1 - 1; i++)
    {
        comprobar(i);
    }

}