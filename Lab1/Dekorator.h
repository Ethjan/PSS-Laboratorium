#pragma once
#include "Komponent.h"

/** @class Dekorator
 * Klasa %Dekorator. Klasa dziedziczy po klasie Komponent.
 */

class Dekorator : public Komponent
{
protected:
    /// WskaŸnik do obiektu Komponent
    Komponent* s_komponent;
    /// Zmienna przechowywuj¹ca numer próbki
    unsigned int s_probka;
public: 
    /**  Konstruktor
    * @brief Dopisaæ.
    */
    Dekorator(Komponent* komponent) : s_komponent(komponent), s_probka(0){}
    ///Metoda implementuj¹ca generowanie wartoœci.
    double Generuj() override;

    // Do usunuêcia
    void sprawdzacz();
    
};

