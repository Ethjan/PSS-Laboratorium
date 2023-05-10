#include "PID.h"
#include <fstream>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;
/**
 * Obliczenie nowego sterowania na podstawie zadanych nastaw regulatora oraz wejścia regulatora.
 * @param we wejście regulatora
 * @return obliczone wyjście regulatora
 */
double PID::symuluj(double we) {
	double sterowanie;
	PI::s_e = PI::s_WartZad - we;
	//obliczenie sterowania
	//sterowanie = PI::s_Kp * PI::s_e + PI::s_eSum / PI::s_Ti + (PI::s_e - PD::s_ePoprzedni) / PD::s_Td;
    sterowanie = PI::obliczP() + PI::obliczI() + PD::obliczD();
	//antywindup oraz ograniczenie sterowania
	if (sterowanie < 100 && sterowanie > 0)
        PI::s_eSum = PI::s_eSum + PI::s_e * PI::s_Tp;
	else if (sterowanie > 100)
		sterowanie = 100;
	else if (sterowanie < 0)
		sterowanie = 0;
	return sterowanie;
}
/**
 * Zmiana wartości zadanej.
 * @param WartZad nowa wartość zadana.
 */
void PID::zmianaWartZad(double WartZad) {
    PI::s_WartZad = WartZad;
}
/**
 * Zapis konfiguracji do pliku (Wzmocnienie regulatora, Stała czasowa całkowania, Stała czasowa różniczkowania, Okres próbkowana, Wartość zadana).
 * @param strumienOdczyt referencja do strumienia do odczytu.
 * @param strumienZapis referencja do strumienia do zapisu.
 * @return referencja do strumienia
 */
std::fstream& PID::ZapisKonfiguracji(std::fstream& strumienOdczyt, std::fstream& strumienZapis) {
    json KonfiguracjaZapis = json::parse(strumienOdczyt);
    json temp;
    // Sprawdzenie czy podany klucz istnieje. Jeżeli tak, to nadpisz. Jeżeli nie, to utwórz
    if (KonfiguracjaZapis.contains("PID_Kp")) {
        KonfiguracjaZapis.at("PID_Kp") = PI::s_Kp;
    }
    else {
        temp.clear();
        temp["PID_Kp"] = PI::s_Kp;
        KonfiguracjaZapis.update(temp, true);
    }
    if (KonfiguracjaZapis.contains("PID_Ti")) {
        KonfiguracjaZapis.at("PID_Ti") = PI::s_Ti;
    }
    else {
        temp.clear();
        temp["PID_Ti"] = PI::s_Ti;
        KonfiguracjaZapis.update(temp, true);
    }
    if (KonfiguracjaZapis.contains("PID_Td")) {
        KonfiguracjaZapis.at("PID_Td") = PD::s_Td;
    }
    else {
        temp.clear();
        temp["PID_Td"] = PD::s_Td;
        KonfiguracjaZapis.update(temp, true);
    }
    if (KonfiguracjaZapis.contains("PID_Tp")) {
        KonfiguracjaZapis.at("PID_Tp") = PI::s_Tp;
    }
    else {
        temp.clear();
        temp["PID_Tp"] = PI::s_Tp;
        KonfiguracjaZapis.update(temp, true);
    }
    if (KonfiguracjaZapis.contains("PID_WartZad")) {
        KonfiguracjaZapis.at("PID_WartZad") = PI::s_WartZad;
    }
    else {
        temp.clear();
        temp["PID_WartZad"] = PI::s_WartZad;
        KonfiguracjaZapis.update(temp, true);
    }
    strumienZapis << std::setw(4) << KonfiguracjaZapis << std::endl;
    return strumienZapis;
}

/**
 * Odczyt konfiguracji z pliku Wzmocnienie regulatora, Stała czasowa całkowania, Stała czasowa różniczkowania, Okres próbkowana, Wartość zadana).
 * @param strumien referencja do strumienia
 * @return referencja do strumienia
 */
std::fstream& PID::OdczytKonfiguracji(std::fstream& strumien) {
    json KonfiguracjaOdczyt = json::parse(strumien);
    KonfiguracjaOdczyt.at("PID_Kp").get_to(PI::s_Kp);
    KonfiguracjaOdczyt.at("PID_Ti").get_to(PI::s_Ti);
    KonfiguracjaOdczyt.at("PID_Td").get_to(PD::s_Td);
    KonfiguracjaOdczyt.at("PID_Tp").get_to(PI::s_Tp);
    KonfiguracjaOdczyt.at("PID_WartZad").get_to(PI::s_WartZad);
    return strumien;
}
