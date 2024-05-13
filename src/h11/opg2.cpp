// Created by Tiemen Molenaar in 2023
// Voorbeeld 11.1 Basisklase Rechthoek
#include <iostream>
#include <sstream>
using namespace std;

namespace opg_2 {
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

	class Venster : virtual public Rechthoek {
	public:
		Venster(int h = 1, int b = 1);
		void print(bool) const;
	};

	class VensterMetTitel : virtual public Venster {
	private:
		string titel;
	public:
		VensterMetTitel(int h, int b, const string& titel);
		void print() const;
	};

	class FlexRechthoek : virtual public Venster {
	public:
		FlexRechthoek() {}
		void breder();
		void hoger();
	};

	class FlexVensterMetTitel : public VensterMetTitel, public FlexRechthoek {
	public:
		FlexVensterMetTitel(int h, int b, string titel);
		void print() const;
	};
}

using namespace opg_2;

void main_opg_2() {
	FlexVensterMetTitel v(5, 4, "windowa");
	v.print();
	v.breder();
	v.breder();
	v.hoger();
	v.print();
}

// Implementatie lidfuncties van Rechthoek
Rechthoek::Rechthoek(int h, int b)
	: hoogte(h), breedte(b) {
}

ostream& opg_2::operator<<(ostream& uit, const Rechthoek& x) {
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

// Implementatie Venster
Venster::Venster(int h, int b)
	: Rechthoek(h, b) {}

void Venster::print(bool noTop=false) const {
	ostringstream uit;
	for (int r = (noTop) ? 1 : 0; r < hoogte; r++) {
		for (int k = 0; k < breedte; k++) {
			// Als we niet bij de randen zijn
			if (r != 0 && k != 0 && r != hoogte - 1 && k != breedte - 1)
				// teken geen ster
				uit << "  ";
			// anders wel
			else
				uit << "* ";
		}
		uit << endl;
	}
	cout << uit.str();
}

// Implementatie Venster met titel
VensterMetTitel::VensterMetTitel(int h, int b,const string& titel)
	: Venster(h,b), titel(titel) {
}

void VensterMetTitel::print() const {
	cout << "*";
	cout << titel.substr(0, breedte);
	if (titel.length() % 2 != 0)
		cout << " ";
	int space_left = breedte - titel.length() / 2 - 2;
	while (space_left > 0) {
		cout << "  ";
		space_left--;
	}
	cout << "*" << endl;
	Venster::print(true);
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

// Implementatie klasse FlexVensterMetTitel
FlexVensterMetTitel::FlexVensterMetTitel(int h, int b,string titel)
	: VensterMetTitel(h,b,titel) {
}

void FlexVensterMetTitel::print() const {
	VensterMetTitel::print();
}