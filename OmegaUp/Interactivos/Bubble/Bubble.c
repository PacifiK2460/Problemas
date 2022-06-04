#include "Bubble.h"

// Main
//	int pregunta(int x)
//	void cambia(int x)

int inicio(int n) {
        for(int i = 0; i < n-2; i++)
        {
            if(pregunta(i) > pregunta(i+1))
            {
                cambia(i);
            }
        }

	return 0;
}
