#pragma once
#include "Dekorator.h"
#include <random>

/** @class DekoratorSzum
 * Klasa %DekoratorSzum. Klasa implementuje generator szumu o zadanym odchyleniu standardowym.
 */

class DekoratorSzum : public Dekorator
{
private:
	/// Zmienna przechowywuj¹ca odchylenie standardowe
	double s_odchylenieStand;
	/// Zmienna przechowuj¹ca silnik generatora szumu
	std::default_random_engine s_generator;
	/// Zmienna przechowuj¹ca dystybucje szumu
	std::normal_distribution<double> s_dystrybucja;
	public:
		/**  Konstruktor
		* @brief Dopisaæ.
		*/
		DekoratorSzum(Komponent* komponent,double odchylenieStand) : Dekorator(komponent), s_odchylenieStand(odchylenieStand), s_generator(std::random_device{}()), s_dystrybucja(0.0, odchylenieStand) {

		}
		///Metoda implementuj¹ca generowanie wartoœci.
		double Generuj() override;
};

