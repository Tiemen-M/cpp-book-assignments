// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 15.9.2
#include <iostream>
#include <list>
#include "vb4.h"
using namespace std;
using namespace vb_4;

namespace opg_2 {
	class OpenRechthoek : public Rechthoek {
	public:
		OpenRechthoek(int breedte, int hoogte)
			: Rechthoek(breedte, hoogte) {
		}
		void teken() const;
	};
}

using namespace opg_2;

void main_opg_2() {
	Figuur* arr[] = { new Driehoek(4), new Rechthoek(5,4), new OpenRechthoek(5,4) };
	list<Figuur*> l(arr, arr + sizeof(arr) / sizeof(Figuur*));

	for (list<Figuur*>::reverse_iterator pos = l.rbegin(); pos != l.rend(); ++pos) {
		(*pos)->teken();
		cout << endl;
		delete* pos;
	}
}

// Implementatie
void OpenRechthoek::teken() const {
	string regel1, regel2;
	for (int k = 0; k < breedte; ++k) {
		regel1 += symbool;
		regel1 += ' ';
		regel2 += (k == 0 || k == breedte - 1) ? symbool : ' ';
		regel2 += ' ';
	}
	for (int r = 0; r < hoogte; ++r) {
		cout << ((r == 0 || r == hoogte - 1) ? regel1 : regel2) << endl;
	}
}