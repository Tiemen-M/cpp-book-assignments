// Created by Tiemen Molenaar in 2023
#include <iostream>
using namespace std;

namespace oef_1 {
	class Voertuig {
	protected:
		int aantalWielen;
	public:
		Voertuig();
		Voertuig(int aantalWielen);
		void print() const;
	};

	class Fiets : public Voertuig {
	private:
		int framenummer;
	public:
		Fiets();
		Fiets(int framenummer);
		void print() const;
	};
}

using namespace oef_1;

void main_oef_1() {
	Voertuig voertuig;
	voertuig.print();
	cout << endl;

	Fiets fiets(1234);
	fiets.print();
}

// Implementatie klasse Voertuig
Voertuig::Voertuig()
	: aantalWielen(4) {
}

Voertuig::Voertuig(int aantalWielen)
	: aantalWielen(aantalWielen) {
}

void Voertuig::print() const {
	cout << "Het voertuig heeft " << aantalWielen << " wielen." << endl;
}

// Implementatie klasse Fiets
Fiets::Fiets()
	: Voertuig(2), framenummer(0) {
}

Fiets::Fiets(int framenummer)
	: Voertuig(2), framenummer(framenummer) {
}

void Fiets::print() const {
	Voertuig::print();
	cout << "Dus is het een fiets." << endl;
	cout << "Verder heeft deze fiets de framenummer: " << framenummer << endl;
}