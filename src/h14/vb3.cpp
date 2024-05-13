// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.3 Algoritme zoek() met template-argumenten
#include <iostream>
#include <vector>
using namespace std;

namespace vb_3 {
	template<typename Iterator, typename T>
	Iterator zoek5(Iterator first, Iterator last, T waarde) {
		Iterator pos = first;
		while (pos != last && *pos != waarde) ++pos;
		return pos;
	}
}

using namespace vb_3;

void main_vb_3() {
	// string
	string naam = "Tiemen M";
	char letter = 'n';

	string::iterator pos1 = zoek5(naam.begin(), naam.end(), letter);
	if (pos1 != naam.end())
		cout << "Letter " << *pos1 << " zit in " << naam << endl;
	else
		cout << "De " << letter << " komt niet voor in " << naam << endl;

	// vector
	vector<int> v;
	for (int i = 1; i < 10; ++i)
		v.push_back(i * 3);

	vector<int>::iterator pos15 = zoek5(v.begin(), v.end(), 15);

	if (pos15 != v.end())
		*pos15 = 9999999;

	vector<int>::iterator pos, einde = v.end();
	for (pos = v.begin(); pos != einde; ++pos)
		cout << *pos << endl;
}