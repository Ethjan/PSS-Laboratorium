#pragma once
#include "SISO.h"
#include <vector>
#include <random>
#include <deque>
#include <iostream>

/** @class ARX
 * Klasa modelująca obiekt typu %ARX. Umożliwia obliczenie wyjścia na podstawie zadanych parametrów modelu oraz zadanego wyjścia.
 */
class ARX : public SISO {
private:
    /// Zmienna przechowująca opóźnienie obiektu
    unsigned int s_k;
    /// Zmienna przechowująca wariancję zakłócenia
    double s_var;
    /// Zmienne przechowujące współczynniki wielomianu A
    std::vector<double> s_A;
    /// Zmienne przechowujące współczynniki wielomianu B
    std::vector<double> s_B;
    /// Zmienna przechowująca poprzednie wartości wejścia obiektu
    std::deque<double> s_u;
    /// Zmienna przechowująca poprzednie wartości  wyjścia obiektu
    std::deque<double> s_y;
    /// Zmienna przechowująca silnik generatora
    std::default_random_engine s_generator;
    /// Zmienna przechowująca dystybucje
    std::normal_distribution<double> s_dystrybucja;
public:   
    /**  Konstruktor
    * @brief W przypadku nie zdefiniowania przez użytkownika parametrów obiektu, przyjmowany jest przykladowy model.
    */
    ARX(std::vector<double> A = { -0.5 }, std::vector<double> B = { 1 }, unsigned int nk = 1, double var = 0.0) :
        s_A(A), s_B(B), s_k(nk), s_var(var), s_y(std::deque<double>(1, 0)), s_u(std::deque<double>(1, 0)), s_generator(std::random_device{}()), s_dystrybucja(0.0, 0.01) {
        if (s_var != 0.0) {
            std::normal_distribution<double> s_dystrybucja(0.0, sqrt(s_var));
        }   
        // Dopisanie odpowiedniej ilości zer do wielomianu B związanych z opoznieniem
        for (unsigned int i = 0; i < s_k; i++) {
            s_B.insert(s_B.begin() + i, 0);
        }
        s_y = (std::deque<double>(s_A.size(), 0));
        s_u = (std::deque<double>(s_B.size(), 0));
    };

    ///Metoda symulujaca obiekt. Jako argument przyjmuje wejscie obiektu oraz zwraca obliczone wyjscie obiektu.
    double symuluj(double we) override;
    ///Metoda wypisujaca parametry modelu. Jako argument przyjmuje referencje do strumienia oraz zwraca referecje do strumienia.
    std::ostream& WypiszParametry(std::ostream& strumien);
    ///Metoda zapisujaca parametry modelu w pliku. Jako argumenty przyjmuje referencje do strumieni do odczytu i zapisu oraz zwraca referecje do strumienia do zapisu.
    std::fstream& ZapisKonfiguracji(std::fstream& strumienOdczyt, std::fstream& strumienZapis);
    ///Metoda odczytyjaca parametry modelu z pliku. Jako argument przyjmuje referencje do strumienia oraz zwraca referecje do strumienia.
    std::fstream& OdczytKonfiguracji(std::fstream& strumien);
};