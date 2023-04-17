#include <iostream>
#include <fstream>
#include "SISO.h"
#include "ARX.h"

int main() {
    ARX obiekt({ -0.5 }, { 1 }, 1, 0);
    obiekt.WypiszParametry();
    double wyjscie;
    std::ofstream outfile("output.txt");
    for (int k = 0; k < 25; k++) {
        if (k == 0){
            wyjscie = obiekt.symuluj(0.0);
        }
        else {
            wyjscie = obiekt.symuluj(1.0);
        }
        //std::cout << "Wyjscie: " << wyjscie << std::endl;
        obiekt.WypiszWeWy();
        if (outfile.is_open()) {
            outfile << wyjscie << std::endl;
        }
        else {
            std::cout << "Nie uda³o siê otworzyæ pliku do zapisu." << std::endl;
        }
    }
    outfile.close();
    return 0;
};
