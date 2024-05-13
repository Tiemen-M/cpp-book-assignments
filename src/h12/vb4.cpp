// Created by Tiemen Molenaar in 2023
// Voorbeeld 12.4 Exceptie van het type bad_alloc
#include <iostream>
using namespace std;

void main_vb_4() {
	long totaal = 0;
	try {
		while (true) {
			new char[1024 * 1024];
			totaal++;
			cout << totaal << " MB" << endl;
		} 
	}
	catch (bad_alloc) {
		cout << "Geheugen is op!" << endl;
	}
}