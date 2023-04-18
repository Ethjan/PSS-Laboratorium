#pragma once
#include "SISO.h"
#include <vector>
#include <deque>
#include <iostream>

class ARX : public SISO {
private:
    int s_dA, s_dB, s_k;
    double s_var;
    std::vector<double> s_A, s_B;
    std::deque<double> s_u, s_y;
public:    
    //Kontruktor
    ARX(std::vector<double> A = { -0.5 }, std::vector<double> B = { 1 }, int nk = 1, double var = 0.0) {
        // Przypisanie warto�ci od u�ytkownika do sk�adowych klasy
        s_A = A; // Wielomian nie zawiera 1 na pocz�tku
        s_B = B;
        if (nk < 0) {
            std::cout << "Wprowadzono ujemna wartosc opoznienia - Ustawiono opoznienie na wartosc 1" << std::endl;
            s_k = 1;
        }
        else {
            s_k = nk;
        }
        s_var = var;
        // Dopisanie odpowiedniej ilo�ci zer do wielomianu B zwi�zanych z opoznieniem
        for (int i = 0; i < s_k; i++) {
            s_B.insert(s_B.begin() + i, 0);
        }
        // Inicjalizacja kolejki warto�ci wejsciowych i wyjsciowych
        s_y = std::deque<double>(s_A.size(), 0);
        s_u = std::deque<double>(s_B.size(), 0);
    };
 
    double symuluj(double we);

    void WypiszParametry();

    void WypiszWeWy();
};