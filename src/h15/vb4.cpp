// Created by Tiemen Molenaar in 2023
// Voorbeeld 15.4 Polymorfisme met Rechthoek en Driehoek
#include <iostream>
using namespace std;


#include "vb4.h"
using namespace vb_4;

void main_vb_4() {
	Figuur* fig[3];

	fig[0] = new Driehoek(3);
	fig[1] = new Rechthoek(10, 4);
	fig[1]->setSymbool('@');
	fig[2] = new Driehoek(6);
	fig[2]->setSymbool('T');

	for (int i = 0; i < 3; ++i) {
		fig[i]->teken();
		cout << endl;
	}
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