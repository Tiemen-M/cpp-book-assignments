// Created by Tiemen Molenaar in 2023
// test1: string stream gebruiken om via >> iets op scherm te drukken
#include <iostream>
#include <sstream>
using namespace std;

void main_test_1() {
	stringstream ss;
	ss.seekp(0);
	ss << "Hallo wereld!!" << endl;

	char ch;
	ss.seekg(0);
	ss >> noskipws;
	while (ss >> ch) {
		cout << ch << endl;
	}
}