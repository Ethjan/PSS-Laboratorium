#pragma once
#include "Kompozyt.h"

/** @class KompozytSzeregowo
 * Klasa składająca obiekty szeregowo.
 */
class KompozytSzeregowo : public Kompozyt{
public:
    /// Metoda obliczająca wyjscie zadanej struktury szeregowej
    double symuluj(double we) override;
};

