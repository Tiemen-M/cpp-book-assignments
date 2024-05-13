// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.16 Kopiëren van een bestand met get() en put()
#include <iostream>
#include <fstream>
using namespace std;

void main_vb_16() {
	ifstream bestand("bestand2.txt", ios::binary);
	ofstream kopie("kopie2.txt", ios::binary);

	kopie << bestand.rdbuf();
	cout << "Kopie is klaar" << endl;
}