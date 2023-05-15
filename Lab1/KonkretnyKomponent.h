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
	///Metoda implementuj¹ca generowanie wartoœci.
	double Generuj() override;
};

