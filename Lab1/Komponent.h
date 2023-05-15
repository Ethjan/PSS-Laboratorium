#pragma once

/** @class Komponent
 * Klasa %Komponent. Klasa czysto abstrakcyjna.
 */
class Komponent
{
public:
	///Metoda implementuj¹ca generowanie wartoœci.
	virtual double Generuj() = 0;
	///Wirtualny destruktor.
	virtual ~Komponent(){};
};

