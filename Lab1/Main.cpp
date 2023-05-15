#include <iostream>
#include <fstream>
#include "SISO.h"
#include "ARX.h"
#include "PI.h"
#include "PD.h"
#include "PID.h"
#include "Komponent.h"
#include "KonkretnyKomponent.h"
#include "Dekorator.h"
#include "DekoratorSin.h"
#include "DekoratorProst.h"
#include "DekoratorSzum.h"

int main() {
    //ARX obiekt({ -0.8, 0.4 }, { 1 }, 1, 0.1);
    //PI regulator1(0.1, 10, 1, 3);
    //PD regulator2(0.2, 100, 1, 3);
    //PID regulator3(0.02, 20, 100, 1,10);

    // Test zapisu konfiguracji
    /*
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
    */

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
    regulator1.zmianaWartZad(5);
    std::ofstream outfile("output.txt");
    double wyjscie=0.0 ,sterowanie;
    for (int i = 0; i < 100; i++) {
        sterowanie = regulator1.symuluj(wyjscie);
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
    /*
    std::fstream PlikOdczyt2("Konf.json", std::ios::in);
    obiekt.OdczytKonfiguracji(PlikOdczyt2);
    obiekt.WypiszParametry(std::cout);
    */

    // Test Generatora
    Komponent* simple = new KonkretnyKomponent(3.0);
    Komponent* generator1 = new DekoratorSzum(simple,0.1);
    Komponent* generator2 = new DekoratorSin(generator1,1,60,0);
    Komponent* generator3 = new DekoratorProst(generator2,1,20);

    std::ofstream outfile("Generator.txt");
    double wartosc;

    for (int i = 0; i < 100; i++) {
        wartosc = generator3->Generuj();
        std::cout << "Wyjscie: " << wartosc << std::endl;
        if (outfile.is_open()) {
            outfile << wartosc << std::endl;
        }
        else {
            std::cout << "Nie udało się otworzyć pliku do zapisu." << std::endl;
        }
    }
    outfile.close();

    delete simple;
    delete generator1;
    delete generator2;
    delete generator3;
    return 0;
};
