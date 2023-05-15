#include "DekoratorSzum.h"

/**
 * Generowanie wartoœci konretnego sygna³u o zadanych parametrach
 * @return wygenerowana wartoœæ sygna³u
 */
double DekoratorSzum::Generuj() {
	double wartosc = s_dystrybucja(s_generator);
	s_probka++;
	//Dekorator::sprawdzacz();
	return wartosc + Dekorator::Generuj();
}