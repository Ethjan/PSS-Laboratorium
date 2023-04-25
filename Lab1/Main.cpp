#include <iostream>
#include "SISO.h"
#include "ARX.h"
//#include <boost/program_options.hpp>

int main() {
    ARX obiekt({ -0.5 }, { 1 }, 1, 0.01);
    obiekt.ZapisKonfiguracji("ARX");
    //obiekt.ZapisKonfiguracji("ARX2");
    obiekt.WypiszParametry(std::cout);
    double wyjscie;
    for (int i = 0; i < 1; i++) {
        if (i == 0) {
            wyjscie = obiekt.symuluj(0.0);
        }
        else {
            wyjscie = obiekt.symuluj(1.0);
        }
        std::cout << "Wyjscie: " << wyjscie << std::endl;
    }
    //obiekt.OdczytKonfiguracji();
    //obiekt.WypiszParametry(std::cout);
    return 0;
};
