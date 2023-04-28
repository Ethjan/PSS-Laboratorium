#include <iostream>
#include <fstream>
#include "SISO.h"
#include "ARX.h"
#include "PI.h"
#include "PD.h"
#include "PID.h"

int main() {
    ARX obiekt({ -0.8, 0.4 }, { 1 }, 1, 0);
    //PI regulator(0.1, 10, 1, 3);
    //PD regulator(0.2, 100, 1, 3);
    PID regulator(0.02, 20, 100, 1,10);
    std::fstream PlikOdczyt("Konf.json", std::ios::in | std::ios::out);
    std::fstream PlikZapis("Konf.json", std::ios::in | std::ios::out);
    obiekt.ZapisKonfiguracji(PlikOdczyt, PlikZapis);
    PlikOdczyt.close();
    PlikZapis.close();
    obiekt.WypiszParametry(std::cout);

    /*
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
    */

    std::ofstream outfile("output.txt");
    double wyjscie=0.0 ,sterowanie;
    for (int i = 0; i < 100
        ; i++) {
        sterowanie = regulator.symuluj(wyjscie);
        wyjscie = obiekt.symuluj(sterowanie);
        std::cout << "Wyjscie: " << wyjscie << std::endl;
        if (outfile.is_open()) {
            outfile << wyjscie << std::endl;
        }
        else {
            std::cout << "Nie udało się otworzyć pliku do zapisu." << std::endl;
        }
    }
    outfile.close();
    

    std::fstream PlikOdczyt2("Konf.json", std::ios::in);
    obiekt.OdczytKonfiguracji(PlikOdczyt2);
    PlikOdczyt2.close();
    obiekt.WypiszParametry(std::cout);
    return 0;
};
