#pragma once

/** @class Komponent
 * Klasa %Komponent. Klasa czysto abstrakcyjna.
 */
class Komponent
{
public:
	///Metoda implementująca generowanie wartości.
	virtual double Generuj() = 0;
	///Wirtualny destruktor.
	virtual ~Komponent(){};
};

