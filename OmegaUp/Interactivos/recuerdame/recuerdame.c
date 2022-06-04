#include "recuerdame.h"
int n = -1;

void recuerdame(int x) {
	n = x;
}

bool soy(int x) {
	return n == x ? true : false;
}
