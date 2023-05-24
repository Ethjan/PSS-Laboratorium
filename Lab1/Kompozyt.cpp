#include "Kompozyt.h"

/**
 * Dodawanie obiektów do struktury.
 */
void Kompozyt::Dodaj(KompozytKomponent* komponent) {
	this->s_elementy.push_back(komponent);
	komponent->UstawPodstawe(this);
}

/**
 * Usuwanie obiektów ze struktury.
 */
void Kompozyt::Usun(KompozytKomponent* komponent) {
	s_elementy.remove(komponent);
	komponent->UstawPodstawe(nullptr);
}