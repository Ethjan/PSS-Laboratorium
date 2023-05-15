#include "DekoratorSin.h"
#include <cmath>

#define M_PI 3.14159265358979323846

/**
 * Generowanie wartoœci konretnego sygna³u o zadanych parametrach
 * @return wygenerowana wartoœæ sygna³u
 */
double DekoratorSin::Generuj() {
	double wartosc = s_amplituda * sin(2 * M_PI / s_czestotliwosc * s_probka + s_przesuniecieFazowe);
	s_probka++;
	//Dekorator::sprawdzacz();
	return wartosc + Dekorator::Generuj();
}