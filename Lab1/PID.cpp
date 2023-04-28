#include "PID.h"

/**
 * Obliczenie nowego sterowania na podstawie zadanych nastaw regulatora oraz wejścia regulatora.
 * @param we wejście regulatora
 * @return obliczone wyjście regulatora
 */
double PID::symuluj(double we) {
	double sterowanie;
	s_e = s_WartZad - we;
	//obliczenie sterowania
	sterowanie = s_Kp * s_e + s_eSum / s_Ti + (s_e - s_ePoprzedni) / s_Td;
	//antywindup oraz ograniczenie sterowania
	if (sterowanie < 100 && sterowanie > 0)
		s_eSum = s_eSum + s_e * s_Tp;
	else if (sterowanie > 100)
		sterowanie = 100;
	else if (sterowanie < 0)
		sterowanie = 0;

	return sterowanie;
}