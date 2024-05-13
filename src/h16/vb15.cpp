// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.15 Kopiëren van een bestand met get() en put()
#include <iostream>
#include <fstream>
using namespace std;

void main_vb_15() {
	ifstream bestand("bestand1.txt");
	ofstream kopie("kopie1.txt");
	char ch;
	if (bestand && kopie)
		while (bestand.get(ch))
			kopie.put(ch);
	cout << "Kopie is klaar." << endl;
}