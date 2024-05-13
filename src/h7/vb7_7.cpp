// Created by Tiemen Molenaar in 2023
// voorbeeld 7.7 omzetten naar hoofdletters
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void naarHoofdletters(string& s);

void main_7_7() {
	string tekst = "Olympische Spelen 2008";

	cout << tekst << endl;
	naarHoofdletters(tekst);
	cout << tekst << endl;
}

void naarHoofdletters(string& s) {
	string::iterator pos;
	for (pos = s.begin(); pos != s.end(); ++pos) {
		*pos = toupper(*pos);
	}
}