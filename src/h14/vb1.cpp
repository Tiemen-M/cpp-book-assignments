// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.1 Eerste versie van algoritme zoek()
#include <iostream>
#include <string>
using namespace std;

namespace vb_1 {
	string::iterator zoek1(string& s, char ch) {
		string::iterator pos = s.begin(), einde = s.end();
		while (pos != einde && *pos != ch)
			++pos;
		return pos;
	}

	string::const_iterator zoek2(const string& s, char ch) {
		string::const_iterator pos = s.begin(), einde = s.end();
		while (pos != einde && *pos != ch)
			++pos;
		return pos;
	}

	string::iterator zoek3(string::iterator first, string::iterator last, char ch) {
		string::iterator pos = first;
		while (pos != last && *pos != ch) ++pos;
		return pos;
	}
}

using namespace vb_1;

void main_vb_1() {
	string naam = "Alexander";
	char letter = 'y';

	string::iterator pos1 = zoek1(naam, letter);
	if (pos1 != naam.end())
		cout << "Letter " << letter << " zit in " << naam;
	else
		cout << "De " << letter << " komt niet in " << naam;
	cout << endl;

	string::const_iterator pos2 = zoek2(naam, letter);
	if (pos2 != naam.end())
		cout << "Letter " << letter << " zit in " << naam;
	else
		cout << "De " << letter << " komt niet in " << naam;
	cout << endl;

	string::iterator pos3 = zoek3(naam.begin(), naam.end(), letter);
	if (pos3 != naam.end())
		cout << "Letter " << letter << " zit in " << naam;
	else
		cout << "De " << letter << " komt niet in " << naam;
	cout << endl;
}