#pragma once
#include "Komponent.h"

/** @class KonkretnyKomponent
 * Klasa %KonkretnyKomponent.
 */
class KonkretnyKomponent : public Komponent
{ 
	public:
		///Metoda implementuj�ca generowanie warto�ci.
		double Generuj() override;
};

