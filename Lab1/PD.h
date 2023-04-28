#pragma once
#include "SISO.h"

/** @class PD
 * Klasa modelująca regulator typu %PD. Umożliwia obliczenie sterowania na podstawie zadanych nastaw oraz wejścia regulatora.
 */
class PD : virtual public  SISO{
	private:
		/// Zmienna przechowująca wzmocnienie regulatora
		double s_Kp;
		/// Zmienna przechowująca stałą czasową różniczkowania
		double s_Td;
		/// Zmienna przechowująca czas próbkowania
		double s_Tp;
		/// Zmienna przechowująca wartość zadaną
		double s_WartZad;
		/// Zmienna przechowująca wartość uchybu
		double s_e;
		/// Zmienna przechowująca poprzednią wartość uchybu
		double s_ePoprzedni;
	public:
		/**  Konstruktor
		* @brief DOPISAC.
		*/
		PD(double Kp = 1, double Td = 1, double Tp = 1, double WartZad = 0) :s_Kp(Kp), s_Td(Td), s_Tp(Tp), s_WartZad(WartZad), s_e(0.0), s_ePoprzedni(0.0) {

		};
		///Metoda symulujaca regulator. Jako argument przyjmuje wejscie regulatora oraz zwraca obliczone wyjscie regulatora.
		double symuluj(double we) override;

		double obliczP();

		double obliczD();

};

