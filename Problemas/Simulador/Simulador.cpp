#include<iostream>
using namespace std;

    int registro[10];

int main()
{
    char instrucciones[3];
    int q,s=0;
    cin>>q;

    char h;

    int d;
    int a;

    int g;

    for (int i = 0; i <= q-1; i++)
    {
        cin>>instrucciones[0]>>instrucciones[1]>>instrucciones[2];

        switch (instrucciones[0])
        {
        case '0':
            switch (instrucciones[1])
            {
            case '0':
                s++;
                g = i;
                i = q;
                goto terminar;
                break;
            case '1':
                s++;
                registro[instrucciones[2]] -= 1;
                break;
            case '2':
                //s++;
                //d = registro[instrucciones[2]];
                break;
            }
            break;
        case '1':
            s++;
            cout<<"     "<<registro[instrucciones[1]]<<" = "<<instrucciones[2]<<"\n";
            registro[instrucciones[1]] = instrucciones[2];
            break;
        case '2':
            s++;
            cout<<"     "<<registro[instrucciones[1]]<<" + "<<instrucciones[2]<<" = ";
            registro[instrucciones[1]] += instrucciones[2];
            cout<<registro[instrucciones[1]]<<"\n";
            break;
        case '3':
            s++;
            cout<<"     "<<registro[instrucciones[1]]<<" * "<<instrucciones[2]<<" = ";
            registro[instrucciones[1]] *= registro[instrucciones[2]];
             cout<<registro[instrucciones[1]]<<"\n";
            break;
        case '4':
            s++;
            registro[instrucciones[1]] = registro[instrucciones[2]];
            break;
        case '5':
            s++;
            registro[instrucciones[1]] += registro[instrucciones[2]];
            break;
        case '6':
            s++;
            h = registro[instrucciones[1]];
            registro[instrucciones[1]] = registro[instrucciones[2]];
            registro[instrucciones[2]] = h;
            break;
        case '9':
            s++;
            if (registro[instrucciones[2]] != 0)
            {
                d = registro[instrucciones[1]];
            }
            break;
        }
    }
    terminar: for (g; g < q-1; g++)
    {
        //cin>>instrucciones[0]>>instrucciones[1]>>instrucciones[2];
        cout<<"Terminado!\n";
    }
    
    cout<<s<<"\n";
    for (int i = 0; i < 9; i++)
    {
        cout<<registro[i]<<"\n";
    }
    

}

        //case '7':
            //s++;
            //registro[instrucciones[1]] = registro[instrucciones[2]];
            //break;
        //case '8':
            //s++;
            //break;