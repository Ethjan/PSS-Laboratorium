#pragma once
#include "DekoratorKomponent.h"

/** @class Dekorator
 * Klasa %Dekorator. Klasa dziedziczy po klasie Komponent.
 */

class Dekorator : public DekoratorKomponent
{
protected:
    /// Wskaźnik do obiektu Komponent
    DekoratorKomponent* s_komponent;
    /// Zmienna przechowywująca numer próbki
    unsigned int s_probka;
public: 
    /**  Konstruktor
    * @brief Jako argument przyjmuje wskaźnik do klasy.
    */
    Dekorator(DekoratorKomponent* komponent) : s_komponent(komponent), s_probka(0){}
    ///Metoda implementująca generowanie wartości.
    double Generuj() override;
    
};

