#include "DekoratorSzum.h"

double DekoratorSzum::Generuj() {
	double wartosc = s_dystrybucja(s_generator);
	s_probka++;
	Dekorator::sprawdzacz();
	return wartosc;
}