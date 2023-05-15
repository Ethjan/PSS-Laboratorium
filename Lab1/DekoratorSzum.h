#pragma once
#include "Dekorator.h"
#include <random>

/** @class DekoratorSzum
 * Klasa %DekoratorSzum. Klasa implementuje generator szumu o zadanym odchyleniu standardowym.
 */

class DekoratorSzum : public Dekorator
{
private:
	/// Zmienna przechowywująca odchylenie standardowe
	double s_odchylenieStand;
	/// Zmienna przechowująca silnik generatora szumu
	std::default_random_engine s_generator;
	/// Zmienna przechowująca dystybucje szumu
	std::normal_distribution<double> s_dystrybucja;
	public:
		/**  Konstruktor
		* @brief Jako argument przyjmuje wskaźnik do klasy oraz ochylenie standardowe szumu.
		*/
		DekoratorSzum(Komponent* komponent,double odchylenieStand) : Dekorator(komponent), s_odchylenieStand(odchylenieStand), s_generator(std::random_device{}()), s_dystrybucja(0.0, odchylenieStand) {}
		///Metoda implementująca generowanie wartości.
		double Generuj() override;
};

