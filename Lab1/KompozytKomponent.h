#pragma once

/** @class KompozytKomponent
 * Klasa rozdzielająca pracę do podelementów, przetwarzająca pośrednie wyniki oraz zwracająca wynik ostateczny.
 */
class KompozytKomponent {
protected:
	KompozytKomponent* s_podstawa;
public:
	///Destruktor
	~KompozytKomponent() {};
	///Ustawienie elementu.
	void UstawPodstawe(KompozytKomponent* podstawa);
	///Metoda dodająca kolejne obiekty.
	virtual void Dodaj(KompozytKomponent* komponent) {}
	///Metoda usuwająca obiekty.
	virtual void Usun(KompozytKomponent* komponent) {}
	///Metoda symulujaca obiekt. Metoda czysto wirtualna.
	virtual double symuluj(double we) = 0;
};

