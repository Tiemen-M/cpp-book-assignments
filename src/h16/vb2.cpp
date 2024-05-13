// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.2 Een nieuw bestand maken
#include <iostream>
#include <fstream>
using namespace std;

void main_vb_2() {
	ofstream uitvoer("bestand1.txt");

	char c = 'A';
	int i = 23;
	double d = 1.4142;

	uitvoer << "Een letter en twee getallen:" << endl;
	uitvoer << c << endl;
	uitvoer << i << endl;
	uitvoer << d << endl;
	uitvoer.close();
}