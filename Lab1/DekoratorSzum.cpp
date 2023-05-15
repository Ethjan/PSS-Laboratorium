#include "DekoratorSzum.h"

/**
 * Generowanie warto�ci konretnego sygna�u o zadanych parametrach
 * @return wygenerowana warto�� sygna�u
 */
double DekoratorSzum::Generuj() {
	double wartosc = s_dystrybucja(s_generator);
	s_probka++;
	//Dekorator::sprawdzacz();
	return wartosc + Dekorator::Generuj();
}