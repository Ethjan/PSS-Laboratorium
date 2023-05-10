#pragma once
#include "SISO.h"
#include <iostream>

/** @class PI
 * Klasa modelująca regulator typu %PI. Umożliwia obliczenie sterowania na podstawie zadanych nastaw oraz wejścia regulatora.
 */
class PI : virtual public SISO {
protected:
	/// Zmienna przechowująca wzmocnienie regulatora
	double s_Kp;
	/// Zmienna przechowująca stałą czasową całkowania
	double s_Ti;
	/// Zmienna przechowująca czas próbkowania
	double s_Tp;
	/// Zmienna przechowująca wartość zadaną
	double s_WartZad;
	/// Zmienna przechowująca wartość uchybu
	double s_e;
	/// Zmienna przechowująca sumę uchybów
	double s_eSum;
public:
	/**  Konstruktor
	* @brief Inicjalizacja wartości klasy.
	*/
	PI(double Kp = 1, double Ti = 1, double Tp = 1, double WartZad = 0) :s_Kp(Kp), s_Ti(Ti), s_Tp(Tp), s_WartZad(WartZad), s_e(0.0), s_eSum(0.0) {
	};
	///Metoda symulujaca regulator. Jako argument przyjmuje wejscie regulatora oraz zwraca obliczone wyjscie regulatora.
	double symuluj(double we) override;

	///Metoda zapisujaca parametry regulatora w pliku. Jako argumenty przyjmuje referencje do strumieni do odczytu i zapisu oraz zwraca referecje do strumienia do zapisu.
	std::fstream& ZapisKonfiguracji(std::fstream& strumienOdczyt, std::fstream& strumienZapis);
	///Metoda odczytyjaca parametry regulatora z pliku. Jako argument przyjmuje referencje do strumienia oraz zwraca referecje do strumienia.
	std::fstream& OdczytKonfiguracji(std::fstream& strumien);
};

