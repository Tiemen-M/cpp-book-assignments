// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.13 Schrijven van een object naar een binair bestand
// Let op: Werk alleen als object geen dynamisch geheugen gebruikt
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "vb13.h"
using namespace vb_13;

void main_vb_13() {
	string filename = "bestand5.dat";
	Punt A, B(2, 3), C(17, 21);
	ofstream bestand(filename.c_str(), ios::binary);

	bestand.write(reinterpret_cast<char*>(&A), sizeof(Punt));
	bestand.write(reinterpret_cast<char*>(&B), sizeof(Punt));
	bestand.write(reinterpret_cast<char*>(&C), sizeof(Punt));

	bestand.close();

	cout << "Binair bestand " << filename << " is geschreven." << endl;
}

// Implementatie van klasse Punt
Punt::Punt(int x, int y)
	: x(x), y(y) {
}

ostream& vb_13::operator<<(ostream& uit, const Punt& p) {
	return uit << '(' << p.x << ',' << p.y << ')';
}