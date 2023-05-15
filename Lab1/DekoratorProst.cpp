#include "DekoratorProst.h"
#include <cmath>

#define M_PI 3.14159265358979323846

double DekoratorProst::Generuj() {
	double wartosc;
	s_probka++;
	if (sin(M_PI / s_wypelnienie * s_probka) >=0)
		wartosc = s_amplituda;
	else 
		wartosc = -s_amplituda;
	Dekorator::sprawdzacz();
	return wartosc;
}