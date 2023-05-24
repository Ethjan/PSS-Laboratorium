#pragma once
#include "DekoratorKomponent.h"

/** @class KonkretnyKomponent
 * Klasa %KonkretnyKomponent. Klasa umożliwiająca generację konkretnej wartości stałej zadanej przez użytkownika.
 */
class DekoratorKonkretnyKomponent : public DekoratorKomponent
{
private:
	double s_wartStala;
public:
	/**  Konstruktor
	* @brief Jako argument przyjmuje wartość stałą. 
	*/
	DekoratorKonkretnyKomponent(double wartStala) : s_wartStala(wartStala) {}
	///Metoda implementująca generowanie wartości stałej zadanej przez użytkownika.
	double Generuj() override;
};

