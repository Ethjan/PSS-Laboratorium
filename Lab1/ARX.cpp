#include "ARX.h"
#include <iostream>
#include <fstream>
#include <numeric>
#include <random>
#include "json.hpp"
#include <boost/program_options.hpp>

namespace po = boost::program_options;

using json = nlohmann::json;

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

void ARX::ZapisKonfiguracji(std::string Nazwa) {
    //std::ifstream PlikOdczyt("Konf.json");
    //json KonfiguracjaZapis = json::parse(PlikOdczyt);

    //std::cout << KonfiguracjaZapis.at("ARX") << std::endl;
    //std::cout << KonfiguracjaZapis.at("A") << KonfiguracjaZapis.at("B") << KonfiguracjaZapis.at("k") << KonfiguracjaZapis.at("War") << std::endl;

    //json Zapis;
    //json KonfiguracjaZapis;
    //json cos = { "orangutan","cos"};
    //json cos = {
    //        {"A", s_A},
     //       {"B", s_B},
    //        {"k", s_k},
    //        {"War", s_var}
    //};
    //Zapis = json::array({ {Nazwa,cos} });
    //KonfiguracjaZapis.update(Zapis);
    //std::cout << "Konfiguracja: " << Zapis << std::endl;
    //std::ofstream PlikZapis("Konf.json");
    //PlikZapis << std::setw(4) << Zapis << std::endl;


}

void ARX::OdczytKonfiguracji(std::string Nazwa) {
    std::ifstream PlikOdczyt("Konf.json");
    json KonfiguracjaOdczyt = json::parse(PlikOdczyt);
    KonfiguracjaOdczyt.at("A").get_to(s_A);
    KonfiguracjaOdczyt.at("B").get_to(s_B);
    KonfiguracjaOdczyt.at("k").get_to(s_k);
    KonfiguracjaOdczyt.at("War").get_to(s_var);
}
