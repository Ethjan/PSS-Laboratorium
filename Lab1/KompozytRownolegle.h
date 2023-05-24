#pragma once
#include "Kompozyt.h"

/** @class KompozytRownolegle
 * Klasa składająca obiekty równolegle.
 */
class KompozytRownolegle : public Kompozyt {
    public:
    /// Metoda obliczająca wyjscie zadanej struktury równoległej
    double symuluj(double we) override;
};

