#pragma once
#include "Dekorator.h"

/** @class DekoratorProst
 * Klasa %DekoratorProst. Klasa implementuj�ca generator sygna�u prostok�tnego o zadanej amplitudzie oraz szeroko�ci impulsu.
 */
class DekoratorProst : public Dekorator
{
	private:
		/// Zmienna przechowywuj�ca szeroko�� sygna�u prostok�tnego
		double s_wypelnienie;
		/// Zmienna przechowywuj�ca amplitud� sygna�u prostok�tnego
		double s_amplituda;
	public:
		/**  Konstruktor
		* @brief Dopisa�.
		*/
		DekoratorProst(Komponent* komponent, double amplituda, double wypelnienie) : Dekorator(komponent) , s_amplituda(amplituda), s_wypelnienie(wypelnienie){

		}
		///Metoda implementuj�ca generowanie warto�ci.
		double Generuj() override;
};

