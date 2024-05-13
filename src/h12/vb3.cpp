// Created by Tiemen Molenaar in 2023
#include <iostream>
#include "vb2.h"
using namespace std;
using namespace vb_2;

void main_vb_3() {
	unsigned aantal = 3;

	IntArray ia(aantal); // begin scope ia
	ia.invoer();

	if (aantal > 0) {
		IntArray ib(aantal); // begin scope ib
		ib.invoer();

		cout << "Gemiddelde van ib is "
			<< ib.gemiddelde() << endl; // einde scope ib
	}

	cout << "Gemiddelde van ia is " << ia.gemiddelde() << endl;
	// einde scope ia
}

