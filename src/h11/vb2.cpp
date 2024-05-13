// Created by Tiemen Molenaar in 2023
// Voorbeeld 11.2 BasiskLasse en afgeleide klasse
#include <iostream>
using namespace std;

namespace vb_2 {
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
	public:
		void breder();
		void hoger();
	};
}

using namespace vb_2;

void main_vb_2() {
	FlexRechthoek fr;
	fr.print();
	
	fr.breder();
	fr.breder();
	fr.hoger();
	cout << endl;
	fr.print();

	cout << endl << fr;
}

// Implementatie lidfuncties van Rechthoek
Rechthoek::Rechthoek(int h, int b)
	: hoogte(h), breedte(b) {
	cout << "default-constructor van basisklasse" << endl;
}

ostream& vb_2::operator<<(ostream& uit, const Rechthoek& x) {
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
void FlexRechthoek::breder() {
	if (breedte < MAX_BREEDTE)
		breedte++;
}

void FlexRechthoek::hoger() {
	if (hoogte < MAX_HOOGTE)
		hoogte++;
}