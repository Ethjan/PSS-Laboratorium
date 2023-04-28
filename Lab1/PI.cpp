#include "PI.h"

/**
 * Obliczenie nowego sterowania na podstawie zadanych nastaw regulatora oraz wejścia regulatora.
 * @param we wejście regulatora
 * @return obliczone wyjście regulatora
 */
double PI::symuluj(double we) {
	double sterowanie;
	s_e = s_WartZad - we;
	//obliczenie sterowania
	sterowanie = obliczP() + obliczI();
	// sterowanie = s_Kp * s_e + s_eSum / s_Ti;
	//antywindup oraz ograniczenie sterowania
	if (sterowanie < 100 && sterowanie > 0)
		s_eSum = s_eSum + s_e* s_Tp;
	else if (sterowanie > 100)
		sterowanie = 100;
	else if (sterowanie < 0)
		sterowanie = 0;

	return sterowanie;
}


double PI::obliczP() {
	return s_Kp * s_e;
}

double PI::obliczI() {
	return s_eSum / s_Ti;
}
