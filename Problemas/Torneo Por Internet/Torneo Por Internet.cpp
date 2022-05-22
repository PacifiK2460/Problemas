    #include <iostream>

    using namespace std;

    int main()
    {
        long participante;
        cin>>participante;

        float distancia;
        char medida[2];

        float mayor = 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000;

        for( int i = 1; i<= participante; i++)
        {

            cin>>distancia>>medida[0];
            if (medida[0] != 'm')
            {
                cin>>medida[1];
            }
            
            

            if (distancia < 0)
            {
                distancia = distancia * -1;
            }
            

            if (medida[0] == 'i')
            {
                distancia = (distancia * 2.54) / 100;
            }
            else if (medida[0] == 'k')
            {
                distancia = distancia * 1000;
            }
            else if (medida[0] == 'y')
            {
                distancia = (distancia * 91.44) / 100;
            }
            else if (medida[0] == 'c')
            {
                distancia = (distancia / 100);
            }
            else
            {
                distancia = distancia;
            }


            if( distancia > mayor)
            {
                mayor = distancia;
            }


        }

        cout<<mayor;

    }