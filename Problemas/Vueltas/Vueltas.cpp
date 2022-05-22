// E. L-OMI2010-Vueltas
#include <iostream>
#define max 1000
using namespace std;

int main()
{
	long long m, n;
	cin >> m >> n;
		
	//Hacer dinamica!
	long long lista[max][max];
	long long listaF[max][max];
	long long listaFF[max][max];

	for (long long i = 0; i <= m - 1; i++)
	{
		for (long long j = 0; j <= n - 1; j++)
		{
			cin >> lista[i][j];
		}
	}

	long long vueltas;
	cin >> vueltas;

	char aplicar;
	long long v = 0;
	long long h = 0;

	for (long long i = 1; i <= vueltas; i++)
	{
		cin >> aplicar;

		if (aplicar == 'V')
		{
			v++;
		}
		else
		{
			h++;
		}

	}

	v = v % 2;
	h = h % 2;

	long long if2 = 0;
	long long if3 = 0;

	if (h == 0 && v == 0)
	{
		for (long long i = 0; i <= m - 1; i++)
		{
			for (long long j = 0; j <= n - 1; j++)
			{
				cout << lista[i][j] << " ";
			}
			cout << "\n";
		}
	}
	if (h == 1 && v == 1)
	{
		for (long long i = m - 1; i >= 0; i--)//V
		{
			for (long long j = 0; j <= n - 1; j++)
			{
				listaF[if2][j] = lista[i][j];
			}
			if2++;
		}
		for (long long i = 0; i <= m - 1; i++)//H
		{
			for (long long j = n - 1; j >= 0; j--)
			{
				listaFF[i][if3] = listaF[i][j];
				if3++;
			}
			if3 = 0;
		}

		for (long long i = 0; i <= m - 1; i++)
		{
			for (long long j =0;j<= n - 1; j++)
			{
				cout << listaFF[i][j] << " ";
			}
			cout << "\n";
		}
	}
	if (h == 1 && v == 0)
	{
		for (long long i = 0; i <= m - 1; i++)//H
		{
			for (long long j = n - 1; j >= 0; j--)
			{
				listaF[i][if3] = lista[i][j];
				if3++;
			}
			if3 = 0;
		}
		for (long long i = 0; i <= m - 1; i++)
		{
			for (long long j = 0; j <= n - 1; j++)
			{
				cout << listaF[i][j] << " ";
			}
			cout << "\n";
		}

	}
	if (h == 0 && v == 1)
	{
		for (long long i = m - 1; i >= 0; i--)//V
		{
			for (long long j = 0; j <= n - 1; j++)
			{
				listaF[if2][j] = lista[i][j];
			}
			if2++;
		}
		
		for (long long i = 0; i <= m - 1; i++)
		{
			for (long long j = 0; j <= n - 1; j++)
			{
				cout << listaF[i][j] << " ";
			}
			cout << "\n";
		}
	}

}