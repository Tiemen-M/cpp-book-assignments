// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.7 Controleren van stream op fouten
// met behulp van de naam van de stream
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main_vb_7() {
	string filename = "c:\\autoexec.bat";
	ifstream invoer(filename.c_str());

	if (!invoer) {
		cout << "Bestand " << filename
			<< " kan niet worden geopend"
			<< endl << "Programma gestopt";
		cin.get();
		exit(1);
	}

	string s;
	getline(invoer, s);
	while (invoer) {
		cout << s << endl;
		getline(invoer, s);
	}
	invoer.close();


}