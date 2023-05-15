#pragma once
#include "Dekorator.h"
#include <random>

/** @class DekoratorSzum
 * Klasa %DekoratorSzum. Klasa implementuje generator szumu o zadanym odchyleniu standardowym.
 */

class DekoratorSzum : public Dekorator
{
private:
	/// Zmienna przechowywuj�ca odchylenie standardowe
	double s_odchylenieStand;
	/// Zmienna przechowuj�ca silnik generatora szumu
	std::default_random_engine s_generator;
	/// Zmienna przechowuj�ca dystybucje szumu
	std::normal_distribution<double> s_dystrybucja;
	public:
		/**  Konstruktor
		* @brief Dopisa�.
		*/
		DekoratorSzum(Komponent* komponent,double odchylenieStand) : Dekorator(komponent), s_odchylenieStand(odchylenieStand), s_generator(std::random_device{}()), s_dystrybucja(0.0, odchylenieStand) {

		}
		///Metoda implementuj�ca generowanie warto�ci.
		double Generuj() override;
};

