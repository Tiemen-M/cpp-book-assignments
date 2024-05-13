// Created by Tiemen Molenaar in 2023
// Voorbeeld 15.6 Polymorfisme via een referentie
#include <iostream>
#include "vb4.h"
using namespace std;
using namespace vb_4;

namespace vb_6 {
	// Functie met een referentie als argument
	void tekenFiguur(const Figuur& f) {
		f.teken();
	}
}

using namespace vb_6;

void main_vb_6() {
	Rechthoek rh(6, 2);
	Driehoek dh(5);
	dh.setSymbool('b');

	tekenFiguur(rh);
	tekenFiguur(dh);
}