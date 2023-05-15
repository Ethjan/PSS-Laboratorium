#include "Dekorator.h"
#include <iostream>

/**
 * Dopisa�
 * @return Dopisa�
 */
double Dekorator::Generuj(){
    if (s_komponent != nullptr) {
        return s_komponent->Generuj();
    }
    return 0.0;
}

void Dekorator::sprawdzacz(){
	std::cout << "Pr�bka numer: " << s_probka << std::endl;
}