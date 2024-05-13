// Created by Tiemen Molenaar in 2023
// Voorbeeld 11.3 Functie-verriding
#include <iostream>
using namespace std;

namespace vb_3 {
	const int
		MIN_BREEDTE = 1,
		MIN_HOOGTE = 1,
		MAX_BREEDTE = 39,
		MAX_HOOGTE = 24;

	class Rechthoek {
	protected:
		int hoogte;
		int breedte;
	public:
		Rechthoek(int h = MIN_HOOGTE, int b = MIN_BREEDTE);
		void print();
		friend ostream& operator<<(ostream& uit, const Rechthoek& x);
	};

	// afgeleide klasse
	class FlexRechthoek : public Rechthoek {
	private:
		char symbol;
	public:
		FlexRechthoek(int ht, int br, char sym = '*');
		void breder();
		void hoger();
		// technisch gezien is dit functie overloading en geen functie overriding
		friend ostream& operator<<(ostream& uit, const FlexRechthoek& x);
		// Bij de volgende functie is wel sprake van functie overriding
		void print();
	};
}

using namespace vb_3;

// main functie
void main_vb_3() {
	FlexRechthoek fr(2, 3, '#');
	fr.print();

	fr.breder();
	fr.breder();
	fr.hoger();
	cout << endl;
	fr.print();

	cout << endl << "Als je de oude print functie wil gebruiken van de basisklas:" << endl;
	static_cast<Rechthoek>(fr).print();

	cout << endl << "Ik heb ook de operator << overladen dus ik kan het volgende:" << endl;
	cout << "cout << fr << endl;" << endl;
	cout << fr << endl;
}

// Implementatie lidfuncties van Rechthoek
Rechthoek::Rechthoek(int h, int b)
	: hoogte(h), breedte(b) {
	cout << "default-constructor van basisklasse" << endl;
}

ostream& vb_3::operator<<(ostream& uit, const Rechthoek& x) {
	for (int r = 0; r < x.hoogte; r++) {
		for (int k = 0; k < x.breedte; k++) {
			uit << "* ";
		}
		uit << endl;
	}
	return uit;
}

void Rechthoek::print() {
	cout << *this;
}

//Implementatie lidfuncties van FlexRechthoek
FlexRechthoek::FlexRechthoek(int ht, int br, char sym)
	: Rechthoek(ht,br), symbol(sym) {
	cout << "constructor van subklasse FlexRechthoek" << endl;
}

void FlexRechthoek::breder() {
	if (breedte < MAX_BREEDTE)
		breedte++;
}

void FlexRechthoek::hoger() {
	if (hoogte < MAX_HOOGTE)
		hoogte++;
}

ostream& vb_3::operator<<(ostream& uit, const FlexRechthoek& x) {
	for (int r = 0; r < x.hoogte; r++) {
		for (int k = 0; k < x.breedte; k++)
			uit << x.symbol << " ";
		uit << endl;
	}
	return uit;
}

void FlexRechthoek::print() {
	cout << *this;
}