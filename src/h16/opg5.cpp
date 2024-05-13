// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 16.14.5 verbeterde DoubleArray uit opgave 5 van hoofstuk 12
// Doel: inhoud van DoubleArray naar bestand schrijven met behulp van een operator<<() functie.
#include <iostream>
#include <fstream>
#include "double_array.h"
using namespace std;
using namespace double_array;

void main_opg_5() {
	// Maak een double array met inhoud
	DoubleArray arr(30);
	double q = 3.14;
	for (int i = 0; i < 30; ++i) {
		arr[i] = q;
		q += 2.34;
	}

	// schrijf het naar een bestand
	ofstream bestand("bestand7.txt");
	if (!bestand) {
		cerr << "Kan bestand niet openen!" << endl;
		exit(1);
	}
	bestand << arr;
	bestand.close();
	cout << "Het bestand is gemaakt." << endl;
}