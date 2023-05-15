#include "Dekorator.h"
#include <iostream>

/**
 * Metoda odpowiedzialna za połączenie generatorów sygnałów.
 */
double Dekorator::Generuj(){
    if (s_komponent != nullptr) {
        return this->s_komponent->Generuj();
    }
    return 0.0;
}