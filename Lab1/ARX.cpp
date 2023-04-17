#include "ARX.h"
#include<iostream>
#include<numeric>

double ARX::symuluj(double we) {
    double wy;
    // Aktualizacja wartosci wejciowych (ustawienie nowej wartoœci na pocz¹tku kolejni i usuniêcie ostatniego elementu kolejki)
    s_u.push_front(we);
    s_u.pop_back();
    // Obliczenie wartosci wyjscia
    wy = std::inner_product(begin(s_B), end(s_B), begin(s_u), 0.0) - std::inner_product(begin(s_A) , end(s_A), begin(s_y), 0.0);
    // Aktualizacja wartosci wyjsciowych (ustawienie nowej wartoœci na pocz¹tku kolejni i usuniêcie ostatniego elementu kolejki)
    s_y.push_front(wy);
    s_y.pop_back();
    return wy;
}

void ARX::WypiszParametry() {
    // Wypisananie Parametrów (Wielomian A, Wielomian B, OpóŸnienie, Wariancja szumu)
    std::cout << "Wielomian A: ";
    for (int i = 0; i < s_A.size(); i++) {
        std::cout << s_A.at(i) << ' ';
    }
    std::cout << std::endl;
    std::cout << "Wielomian B: ";
    for (int j = 0; j < s_B.size(); j++) {
        std::cout << s_B.at(j) << ' ';
    }
    std::cout << std::endl;
    std::cout << "Opoznienie: " << s_k << std::endl;
    std::cout << "Wariancja szumu: " << s_var << std::endl;
}

void ARX::WypiszWeWy() {
    // Wypisanie wartoœci wejœciowych oraz wyjœciowych
    std::cout << "Wejscie: ";
    for (int i = 0; i < s_u.size(); i++) {
        std::cout << s_u.at(i) << ' ';
    }
    std::cout << "Wyjscie: ";
    for (int j = 0; j < s_y.size(); j++) {
        std::cout << s_y.at(j) << ' ';
    }
    std::cout << std::endl;
}

