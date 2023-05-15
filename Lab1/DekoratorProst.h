#pragma once
#include "Dekorator.h"

/** @class DekoratorProst
 * Klasa %DekoratorProst. Klasa implementuj¹ca generator sygna³u prostok¹tnego o zadanej amplitudzie oraz szerokoœci impulsu.
 */
class DekoratorProst : public Dekorator
{
	private:
		/// Zmienna przechowywuj¹ca szerokoœæ sygna³u prostok¹tnego
		double s_wypelnienie;
		/// Zmienna przechowywuj¹ca amplitudê sygna³u prostok¹tnego
		double s_amplituda;
	public:
		/**  Konstruktor
		* @brief Dopisaæ.
		*/
		DekoratorProst(Komponent* komponent, double amplituda, double wypelnienie) : Dekorator(komponent) , s_amplituda(amplituda), s_wypelnienie(wypelnienie){

		}
		///Metoda implementuj¹ca generowanie wartoœci.
		double Generuj() override;
};

