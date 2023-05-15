#pragma once
#include "Komponent.h"

/** @class KonkretnyKomponent
 * Klasa %KonkretnyKomponent.
 */
class KonkretnyKomponent : public Komponent
{ 
	public:
		///Metoda implementuj¹ca generowanie wartoœci.
		double Generuj() override;
};

