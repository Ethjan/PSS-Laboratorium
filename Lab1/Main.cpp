#include <iostream>
#include "SISO.h"
#include "ARX.h"

int main() {
    ARX obiekt({ 1,-0.5 }, { 1 }, 1, 0);
    obiekt.WypiszParametry();
    double wyjscie;
    for (int k = 0; k < 10; k++) {
        wyjscie = obiekt.symuluj(1.0);
        std::cout << "Wyjscie: " << wyjscie << std::endl;
        //obiekt.WypiszWeWy();
    }
    return 0;
};
