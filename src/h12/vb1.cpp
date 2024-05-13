// Created by Tiemen Molenaar in 2023
// Voorbeeld 12.1 Dynamische array
#include <iostream>
using namespace std;

void main_vb_1() {
	cout << "Hoeveel getallen wil je intikken? ";
	int aantal;
	cin >> aantal;

	int* pi;
	pi = new int[aantal]; // vraag dynamsich geheugen aan

	int som = 0;
	for (int nr = 0; nr < aantal; nr++) {
		cout << "Tik het " << (nr + 1) << "e getal in ";
		cin >> pi[nr];
	}
	cin.get();
	for (int nr = 0; nr < aantal; som += pi[nr++]);
	cout << "Het gemiddelde is " << static_cast<double>(som) / aantal;

	delete[] pi;
}