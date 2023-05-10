#include "PI.h"
#include <fstream>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;
/**
 * Obliczenie nowego sterowania na podstawie zadanych nastaw regulatora oraz wejścia regulatora.
 * @param we wejście regulatora
 * @return obliczone wyjście regulatora
 */
double PI::symuluj(double we) {
	double sterowanie;
	s_e = s_WartZad - we;
	//obliczenie sterowania
	sterowanie = s_Kp * s_e + s_eSum / s_Ti;
	//antywindup oraz ograniczenie sterowania
	if (sterowanie < 100 && sterowanie > 0)
		s_eSum = s_eSum + s_e * s_Tp;
	else if (sterowanie > 100)
		sterowanie = 100;
	else if (sterowanie < 0)
		sterowanie = 0;

	return sterowanie;
}

/**
 * Zapis konfiguracji do pliku (Wzmocnienie regulatora, Stała czasowa całkowania, Okres próbkowana, Wartość zadana).
 * @param strumienOdczyt referencja do strumienia do odczytu.
 * @param strumienZapis referencja do strumienia do zapisu.
 * @return referencja do strumienia
 */
std::fstream& PI::ZapisKonfiguracji(std::fstream& strumienOdczyt, std::fstream& strumienZapis) {
    json KonfiguracjaZapis = json::parse(strumienOdczyt);
    json temp;
    // Sprawdzenie czy podany klucz istnieje. Jeżeli tak, to nadpisz. Jeżeli nie, to utwórz
    if (KonfiguracjaZapis.contains("PI_Kp")) {
        KonfiguracjaZapis.at("PI_Kp") = s_Kp;
    }
    else {
        temp.clear();
        temp["PI_Kp"] = s_Kp;
        KonfiguracjaZapis.update(temp, true);
    }
    if (KonfiguracjaZapis.contains("PI_Ti")) {
        KonfiguracjaZapis.at("PI_Ti") = s_Ti;
    }
    else {
        temp.clear();
        temp["PI_Ti"] = s_Ti;
        KonfiguracjaZapis.update(temp, true);
    }
    if (KonfiguracjaZapis.contains("PI_Tp")) {
        KonfiguracjaZapis.at("PI_Tp") = s_Tp;
    }
    else {
        temp.clear();
        temp["PI_Tp"] = s_Tp;
        KonfiguracjaZapis.update(temp, true);
    }
    if (KonfiguracjaZapis.contains("PI_WartZad")) {
        KonfiguracjaZapis.at("PI_WartZad") = s_WartZad;
    }
    else {
        temp.clear();
        temp["PI_WartZad"] = s_WartZad;
        KonfiguracjaZapis.update(temp, true);
    }
    strumienZapis << std::setw(4) << KonfiguracjaZapis << std::endl;
    return strumienZapis;
}

/**
 * Odczyt konfiguracji z pliku (Wzmocnienie regulatora, Stała czasowa całkowania, Okres próbkowana, Wartość zadana).
 * @param strumien referencja do strumienia
 * @return referencja do strumienia
 */
std::fstream& PI::OdczytKonfiguracji(std::fstream& strumien) {
    json KonfiguracjaOdczyt = json::parse(strumien);
    KonfiguracjaOdczyt.at("PI_Kp").get_to(s_Kp);
    KonfiguracjaOdczyt.at("PI_Ti").get_to(s_Ti);
    KonfiguracjaOdczyt.at("PI_Tp").get_to(s_Tp);
    KonfiguracjaOdczyt.at("PI_WartZad").get_to(s_WartZad);
    return strumien;
}

