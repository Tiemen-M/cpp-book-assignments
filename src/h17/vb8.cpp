// Created by Tiemen Molenaar in 2023
// Voorbeeld 17.8 Zelf een standaardexceptie opwerpen
#include <iostream>
#include <stdexcept>
using namespace std;

namespace vb_8 {
	// Prototype
	double deel(int teller, int noemer);
}
using namespace vb_8;

void main_vb_8() {
	double resultaat;
	try {
		resultaat = deel(3, 8);
		cout << "3/8 = " << resultaat << endl;

		resultaat = deel(5, 0);
		cout << "5/0 = " << resultaat << endl;
	}
	catch (exception& exc) {
		cerr << exc.what();
	}
}

// Implementatie
double vb_8::deel(int teller, int noemer) {
	if (noemer == 0)
		throw logic_error("Deel nou niet door nul!");
	return static_cast<double>(teller) / noemer;
}