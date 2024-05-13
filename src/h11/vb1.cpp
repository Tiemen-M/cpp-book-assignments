// Created by Tiemen Molenaar in 2023
// Voorbeeld 11.1 Basisklase Rechthoek
#include <iostream>
using namespace std;

namespace vb_1 {
	class Rechthoek {
	private:
		int hoogte;
		int breedte;
	public:
		Rechthoek(int h = 1, int b = 1);
		void print();
		friend ostream& operator<<(ostream& uit, const Rechthoek& x);
	};
}

using namespace vb_1;

void main_vb_1() {
	Rechthoek r(5, 8);
	r.print();
}

// Implementatie lidfuncties van Rechthoek
Rechthoek::Rechthoek(int h, int b)
	: hoogte(h), breedte(b) {
}

ostream& vb_1::operator<<(ostream& uit, const Rechthoek& x) {
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