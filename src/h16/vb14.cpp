// Created by Tiemen Molenaar in 2023
// Coorbeeld 16.14 Lezen van object uit binair bestand
#include <iostream>
#include <fstream>
#include <string>
#include "vb13.h"
using namespace std;
using namespace vb_13;

void main_vb_14() {
	string filename = "bestand5.dat";
	ifstream bestand(filename.c_str(), ios::binary);

	Punt P, Q, R;

	bestand.read(reinterpret_cast<char*>(&P), sizeof(Punt));
	bestand.read(reinterpret_cast<char*>(&Q), sizeof(Punt));
	bestand.read(reinterpret_cast<char*>(&R), sizeof(Punt));

	cout << filename << " is ingelezen:" << endl;
	cout << P << endl;
	cout << Q << endl;
	cout << R << endl;
}
