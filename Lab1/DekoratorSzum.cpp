#include "DekoratorSzum.h"

/**
 * Generowanie wartości konretnego sygnału o zadanych parametrach
 * @return wygenerowana wartość sygnału
 */
double DekoratorSzum::Generuj() {
	double wartosc = s_dystrybucja(s_generator);
	s_probka++;
	return wartosc + Dekorator::Generuj();
}