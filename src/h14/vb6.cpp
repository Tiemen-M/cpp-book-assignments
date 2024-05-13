// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.6 Unair predikaat, het algoritme find_if()
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace vb_6 {
	void print(int x) {
		cout << x << ' ';
	}

	// Unair predikaat
	bool even(int x) {
		return x % 2 == 0;
	}
}

using namespace vb_6;

void main_vb_6() {
	int rij[] = { 3,7,11,13,15,23,24,35,40,63 };
	int rijlengte = sizeof(rij) / sizeof(int);
	vector<int> v(rij, rij + rijlengte);

	for_each(v.begin(), v.end(), print);
	cout << endl;

	vector<int>::iterator pos = find_if(v.begin(), v.end(), even);
	cout << endl;

	if (pos != v.end())
		cout << "Even getal gevonden: " << *pos << endl;
}