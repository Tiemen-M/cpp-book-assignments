// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.6 Inlezen van strings met getline()
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main_vb_6() {
	ifstream invoer("bestand2.txt");
	string s;
	for (int i = 0; i < 3; ++i) {
		getline(invoer, s);
		cout << s << endl;
	}
	invoer.close();
}