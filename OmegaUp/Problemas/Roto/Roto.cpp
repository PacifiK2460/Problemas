#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string txt;

    getline(cin,txt);

    vector <string> inicio;
    vector <string> fin;
    vector <string> medio;

    long long g;

    for (long long i = 0; i < txt.size(); i++)
    {
        //cout<<"analizando: "<<txt[i]<<endl;
        if (txt[i] == '[')
        {
            //cout<<txt[i]<<" ("<<i<<") {Inicio}\n";
            g = i+1;
            for (i; i < txt.size(); i++)
            {
                if (txt[i+1] == ']' or txt[i+1] == '[' or i == txt.size()-1)
                {
                    //cout<<"A usar de: "<<g<<" ~ "<<i;
                    if (txt.size() - i != 1)
                    {
                        //cout<<"Agregando1: "<<txt.substr(g,(i-g) +1)<<endl;
                        inicio.push_back(txt.substr(g,(i-g) +1));
                    }
                    else if(txt.size() - i == 1)
                    {//cout<<"Agregando2: "<<txt.substr(g,(txt.size()-g))<<endl;
                        inicio.push_back(txt.substr(g,(txt.size()-g)));
                    }                    
                    //cout<<" | "<<inicio.top()<<endl;
                    break;
                }
            }
        }
        else if (txt[i] == ']')
        {
            //cout<<txt[i]<<" ("<<i<<") {Fin}\n";
            g = i+1;
            for (i; i < txt.size(); i++)
            {
                if (txt[i+1] == ']' or txt[i+1] == '[' or i == txt.size()-1)
                {
                    //cout<<"A usar de: "<<g<<" ~ "<<i;
                    if (txt.size() - i != 1)
                    {
                        //cout<<"Adding1: "<<txt.substr(g,(i-g) +1)<<endl;
                        fin.push_back(txt.substr(g,(i-g) +1));
                    }
                    else if(txt.size() - i == 1)
                    {
                        //cout<<"Adding2: "<<txt.substr(g,(txt.size()-g))<<endl; 
                        fin.push_back(txt.substr(g,(txt.size()-g)));
                    }  
                    //cout<<" | "<<fin.back()<<endl;
                    break;
                }
            }
        }
        else
        {
            //cout<<txt[i]<<" ("<<i<<") {Fin}\n";
            g = i;
            for (i; i < txt.size(); i++)
            {
                if (txt[i+1] == ']' or txt[i+1] == '[' or i == txt.size()-1)
                {
                    //cout<<"A usar de: "<<g<<" ~ "<<i;
                    if (txt.size() - i != 1)
                    {
                        medio.push_back(txt.substr(g,(i-g) +1));
                    }
                    else if(txt.size() - i == 1)
                    {
                        medio.push_back(txt.substr(g,(txt.size()-g)));
                    }  
                    //cout<<" | "<<fin.back()<<endl;
                    break;
                }
            }
        }
        
    }

    if (!inicio.empty())
    {
        for (long long i = inicio.size()-1; i >= 0; i--)
        {
            cout<<inicio.at(i);
        }

    }
    if (!medio.empty())
    {    

        for (long long i = 0; i < medio.size(); i++)
        {
            cout<<medio.at(i);
        }
    
    }
    if (!fin.empty())
    {    

        for (long long i = 0; i < fin.size(); i++)
        {
            cout<<fin.at(i);
        }
    
    }
}