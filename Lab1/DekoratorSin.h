#pragma once
#include "Dekorator.h"

/** @class DekoratorSin
 * Klasa %DekoratorSin. Klasa implementująca generatora sygnału sinusoidalnego o zadanej amplitudzie, częstotliwości oraz przesunięciu fazowym.
 */
class DekoratorSin : public Dekorator
{
	private:
		/// Zmienna przechowywująca amplitudę sinusa.
		double s_amplituda;
		/// Zmienna przechowywująca częstotliwość sinusa.
		double s_czestotliwosc;
		/// Zmienna przechowywująca przesunięcie fazowe sinusa. Jest to ilość próbek, które zostanie przesunięty sinus.
		double s_przesuniecieFazowe;
	public:
		/** Konstruktor
		* @brief Jako argument przyjmuje wskaźnik do klasy oraz amplitudę, częstotliwość i przesunięcie fazowe sinusoidy.
		*/
		DekoratorSin(Komponent* komponent,double amplituda, double czestotliwosc, double przesuniecieFazowe) : Dekorator(komponent), s_amplituda(amplituda),s_czestotliwosc(czestotliwosc),s_przesuniecieFazowe(przesuniecieFazowe) {}
		///Metoda implementująca generowanie wartości.
		double Generuj() override;
};

