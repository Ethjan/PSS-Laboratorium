#include "ARX.h"
#include<iostream>
#include<numeric>

double ARX::symuluj(double we) {
    double wy;
    s_u.push_back(we);
    s_u.erase(s_u.begin());
    wy = std::inner_product(begin(s_B), end(s_B), begin(s_u), 0.0) + std::inner_product(begin(s_A), end(s_A), begin(s_y), 0.0);
    s_y.push_back(wy);
    s_y.erase(s_y.begin());
    return wy;
}

void ARX::WypiszParametry() {
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

