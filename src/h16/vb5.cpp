// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.5 Inlezen van strings met de extraction-operator >>
#include <iostream>
#include <fstream>
using namespace std;

void main_vb_5() {
	ifstream invoer("bestand2.txt");
	string s1, s2, s3;
	invoer >> s1;
	invoer >> s2;
	invoer >> s3;

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	invoer.close();
}
