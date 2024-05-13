// Created by Tiemen Molenaar in 2023
// Voorbeeld 15.3 Rechthoek en Driehoek
#include <iostream>
using namespace std;

namespace vb_3 {
	class Figuur {
	protected:
		char symbool;
	public:
		Figuur(char symbool = '*')
			: symbool(symbool) {
		}

		void setSymbool(char sym) {
			symbool = sym;
		}
	};

	class Rechthoek : public Figuur {
	private:
		int breedte, hoogte;
	public:
		Rechthoek(int breedte, int hoogte)
			: breedte(breedte), hoogte(hoogte) {
		}
		void teken() const;
	};

	class Driehoek : public Figuur {
	private:
		int grote;
	public:
		Driehoek(int grote)
			: grote(grote) {
		}
		void teken() const;
	};
}

using namespace vb_3;

void main_vb_3() {
	Rechthoek rh(14, 4);
	rh.teken();
	cout << endl << endl;

	Driehoek dh(7);
	dh.setSymbool('#');
	dh.teken();
}

// Implementatie
void Rechthoek::teken() const {
	string regel;
	for (int k = 0; k < breedte; ++k) {
		regel += symbool;
		regel += ' ';
	}
	for (int r = 0; r < hoogte; ++r)
		cout << regel << endl;
}

void Driehoek::teken() const {
	string regel;
	for (int k = 0; k < grote; ++k)
		regel += ' ';
	regel += symbool;
	regel += ' ';
	for (int r = 0; r < grote; ++r) {
		cout << regel << endl;
		regel.erase(0, 1);
		regel += symbool;
		regel += ' ';
	}
}