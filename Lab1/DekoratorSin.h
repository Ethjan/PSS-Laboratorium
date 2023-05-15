#pragma once
#include "Dekorator.h"

/** @class DekoratorSin
 * Klasa %DekoratorSin. Klasa implementuj�ca generatora sygna�u sinusoidalnego o zadanej amplitudzie, cz�stotliwo�ci oraz przesuni�ciu fazowym.
 */
class DekoratorSin : public Dekorator
{
	private:
		/// Zmienna przechowywuj�ca amplitud� sinusa.
		double s_amplituda;
		/// Zmienna przechowywuj�ca cz�stotliwo�� sinusa.
		double s_czestotliwosc;
		/// Zmienna przechowywuj�ca przesuni�cie fazowe sinusa. Jest to ilo�� pr�bek, kt�re zostanie przesuni�ty sinus.
		double s_przesuniecieFazowe;
	public:
		/**  Konstruktor
		* @brief Dopisa�.
		*/
		DekoratorSin(Komponent* komponent,double amplituda, double czestotliwosc, double przesuniecieFazowe) : Dekorator(komponent), s_amplituda(amplituda),s_czestotliwosc(czestotliwosc),s_przesuniecieFazowe(przesuniecieFazowe) {

		}
		///Metoda implementuj�ca generowanie warto�ci.
		double Generuj() override;
};

