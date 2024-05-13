// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 16.14.2 : print programma met nummering
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

void main_opg_2() {
	ifstream broncode("opg2.cpp");
	stringstream formateerde_brondcode;

	string line;
	int num = 0;
	while (getline(broncode, line)) {
		formateerde_brondcode << setw(5) << left << ++num
			<< line << endl;
	}

	formateerde_brondcode >> cout.rdbuf();
}