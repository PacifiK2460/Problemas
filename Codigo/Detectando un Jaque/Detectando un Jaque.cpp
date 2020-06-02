#include<iostream>
#include<utility>
using namespace std;

char T[8][8];
int f[8][8];


void reina(int x,int y, int h)
{

    //arriba
    for (int i = y-1; i >= 0; i--)
    {        
        if (T[x][i] == '.')
        {
            f[x][i] = h;
        }
        else
        {
            f[x][i] = h;
            break;
        }    
    }
    //Abajo
    for (int i = y+1; i <= 0; i++)
    {        
        if (T[x][i] == '.')
        {
            f[x][i] = h;
        }
        else
        {
            f[x][i] = h;
            break;
            
        }    
    }
    //Izq
    for (int i = x-1; i >= 0; i--)
    {        
        if (T[i][y] == '.')
        {
            f[i][y] = h;
        }
        else
        {
            f[i][y] = h;
            break;
        }    
    }
    //Der
    for (int i = x+1; i <= 0; i++)
    {        
        if (T[i][y] == '.')
        {
            f[i][y] = h;
        }
        else
        {
            f[i][y] = h;
            break;
        }    
    }
    //Di_Sup_I
    for (int i = 1; i <= (x <= y ? x : y); i--)
    {
        if (T[x-i][y-i] == '.')
        {
            f[x-i][y-i] = h;
        }else
        {
            f[x-i][y-i] = h;
            break;
        }
    }
    //Di_Sup_D
    for (int i = 1; i <= (x >= y ? x : y); i++)
    {
        if (T[x-i][y+i] == '.')
        {
            f[x-i][y+i] = h;
        }else
        {
            f[x-i][y+i] = h;
            break;
        }
    }
    //Di_Inf_I
    for (int i = 1; i <= (x <= y ? x : y); i--)
    {
        if (T[x+i][y-i] == '.')
        {
            f[x+i][y-i] = h;
        }else
        {
            f[x+i][y-i] = h;
            break;
        }
    }
    //Di_Inf_D
        for (int i = 1; i <= (x >= y ? x : y); i++)
    {
        if (T[x+i][y+i] == '.')
        {
            f[x+i][y+i] = h;
        }else
        {
            f[x+i][y+i] = h;
            break;
        }
    }
}

void torre(int x,int y, int h)
{
    //arriba
    for (int i = y-1; i >= 0; i--)
    {        
        if (T[x][i] == '.')
        {
            f[x][i] = h;
        }
        else
        {
            f[x][i] = h;
            break;
        }    
    }
    //Abajo
    for (int i = y+1; i <= 0; i++)
    {        
        if (T[x][i] == '.')
        {
            f[x][i] = h;
        }
        else
        {
            f[x][i] = h;
            break;
        }    
    }
    //Izq
    for (int i = x-1; i >= 0; i--)
    {        
        if (T[i][y] == '.')
        {
            f[i][y] = h;
        }
        else
        {
            f[i][y] = h;
            break;
        }    
    }
    //Der
    for (int i = x+1; i <= 0; i++)
    {        
        if (T[i][y] == '.')
        {
            f[i][y] = h;
        }
        else
        {
            f[i][y] = h;
            break;
        }    
    }
}

void alfil(int x,int y, int h)
{
    //Di_Sup_I
    for (int i = 1; i <= (x <= y ? x : y); i--)
    {
        if (T[x-i][y-i] == '.')
        {
            f[x-i][y-i] = h;
        }else
        {
            f[x-i][y-i] = h;
            break;
        }
    }
    //Di_Sup_D
    for (int i = 1; i <= (x >= y ? x : y); i++)
    {
        if (T[x-i][y+i] == '.')
        {
            f[x-i][y+i] = h;
        }else
        {
            f[x -i ][y +i] = h;
            break;
        }
    }
    //Di_Inf_I
    for (int i = 1; i <= (x <= y ? x : y); i--)
    {
        if (T[x+i][y-i] == '.')
        {
            f[x+i][y-i] = h;
        }else
        {
            f[x+i][y-i] = h;
            break;
        }
    }
    //Di_Inf_D
    for (int i = 1; i <= (x >= y ? x : y); i++)
    {
        if (T[x+i][y+i] == '.')
        {
            f[x+i][y+i] = h;
        }else
        {
            f[x+i][y+i] = h;
            break;
        }
    }
}

void caballo(int x, int y, int h)
{
    f[x-2][y+1] = h;
    f[x-2][y-1] = h;

    f[x+2][y+1] = h;
    f[x+2][y-1] = h;

    f[x-1][y+2] = h;
    f[x+1][y+2] = h;

    f[x+1][y-2] = h;
    f[x-1][y-1] = h;
}

void peon(int x, int y, int h)
{
    f[(h == 1 ? x-1 : x+1)][y-1] = h;
    f[(h == 1 ? x-1 : x+1)][y+1] = h;
}

void rei(int x, int y, int h)
{
    f[x-1][y] = h;
    f[x-1][y-1] = h;
    f[x-1][y+1] = h;
    f[x][y-1] = h;
    f[x][y+1] = h;
    f[x+1][y] = h;
    f[x+1][y-1] = h;
    f[x+1][y+1] = h;
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

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            switch (T[i][j])
            {
                case 'e':
                    reina(i,j,1);
                    break;
                case 'r':
                    rei(i,j,1);
                    break;
                case 't':
                    torre(i,j,1);
                    break;
                case 'a':
                    alfil(i,j,1);
                    break;
                case 'c':
                    caballo(i,j,1);
                    break;
                case 'p':
                    peon(i,j,1);
                    break;
            }
        }
    }

    cout<<(f[R.first][R.second] == 1 ? 1 : 0)<<endl;

for (int i = 0; i < 8; i++)
{
    for (int j = 0; j < 8; j++)
    {
        f[i][j] = 0;
    }
}


    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            switch (T[i][j])
            {
                case 'E':
                    reina(i,j,2);
                    break;
                case 'R':
                    rei(i,j,2);
                    break;
                case 'T':
                    torre(i,j,2);
                    break;
                case 'A':
                    alfil(i,j,2);
                    break;
                case 'C':
                    caballo(i,j,2);
                    break;
                case 'P':
                    peon(i,j,2);
                    break;
            }
        }
    }

    cout<<(f[r.first][r.second] == 2 ? 1 : 0)<<endl;

}
