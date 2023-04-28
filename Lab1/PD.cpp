#include "PD.h"

/**
 * Obliczenie nowego sterowania na podstawie zadanych nastaw regulatora oraz wejścia regulatora.
 * @param we wejście regulatora
 * @return obliczone wyjście regulatora
 */
double PD::symuluj(double we) {
	double sterowanie;
	s_e = s_WartZad - we;
	//obliczenie sterowania
	sterowanie = obliczP() + obliczD();
	//sterowanie = s_Kp * s_e + (s_e-s_ePoprzedni) / s_Td;
	//antywindup oraz ograniczenie sterowania
	if (sterowanie > 100)
		sterowanie = 100;
	else if (sterowanie < 0)
		sterowanie = 0;

	return sterowanie;
}

double PD::obliczP() {
	return s_Kp * s_e;
}

double PD::obliczD() {
	return (s_e - s_ePoprzedni) / s_Td;
}
