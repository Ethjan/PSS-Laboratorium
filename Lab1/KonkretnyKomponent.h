#pragma once
#include "Komponent.h"

/** @class KonkretnyKomponent
 * Klasa %KonkretnyKomponent. Klasa umożliwiająca generację konkretnej wartości stałej zadanej przez użytkownika.
 */
class KonkretnyKomponent : public Komponent
{
private:
	double s_wartStala;
public:
	/**  Konstruktor
	* @brief Jako argument przyjmuje wartość stałą. 
	*/
	KonkretnyKomponent(double wartStala) : s_wartStala(wartStala) {}
	///Metoda implementująca generowanie wartości stałej zadanej przez użytkownika.
	double Generuj() override;
};

