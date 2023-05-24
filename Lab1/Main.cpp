#include <iostream>
#include <fstream>
#include "SISO.h"
#include "ARX.h"
#include "PI.h"
#include "PD.h"
#include "PID.h"
#include "DekoratorKomponent.h"
#include "DekoratorKonkretnyKomponent.h"
#include "Dekorator.h"
#include "DekoratorSin.h"
#include "DekoratorProst.h"
#include "DekoratorSzum.h"
#include "KompozytKomponent.h"
#include "Kompozyt.h"
#include "KompozytSzeregowo.h"
#include "KompozytRownolegle.h"

int main() {
    double wyjscie;
    //double wartosc;

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
    double wyjscie=0.0 ,sterowanie ,wartZadana = 3.0;
    for (int i = 0; i < 100; i++) {
        sterowanie = regulator1.symuluj(wartZadana - wyjscie);
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

    /*
    // Test Generatora
    DekoratorKomponent* generatorKonkretny = new DekoratorKonkretnyKomponent(2.0);
    DekoratorKomponent* generatorSzum = new DekoratorSzum(generatorKonkretny,0.1);
    DekoratorKomponent* generatorSzumSin = new DekoratorSin(generatorSzum,1,60,0);
    DekoratorKomponent* generatorSzumSinProst = new DekoratorProst(generatorSzumSin,1,20);

    std::ofstream outfile("Generator.txt");
    

    for (int i = 0; i < 100; i++) {
        wartosc = generatorSzumSinProst->Generuj();
        std::cout << "Wyjscie: " << wartosc << std::endl;
        if (outfile.is_open()) {
            outfile << wartosc << std::endl;
        }
        else {
            std::cout << "Nie udało się otworzyć pliku do zapisu." << std::endl;
        }
    }
    outfile.close();

    delete generatorKonkretny;
    delete generatorSzum;
    delete generatorSzumSin;
    delete generatorSzumSinProst;
    */

    ///*
    // Test Kompozytu
    KompozytKomponent* grupa1 = new KompozytSzeregowo;

    KompozytKomponent* obiekt11 = new ARX({ -0.8, 0.4 }, { 1 }, 1, 0.0);
    KompozytKomponent* obiekt12 = new ARX({ -0.8, 0.4 }, { 1 }, 1, 0.0);

    grupa1->Dodaj(obiekt11);
    grupa1->Dodaj(obiekt12);

    KompozytKomponent* grupa2 = new KompozytRownolegle;

    KompozytKomponent* obiekt21 = new ARX({ -0.8, 0.4 }, { 1 }, 1, 0.0);
    KompozytKomponent* obiekt22 = new ARX({ -0.8, 0.4 }, { 1 }, 1, 0.0);

    grupa2->Dodaj(obiekt21);
    grupa2->Dodaj(obiekt22);

    KompozytKomponent* grupa3 = new KompozytRownolegle;

    grupa3->Dodaj(grupa1);
    grupa3->Dodaj(grupa2);

    KompozytKomponent* obiekt32 = new ARX({ -0.8, 0.4 }, { 1 }, 1, 0.0);
    KompozytKomponent* struktura = new KompozytSzeregowo;

    struktura->Dodaj(obiekt32);
    struktura->Dodaj(grupa3);

    std::ofstream outfile("Struktura.txt");
    for (int i = 0; i < 100; i++) {
        
        if (i == 0) {
            wyjscie = struktura->symuluj(0.0);
        }
        else {
            wyjscie = struktura->symuluj(1.0);
        }
        std::cout << "Wyjscie: " << wyjscie << std::endl;
        if (outfile.is_open()) {
            outfile << wyjscie << std::endl;
        }
        else {
            std::cout << "Nie udało się otworzyć pliku do zapisu." << std::endl;
        }
    }
    outfile.close();

    delete obiekt11;
    delete obiekt12;
    delete grupa1;
    delete obiekt21;
    delete obiekt22;
    delete grupa2;
    delete obiekt32;
    delete grupa3;
    delete struktura;
    //*/

    return 0;
};
