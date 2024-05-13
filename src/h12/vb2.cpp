// Created by Tiemen Molenaar in 2023
// Voorbeeld 12.2 Klasse met dynamische array en destructor
#include <iostream>
#include "vb2.h"
using namespace std;

// see vb2.h

using namespace vb_2;

void main_vb_2() {
	cout << "Hoeveel getallen wil je intikken? ";
	unsigned aantal;
	cin >> aantal;

	IntArray ia(aantal);
	ia.invoer();
	cout << "Het gemiddelde is " << ia.gemiddelde() << endl;
}

// Implementatie van IntArray
IntArray::IntArray(unsigned n)
	: aantal(n) {
	p = new int[aantal];
	for (unsigned i = 0; i < aantal; i++) {
		p[i] = 0;
	}
}

IntArray::~IntArray() {
	cout << "Destructor van IntArray" << endl;
	delete[] p;
	cin.get();
}

void IntArray::invoer() {
	for (unsigned i = 0; i < aantal; i++) {
		cout << "Tik het " << (i + 1) << "e getal in ";
		cin >> p[i];
	}
	cin.get();
}

double IntArray::gemiddelde() const {
	int som = 0;
	for (unsigned i = 0; i < aantal; som += p[i++]);
	return static_cast<double>(som) / aantal;
}