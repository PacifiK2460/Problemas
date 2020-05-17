#include<iostream>
#include<utility>
using namespace std;

char T[8][8];
int f[8][8];

void reina(int x,int y)
{
    //arriba
    for (int i = y-1; i >= 0; i--)
    {        
        if (T[x][i] == '.')
        {
            f[x][i] == 1;
        }
        else
        {
            break;
        }    
    }
    //Abajo
    for (int i = y+1; i <= 0; i++)
    {        
        if (T[x][i] == '.')
        {
            f[x][i] == 1;
        }
        else
        {
            break;
        }    
    }
    //Izq
    for (int i = x-1; i >= 0; i--)
    {        
        if (T[i][y] == '.')
        {
            f[i][y] == 1;
        }
        else
        {
            break;
        }    
    }
    //Der
    for (int i = x+1; i <= 0; i++)
    {        
        if (T[i][y] == '.')
        {
            f[i][y] == 1;
        }
        else
        {
            break;
        }    
    }
    //Di_Sup_I
    for (int i = 1; i <= (x <= y ? x : y); i--)
    {
        if (T[x-i][y-i] == '.')
        {
            f[x-i][y-i] = 1;
        }else
        {
            break;
        }
    }
    //Di_Sup_D
    for (int i = 1; i <= (x >= y ? x : y); i++)
    {
        if (T[x+i][y-i] == '.')
        {
            f[x+i][y-i] = 1;
        }else
        {
            break;
        }
    }
    //Di_Inf_I
    for (int i = 1; i <= (x <= y ? x : y); i--)
    {
        if (T[x-i][y+i] == '.')
        {
            f[x-i][y+i] = 1;
        }else
        {
            break;
        }
    }
    //Di_Inf_D
        for (int i = 1; i <= (x >= y ? x : y); i++)
    {
        if (T[x+i][y+i] == '.')
        {
            f[x+i][y+i] = 1;
        }else
        {
            break;
        }
    }
}

void torre(int x,int y)
{
    //arriba
    for (int i = y-1; i >= 0; i--)
    {        
        if (T[x][i] == '.')
        {
            f[x][i] == 1;
        }
        else
        {
            break;
        }    
    }
    //Abajo
    for (int i = y+1; i <= 0; i++)
    {        
        if (T[x][i] == '.')
        {
            f[x][i] == 1;
        }
        else
        {
            break;
        }    
    }
    //Izq
    for (int i = x-1; i >= 0; i--)
    {        
        if (T[i][y] == '.')
        {
            f[i][y] == 1;
        }
        else
        {
            break;
        }    
    }
    //Der
    for (int i = x+1; i <= 0; i++)
    {        
        if (T[i][y] == '.')
        {
            f[i][y] == 1;
        }
        else
        {
            break;
        }    
    }
}

int main()
{
    pair <int,int>R,r;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin>>T[i][j];
            if (T[i][j] == 'E')
            {
                R.first = i;
                R.second = j;
            }
            else if (T[i][j] == 'e')
            {
                r.first = i;
                r.second = j;
            }
        }
    }

    for (int i = 0; i < 8; i++)b
    {
        for (int j = 0; j < 8; j++)
        {
            switch (T[i][j])
            {
                case 'a' or 'A':
                    reina(i,j);
                    break;

                case 't' or 'T':
                    torre(i,j);
                    break;
                case ''
            }
        }
     }
}