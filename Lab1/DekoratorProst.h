#pragma once
#include "Dekorator.h"

/** @class DekoratorProst
 * Klasa %DekoratorProst. Klasa implementująca generator sygnału prostokątnego o zadanej amplitudzie oraz szerokości impulsu.
 */
class DekoratorProst : public Dekorator
{
	private:
		/// Zmienna przechowywująca szerokość sygnału prostokątnego
		double s_wypelnienie;
		/// Zmienna przechowywująca amplitudę sygnału prostokątnego
		double s_amplituda;
	public:
		/** Konstruktor
		* @brief Jako argument przyjmuje wskaźnik do klasy oraz amplitudę i szerokość sygnału prostokątnego.
		*/
		DekoratorProst(DekoratorKomponent* komponent, double amplituda, double wypelnienie) : Dekorator(komponent) , s_amplituda(amplituda), s_wypelnienie(wypelnienie){}
		///Metoda implementująca generowanie wartości.
		double Generuj() override;
};

