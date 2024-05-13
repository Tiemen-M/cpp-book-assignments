// Created by Tiemen Molenaar in 2023
// Voorbeeld 13.11 Template-functie print en vector
#include <iostream>
#include <vector>
using namespace std;

namespace vb_11 {
	// Generieke functie
	template<typename InputIterator>
	void print(string s, InputIterator first, InputIterator last) {
		cout << s << ':' << endl;
		for (InputIterator pos = first; pos != last; ++pos)
			cout << *pos << " ";
		cout << endl << endl;
	}
}

using namespace vb_11;

void main_vb_11() {
	// Lege vector
	vector<int> v;
	// Voeg drie getallen toe aan v
	v.push_back(5);
	v.push_back(1);
	v.push_back(10);

	print("Vector", v.begin(), v.end());
}
