// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.3 Inlezen van een bestand
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main_vb_3() {
	ifstream invoer("bestand1.txt");
	string s;
	char c;
	int i;
	double d;

	getline(invoer, s);
	invoer >> c;
	invoer >> i;
	invoer >> d;

	cout << s << endl
		<< c << endl
		<< i << endl
		<< d << endl;
	invoer.close();
}