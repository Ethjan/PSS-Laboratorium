#include "DekoratorKonkretnyKomponent.h"

/**
 * Metoda odpowiedzialna za generację stałego sygnału
 * @return Wartość stała zadana przez użytkownika
 */
double DekoratorKonkretnyKomponent::Generuj() {
	return s_wartStala;
}
