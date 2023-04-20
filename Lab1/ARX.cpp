#include "ARX.h"
#include<iostream>
#include<numeric>
#include<random>

double ARX::symuluj(double we) {
    double wy;
    // Aktualizacja wartosci wejciowych (ustawienie nowej wartoœci na pocz¹tku kolejni i usuniêcie ostatniego elementu kolejki)
    s_u.push_front(we);
    s_u.pop_back();

    // Obliczenie wartosci wyjscia
    if (s_var == 0) {
        wy = std::inner_product(begin(s_B), end(s_B), begin(s_u), 0.0) - std::inner_product(begin(s_A), end(s_A), begin(s_y), 0.0);
    }
    else {
        std::default_random_engine generator(std::random_device{}());
        std::normal_distribution<double> dystrybucja(0.0, sqrt(s_var));
        double zaklocenie = dystrybucja(generator);
        std::cout << zaklocenie << std::endl;
        wy = std::inner_product(begin(s_B), end(s_B), begin(s_u), 0.0) - std::inner_product(begin(s_A) , end(s_A), begin(s_y), 0.0) + zaklocenie;
    }
    // Aktualizacja wartosci wyjsciowych (ustawienie nowej wartoœci na pocz¹tku kolejni i usuniêcie ostatniego elementu kolejki)
    s_y.push_front(wy);
    s_y.pop_back();
    return wy;
}
std::ostream& ARX::WypiszParametry(std::ostream& strumien){
    // Wypisananie Parametrów (Wielomian A, Wielomian B, OpóŸnienie, Wariancja szumu)
    strumien << "Wielomian A: ";
    for (int i = 0; i < s_A.size(); i++) {
        strumien << s_A.at(i) << ' ';
    }
    strumien << std::endl;
    strumien << "Wielomian B: ";
    for (int i = 0; i < s_B.size(); i++) {
        strumien << s_B.at(i) << ' ';
    }
    strumien << std::endl;
    strumien << "Opoznienie: " << s_k << std::endl;
    strumien << "Wariancja szumu: " << s_var << std::endl;
    return strumien;
}

void ARX::ZapisKonfiguracji() {

}
