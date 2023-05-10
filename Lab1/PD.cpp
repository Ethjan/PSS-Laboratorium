#include "PD.h"
#include <fstream>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;
/**
 * Obliczenie nowego sterowania na podstawie zadanych nastaw regulatora oraz wejścia regulatora.
 * @param we wejście regulatora
 * @return obliczone wyjście regulatora
 */
double PD::symuluj(double we) {
	double sterowanie;
	s_e = s_WartZad - we;
	//obliczenie sterowania
	sterowanie = s_Kp * s_e + (s_e-s_ePoprzedni) / s_Td;
	//ograniczenie sterowania
	if (sterowanie > 100)
		sterowanie = 100;
	else if (sterowanie < 0)
		sterowanie = 0;

	return sterowanie;
}
/**
 * Zapis konfiguracji do pliku (Wzmocnienie regulatora, Stała czasowa różniczkowania, Okres próbkowana, Wartość zadana).
 * @param strumienOdczyt referencja do strumienia do odczytu.
 * @param strumienZapis referencja do strumienia do zapisu.
 * @return referencja do strumienia
 */
std::fstream& PD::ZapisKonfiguracji(std::fstream& strumienOdczyt, std::fstream& strumienZapis) {
    json KonfiguracjaZapis = json::parse(strumienOdczyt);
    json temp;
    // Sprawdzenie czy podany klucz istnieje. Jeżeli tak, to nadpisz. Jeżeli nie, to utwórz
    if (KonfiguracjaZapis.contains("PD_Kp")) {
        KonfiguracjaZapis.at("PD_Kp") = s_Kp;
    }
    else {
        temp.clear();
        temp["PD_Kp"] = s_Kp;
        KonfiguracjaZapis.update(temp, true);
    }
    if (KonfiguracjaZapis.contains("PD_Td")) {
        KonfiguracjaZapis.at("PD_Td") = s_Td;
    }
    else {
        temp.clear();
        temp["PD_Td"] = s_Td;
        KonfiguracjaZapis.update(temp, true);
    }
    if (KonfiguracjaZapis.contains("PD_Tp")) {
        KonfiguracjaZapis.at("PD_Tp") = s_Tp;
    }
    else {
        temp.clear();
        temp["PD_Tp"] = s_Tp;
        KonfiguracjaZapis.update(temp, true);
    }
    if (KonfiguracjaZapis.contains("PD_WartZad")) {
        KonfiguracjaZapis.at("PD_WartZad") = s_WartZad;
    }
    else {
        temp.clear();
        temp["PD_WartZad"] = s_WartZad;
        KonfiguracjaZapis.update(temp, true);
    }
    strumienZapis << std::setw(4) << KonfiguracjaZapis << std::endl;
    return strumienZapis;
}

/**
 * Odczyt konfiguracji z pliku (Wzmocnienie regulatora, Stała czasowa różniczkowania, Okres próbkowana, Wartość zadana).
 * @param strumien referencja do strumienia
 * @return referencja do strumienia
 */

std::fstream& PD::OdczytKonfiguracji(std::fstream& strumien) {
    json KonfiguracjaOdczyt = json::parse(strumien);
    KonfiguracjaOdczyt.at("PD_Kp").get_to(s_Kp);
    KonfiguracjaOdczyt.at("PD_Td").get_to(s_Td);
    KonfiguracjaOdczyt.at("PD_Tp").get_to(s_Tp);
    KonfiguracjaOdczyt.at("PD_WartZad").get_to(s_WartZad);
    return strumien;
}


