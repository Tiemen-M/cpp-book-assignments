// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 16.14.4
#include <iostream>
#include <fstream>
#include "opg3.h"
#include <string>
#include <sstream>
using namespace std;
using namespace opg_3;

namespace opg_4 {
	void skip(istream& in) {
		// pre: er is nog iets te lezen in de stream in
		char ch;
		do {
			in >> ch;
		} while (in && !isdigit(ch) && ch != '-');
		if (in)
			in.putback(ch);
	}
}
using namespace opg_4;

void main_opg_4() {
	DatumLijst l;

	// read from file the datums
	ifstream bestand("datums.txt");
	Datum item;
	string line;
	while (getline(bestand, line)) {
		istringstream(line) >> item;
		l.voegtoe(item);
	}
	bestand.close();

	// print the datums
	cout << "Ingeladen datums:" << endl;
	l.print();
}