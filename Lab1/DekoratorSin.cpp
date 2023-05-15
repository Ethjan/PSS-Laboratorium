#include "DekoratorSin.h"
#include <cmath>

#define M_PI 3.14159265358979323846

/**
 * Generowanie wartości konretnego sygnału o zadanych parametrach
 * @return wygenerowana wartość sygnału
 */
double DekoratorSin::Generuj() {
	double wartosc = s_amplituda * sin(2 * M_PI / s_czestotliwosc * s_probka + s_przesuniecieFazowe);
	s_probka++;
	return wartosc + Dekorator::Generuj();
}