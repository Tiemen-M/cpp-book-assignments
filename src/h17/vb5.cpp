// Created by Tiemen Molenaar in 2023
// Voorbeeld 17.5 Re-throw
#include <iostream>
using namespace std;

namespace vb_5 {
	void functie1();
	void functie2();
}
using namespace vb_5;

void main_vb_5() {
	try {
		functie1();
	}
	catch (string s) {
		cerr << "In main() gevangen: ";
		cerr << s << endl;
	}
	cin.get();
}

void vb_5::functie1() {
	try {
		functie2();
	}
	catch (string s) {
		cerr << "In functie1() gevangen: ";
		cerr << s << endl;
		throw;
	}
}

void vb_5::functie2() {
	throw string("In functie2 gegooid.");
}