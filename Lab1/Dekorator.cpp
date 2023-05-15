#include "Dekorator.h"
#include <iostream>

/**
 * Dopisaæ
 * @return Dopisaæ
 */
double Dekorator::Generuj(){
    if (s_komponent != nullptr) {
        return s_komponent->Generuj();
    }
    return 0.0;
}

void Dekorator::sprawdzacz(){
	std::cout << "Próbka numer: " << s_probka << std::endl;
}