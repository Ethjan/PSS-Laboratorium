#pragma once

/** @class SISO
 * Klasa modelujaca obiekt typu %SISO. Klasa czysto abstrakcyjna.
 */
class SISO {
public:
    ///Metoda symulujaca obiekt. Metoda czysto wirtualna.
    virtual double symuluj(double we) = 0;
    ///Wirtualny destruktor.
    virtual ~SISO(){};
};
