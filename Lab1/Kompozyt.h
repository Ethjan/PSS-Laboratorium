#pragma once
#include "KompozytKomponent.h"
#include <list>

/** @class Kompozyt
 * Opisuje operacje struktury.
 */
class Kompozyt : public KompozytKomponent
{
protected:
    /// Lista obiektów.
    std::list<KompozytKomponent*> s_elementy;
public:
    ///Metoda dodająca kolejne obiekty do struktury.
    void Dodaj(KompozytKomponent* komponent) override;
    ///Metoda usuwająca obiekty do struktury.
    void Usun(KompozytKomponent* komponent) override;
};

