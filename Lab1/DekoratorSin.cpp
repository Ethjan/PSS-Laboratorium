#include "DekoratorSin.h"
#include <cmath>

#define M_PI 3.14159265358979323846

double DekoratorSin::Generuj() {
	double wartosc = s_amplituda * sin(2 * M_PI / s_czestotliwosc * s_probka + s_przesuniecieFazowe);
	s_probka++;
	Dekorator::sprawdzacz();
	return wartosc;
}