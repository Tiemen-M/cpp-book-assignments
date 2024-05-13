// Created by Tiemen Molenaar in 2023
// Uitwerking vraag 16.13.3 : programma die alfabet naar alfabet.txt schrijft
#include <iostream>
#include <fstream>
using namespace std;

void main_vr_3() {
	ofstream alfabet("alfabet.txt");
	
	// alfabet stream writable?
	if (!alfabet) {
		cerr << "Kan bestand alfabet.txt niet openen" << endl;
		exit(1);
	}
	
	char karakter = 'A';
	while (karakter <= 'Z')
		alfabet << karakter++;
	alfabet << endl;
	alfabet.close();

	cout << "Bestand alfabet.txt is met success gemaakt." << endl;
}