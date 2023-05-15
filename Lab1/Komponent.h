#pragma once

/** @class Komponent
 * Klasa %Komponent. Klasa czysto abstrakcyjna.
 */
class Komponent
{
public:
	///Metoda implementuj�ca generowanie warto�ci.
	virtual double Generuj() = 0;
	///Wirtualny destruktor.
	virtual ~Komponent(){};
};

