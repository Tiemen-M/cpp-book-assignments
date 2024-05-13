// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.3 Strings schrijven naar een bestand
#include <iostream>
#include <fstream>
using namespace std;

void main_vb_4() {
	ofstream uitvoer("bestand2.txt");
	string s = "Een, twee";

	uitvoer << s << endl;
	uitvoer << "drie, vier," << endl;
	uitvoer << "vijf, zes, zeven, acht." << endl;
	uitvoer.close();
}
