#pragma once
#include "Komponent.h"

/** @class KonkretnyKomponent
 * Klasa %KonkretnyKomponent.
 */
class KonkretnyKomponent : public Komponent
{
private:
	double s_wartStala;
public:
	KonkretnyKomponent(double wartStala) : s_wartStala(wartStala) {

	}
	///Metoda implementuj�ca generowanie warto�ci.
	double Generuj() override;
};

