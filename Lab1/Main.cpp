#include <iostream>
#include "SISO.h"
#include "ARX.h"
//#include <boost/program_options.hpp>

int main() {
    ARX obiekt({ -0.5 }, { 1 }, 1, 0.01);
    obiekt.WypiszParametry(std::cout);
    double wyjscie;
    for (int i = 0; i < 25; i++) {
        if (i == 0) {
            wyjscie = obiekt.symuluj(0.0);
        }
        else {
            wyjscie = obiekt.symuluj(1.0);
        }
        std::cout << "Wyjscie: " << wyjscie << std::endl;
    }
    std::cout << "TEST" << std::endl;
    return 0;
};
