#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

stack<string> inicio;
stack<string> fin;

void PrintStackInicio()
{
    if (inicio.empty())
    {
        return;
    }

    string x = inicio.top();
    inicio.pop();
    PrintStackInicio();
    cout<<x;
    inicio.push(x);
}
void PrintStackFin()
{
    if (fin.empty())
    {
        return;
    }

    string x = fin.top();
    fin.pop();
    PrintStackFin();
    cout<<x;
    fin.push(x);
}

int main()
{
    string texto;

    size_t l[3];
    string e = " ";

    cout<<"0\n";
    getline(cin,texto);
    cout<<"Loop 0:"<<texto.length()<<"\n";
    for (int i = 0; i < texto.length(); i++)
    {
        cout<<i<<endl;
        cin.get();
        if (texto[i] == '[' && (texto[i+1] != '[' && texto[i+1] != ']'))
        {
            cout<<texto[i]<<"Cumple con: 2\n";
            //l = ( <= texto.find('[',i+1) ? texto.find(']',i+1) : texto.find('[',i+1));   
            l[0] = texto.find(']',i+1);
            l[1] = texto.find('[',i+1);
            l[2] = texto.find(']',i+1);

            sort(l[0],l[2]);

            cout<<" l(i) = "<<l<<endl;
            inicio.push(texto.substr(i+1,l[0] - i));
            inicio.push(e);
            i = l[0];
        }else if(texto[i] == ']' && (texto[i+1] != '[' && texto[i+1] != ']'))
        {
            cout<<texto[i]<<"Cumple con: 3\n";
            //l = (texto.find(']',i+1) <= texto.find('[',i+1) ? texto.find(']',i+1) : texto.find('[',i+1));
            l[0] = texto.find(']',i+1);
            l[1] = texto.find('[',i+1);
            l[2] = texto.find(']',i+1);
            
            sort(l[0],l[2]);

            cout<<" l(i) = "<<l<<endl;
            fin.push(texto.substr(i+1,l[0] - 1));
            fin.push(e);
            i = l[0];
        }
        else
        {
            cout<<texto[i]<<" No cumple ninguna condicion\n";
        }
    }
}