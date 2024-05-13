// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.18 Kopiëren van een bestand naar de printer
#include <iostream>
#include <fstream>
using namespace std;

void main_vb_18() {
	ifstream in("bestand2.txt", ios::binary);
	ofstream printer("PORTPROMPT:test.pdf");

	printer << "Dit is de inhoud van bestand2.txt" << endl;
	printer << in.rdbuf() << endl;
	printer << '\f';			// leeg de printerbuffer
}