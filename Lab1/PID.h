#pragma once
#include "PI.h"
#include "PD.h"
#include <iostream>

/** @class PID
 * Klasa modelująca regulator typu %PID. Umożliwia obliczenie sterowania na podstawie zadanych nastaw oraz wejścia regulatora.
 */
class PID: public PI, public PD{
	public:
		/**  Konstruktor
		* @brief Konstruktor wywolujący kontruktory klasy PI i PD.
		*/
		PID(double Kp = 1, double Ti = 1, double Td = 1, double Tp = 1, double WartZad = 0) : PI(Kp, Ti, Tp, WartZad),PD(Kp, Td){

		};
		
		///Metoda symulujaca regulator. Jako argument przyjmuje wejscie regulatora oraz zwraca obliczone wyjscie regulatora.
		double symuluj(double we) override;
		///Metoda zapisujaca parametry regulatora w pliku. Jako argumenty przyjmuje referencje do strumieni do odczytu i zapisu oraz zwraca referecje do strumienia do zapisu.
		std::fstream& ZapisKonfiguracji(std::fstream& strumienOdczyt, std::fstream& strumienZapis);
		///Metoda odczytyjaca parametry regulatora z pliku. Jako argument przyjmuje referencje do strumienia oraz zwraca referecje do strumienia.
		std::fstream& OdczytKonfiguracji(std::fstream& strumien);

};

