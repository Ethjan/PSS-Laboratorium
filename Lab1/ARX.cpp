#include "ARX.h"
#include <iostream>
#include <fstream>
#include <numeric>
#include <random>
#include "json.hpp"

using json = nlohmann::json;

/**
 * @param we wejście obiektu
 * @return obliczone wyjście obiektu
 */
double ARX::symuluj(double we) {
    double wy;
    // Aktualizacja wartosci wejściowych (ustawienie nowej wartości na początku kolejki i usunięcie ostatniego elementu kolejki)
    s_u.push_front(we);
    s_u.pop_back();
    // Obliczenie wartości wyjścia
    if (s_var == 0.0) {
        wy = std::inner_product(begin(s_B), end(s_B), begin(s_u), 0.0) - std::inner_product(begin(s_A), end(s_A), begin(s_y), 0.0);
    }
    else {
        std::default_random_engine generator(std::random_device{}());
        std::normal_distribution<double> dystrybucja(0.0, sqrt(s_var));
        double zaklocenie = dystrybucja(generator);
        wy = std::inner_product(begin(s_B), end(s_B), begin(s_u), 0.0) - std::inner_product(begin(s_A) , end(s_A), begin(s_y), 0.0) + zaklocenie;
    }
    // Aktualizacja wartości wyjsciowych (ustawienie nowej wartości na początku kolejni i usunięcie ostatniego elementu kolejki)
    s_y.push_front(wy);
    s_y.pop_back();
    return wy;
}
/**
 * Wypisananie Parametrów (Wielomian A, Wielomian B, Opóźnienie, Wariancja szumu) na dowolnym strumieniu zadanym przez użytkownika
 */
std::ostream& ARX::WypiszParametry(std::ostream& strumien){
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

/**
 * Zapis konfiguracji do pliku (Wielomian A, Wielomian B, Opóźnienie, Wariancja szumu)
 */
void ARX::ZapisKonfiguracji() {
    std::ifstream PlikOdczyt("Konf.json");
    json KonfiguracjaZapis = json::parse(PlikOdczyt);
    json temp;
    // Sprawdzenie czy podany klucz istnieje. Jeżeli tak, to nadpisz. Jeżeli nie, to utwórz
    if (KonfiguracjaZapis.contains("ARX_A")){
        KonfiguracjaZapis.at("ARX_A") = s_A;
    }
    else {
        temp.clear();
        temp["ARX_A"]= s_A;
        KonfiguracjaZapis.update(temp,true);
    }
    if (KonfiguracjaZapis.contains("ARX_B")) {
        KonfiguracjaZapis.at("ARX_B") = s_B;
    }
    else {
        temp.clear();
        temp["ARX_B"] = s_B;
        KonfiguracjaZapis.update(temp, true);
    }
    if (KonfiguracjaZapis.contains("ARX_k")) {
        KonfiguracjaZapis.at("ARX_k") = s_k;
    }
    else {
        temp.clear();
        temp["ARX_k"] = s_k;
        KonfiguracjaZapis.update(temp, true);
    }
    if (KonfiguracjaZapis.contains("ARX_War")) {
        KonfiguracjaZapis.at("ARX_War") = s_var;
    }
    else {
        temp.clear();
        temp["ARX_War"] = s_var;
        KonfiguracjaZapis.update(temp, true);
    }
    std::ofstream PlikZapis("Konf.json");
    PlikZapis << std::setw(4) << KonfiguracjaZapis << std::endl;
    PlikZapis.close();
    PlikOdczyt.close();
}

/**
 * Odczyt konfiguracji z pliku (Wielomian A, Wielomian B, Opóźnienie, Wariancja szumu)
 */
void ARX::OdczytKonfiguracji() {
    std::ifstream PlikOdczyt("Konf.json");
    json KonfiguracjaOdczyt = json::parse(PlikOdczyt);
    KonfiguracjaOdczyt.at("ARX_A").get_to(s_A);
    KonfiguracjaOdczyt.at("ARX_B").get_to(s_B);
    KonfiguracjaOdczyt.at("ARX_k").get_to(s_k);
    KonfiguracjaOdczyt.at("ARX_War").get_to(s_var);
    PlikOdczyt.close();
}
