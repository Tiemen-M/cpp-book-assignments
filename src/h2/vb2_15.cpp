// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <bitset>

using namespace std;

void vb2_15main() {
	int teller = 3, noemer = 4;
	double uitkomst1, uitkomst2;

	// integer deling
	uitkomst1 = teller / noemer;

	// gewone deling
	uitkomst2 = static_cast<double>(teller) / noemer;

	cout << "Zonder static cast: " << uitkomst1 << endl;
	cout << "Met static cast: " << uitkomst2 << endl;

	cout << "0b111 is het zelfde als " << bitset<4>("0111").to_ulong() << endl;
	cout << "ox11 is het zelfde als " << 0x11 << endl;
}