#pragma once
#include "Dekorator.h"

/** @class DekoratorSin
 * Klasa %DekoratorSin. Klasa implementuj¹ca generatora sygna³u sinusoidalnego o zadanej amplitudzie, czêstotliwoœci oraz przesuniêciu fazowym.
 */
class DekoratorSin : public Dekorator
{
	private:
		/// Zmienna przechowywuj¹ca amplitudê sinusa.
		double s_amplituda;
		/// Zmienna przechowywuj¹ca czêstotliwoœæ sinusa.
		double s_czestotliwosc;
		/// Zmienna przechowywuj¹ca przesuniêcie fazowe sinusa. Jest to iloœæ próbek, które zostanie przesuniêty sinus.
		double s_przesuniecieFazowe;
	public:
		/**  Konstruktor
		* @brief Dopisaæ.
		*/
		DekoratorSin(Komponent* komponent,double amplituda, double czestotliwosc, double przesuniecieFazowe) : Dekorator(komponent), s_amplituda(amplituda),s_czestotliwosc(czestotliwosc),s_przesuniecieFazowe(przesuniecieFazowe) {

		}
		///Metoda implementuj¹ca generowanie wartoœci.
		double Generuj() override;
};

