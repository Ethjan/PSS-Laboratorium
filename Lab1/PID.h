#pragma once
#include "PI.h"
#include "PD.h"

/** @class PID
 * Klasa modelująca regulator typu %PID. Umożliwia obliczenie sterowania na podstawie zadanych nastaw oraz wejścia regulatora.
 */
class PID: public PI, public PD{
	private:
		/// Zmienna przechowująca wzmocnienie regulatora
		double s_Kp;
		/// Zmienna przechowująca stałą czasową całkowania
		double s_Ti;
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
		/// Zmienna przechowująca sumę uchybów
		double s_eSum;
	public:
		/**  Konstruktor
		* @brief DOPISAC.
		*/
		
		PID(double Kp = 1, double Ti = 1, double Td = 1, double Tp = 1, double WartZad = 0) : s_Kp(Kp), s_Ti(Ti), s_Td(Td), s_Tp(Tp), s_WartZad(WartZad), s_e(0.0), s_eSum(0.0), s_ePoprzedni(0.0) {

		};
		
		///Metoda symulujaca regulator. Jako argument przyjmuje wejscie regulatora oraz zwraca obliczone wyjscie regulatora.
		double symuluj(double we) override;

};

