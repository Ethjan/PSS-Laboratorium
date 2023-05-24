#pragma once

/** @class Komponent
 * Klasa %Komponent. Klasa czysto abstrakcyjna.
 */
class DekoratorKomponent
{
public:
	///Metoda implementująca generowanie wartości.
	virtual double Generuj() = 0;
	///Wirtualny destruktor.
	virtual ~DekoratorKomponent(){};
};

