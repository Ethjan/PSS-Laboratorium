#pragma once
#include "Komponent.h"

/** @class Dekorator
 * Klasa %Dekorator. Klasa dziedziczy po klasie Komponent.
 */

class Dekorator : public Komponent
{
protected:
    /// Wska�nik do obiektu Komponent
    Komponent* s_komponent;
    /// Zmienna przechowywuj�ca numer pr�bki
    unsigned int s_probka;
public: 
    /**  Konstruktor
    * @brief Dopisa�.
    */
    Dekorator(Komponent* komponent) : s_komponent(komponent), s_probka(0){}
    ///Metoda implementuj�ca generowanie warto�ci.
    double Generuj() override;

    // Do usunu�cia
    void sprawdzacz();
    
};

