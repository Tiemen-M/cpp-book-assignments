// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.8 Testen van stream met behulp van lidfuncties ifstream
#include <iostream>
#include <fstream>
using namespace std;

void main_vb_8() {
	
	// Maak een bestand met wat getallen
	string filename = "bestand3.txt";
	/*
	ofstream uitvoer(filename.c_str());
	for (int i = 1; i < 100; i += 7)
		uitvoer << i * i << endl;

	// Sluit het bestand
	uitvoer.close();
	*/
	// Open het bestand voor invoer
	ifstream invoer(filename.c_str());

	// Ga na of alles in orde is:
	if (invoer.fail()) {
		cerr << "Bestand niet gevonden";
		cin.get();
		exit(1);
	}

	// Lees het eerste getal
	int getal;
	invoer >> getal;
	if (invoer.fail()) {
		cerr << "Verkeerde informatie in het bestand.";
		cin.get();
		exit(2);
	}

	// Lees de volgende getallen
	while (invoer.good()) {
		cout << getal << endl;
		invoer >> getal;
	}
	invoer.close();
}