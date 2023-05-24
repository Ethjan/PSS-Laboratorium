#include "KompozytSzeregowo.h"

/**
 * Symulowanie obiektu o zadanej strukturze.
 * @return obliczone wyjscie struktury szeregowej.
 */
double KompozytSzeregowo::symuluj(double we) {
    double wyjscie = 0.0 ,wejscie = we;
    for (KompozytKomponent* c : s_elementy) {
        wyjscie = c->symuluj(wejscie);
        wejscie = wyjscie;
    }
    return wyjscie;
}