// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 15.9.1 subklasse Ruit
#include <iostream>
#include <vector>
#include "vb4.h"
using namespace std;
using namespace vb_4;

namespace opg_1 {
	class Ruit : public Figuur {
	private:
		int zijde;
	public:
		Ruit(int zijde = 3)
			: Figuur(), zijde(zijde) {
		}
		void teken() const;
	};

	void tekenHet(const Figuur&);
}

using namespace opg_1;

void main_opg_1() {
	vector<Figuur*> v;
	Figuur* p;

	p = new Ruit;
	v.push_back(p);

	p = new Rechthoek(3,4);
	p->setSymbool('&');
	v.push_back(p);

	p = new Driehoek(10);
	v.push_back(p);

	p = new Ruit(20);
	p->setSymbool('T');
	v.push_back(p);

	vector<Figuur*>::iterator pos, end = v.end();
	for (pos = v.begin(); pos != end; ++pos)
		tekenHet(**pos);

}

// Implementatie
void Ruit::teken() const {
	string regel;
	// make first row
	for (int k = 0; k < zijde - 1; ++k)
		regel += ' ';
	regel += symbool;
	cout << regel << endl;
	// to the mid
	for (int r = 0; r < zijde - 1; ++r) {
		regel.erase(0, 1);
		regel += ' ';
		regel += symbool;
		cout << regel << endl;
	}
	// last
	for (int r = 0; r < zijde - 1; ++r) {
		regel.erase(regel.length()-2, regel.length());
		regel = " " + regel;
		cout << regel << endl;
	}
}

void opg_1::tekenHet(const Figuur& in) {
	cout << endl;
	in.teken();
}