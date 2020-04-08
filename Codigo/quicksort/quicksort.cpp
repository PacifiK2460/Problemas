#include "quicksort.h"

// Main
//	int ElementoEnPosicion(int i)
//	int Intercambiar(int i, int j)

int HacerParticion(int inicio, int fin) {
	if (ElementoEnPosicion(inicio) > ElementoEnPosicion((inicio + fin) / 2))
	{
		Intercambiar(inicio,((inicio + fin) / 2));
	}

	return ElementoEnPosicion(inicio);
}