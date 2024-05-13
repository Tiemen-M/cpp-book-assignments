// Created by Tiemen Molenaar in 2023
// Voorbeeld 17.1 Try, throw en catch
#include <iostream>
using namespace std;

namespace vb_1 {
	// Prototype
	double deel(int teller, int noemer);
} 

using namespace vb_1;

void main_vb_1() {
	double resultaat;
	try {
		resultaat = deel(3, 8);
		cout << "3/8 = " << resultaat << endl;
		resultaat = deel(5, 0);
		cout << "5/0 = " << resultaat << endl;
		cout << "Dat was het" << endl;
	}
	catch (int) {
		cerr << "Delen door 0 kan niet." << endl;
	}
}

// Implementatie
double vb_1::deel(int teller, int noemer) {
	if (noemer == 0)
		throw 0;
	return static_cast<double>(teller) / noemer;
}