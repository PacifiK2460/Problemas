#include "Bucket.h"

int arreglo[1001];
int ti;

void inicio(int N, int M[]) {
	for (int i = 0; i <= N-1; i++)
	{
		arreglo[i] = M[i];
	}

	ti = N;
	
}

int pregunta(int x) {
	int t = 0;

	for (int i = 0; i <= ti-1; i++)
	{
		if (arreglo[i] == x)
		{
			t = t + 1;
		}
		
	}
	
	return t;
}