#include <iostream>
#include <fstream>
#include "SISO.h"
#include "ARX.h"
#include "PI.h"
#include "PD.h"
#include "PID.h"

int main() {
    ARX obiekt({ -0.8, 0.4 }, { 1 }, 1, 0.1);
    PI regulator1(0.1, 10, 1, 3);
    PD regulator2(0.2, 100, 1, 3);
    PID regulator3(0.02, 20, 100, 1,10);

    // Test zapisu konfiguracji
    std::fstream PlikOdczyt("Konf.json", std::ios::in | std::ios::out);
    std::fstream PlikZapis("Konf.json", std::ios::in | std::ios::out);
    obiekt.ZapisKonfiguracji(PlikOdczyt, PlikZapis);
    obiekt.WypiszParametry(std::cout);

    std::fstream PlikOdczyt1("Konf.json", std::ios::in | std::ios::out);
    std::fstream PlikZapis1("Konf.json", std::ios::in | std::ios::out);
    regulator1.ZapisKonfiguracji(PlikOdczyt1, PlikZapis1);

    std::fstream PlikOdczyt3("Konf.json", std::ios::in | std::ios::out);
    std::fstream PlikZapis3("Konf.json", std::ios::in | std::ios::out);
    regulator2.ZapisKonfiguracji(PlikOdczyt3, PlikZapis3);

    std::fstream PlikOdczyt4("Konf.json", std::ios::in | std::ios::out);
    std::fstream PlikZapis4("Konf.json", std::ios::in | std::ios::out);
    regulator3.ZapisKonfiguracji(PlikOdczyt4, PlikZapis4);

    // Test obiektu
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
    // Test sterowania
    /*
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
    */
    // Test odczytu konfiguracji
    std::fstream PlikOdczyt2("Konf.json", std::ios::in);
    obiekt.OdczytKonfiguracji(PlikOdczyt2);
    obiekt.WypiszParametry(std::cout);
    return 0;
};
