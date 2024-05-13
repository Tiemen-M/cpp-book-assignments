// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.9 Functie-object en algoritme
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace vb_9 {
	class MaakNegatief {
	public:
		void operator()(int& x) const {
			x = -x;
		}
	};

	void print(int x) {
		cout << x << ' ';
	}
}

using namespace vb_9;

void main_vb_9() {
	int rij[] = { 2,3,5,7,11,13,17 };
	int rijlengte = sizeof(rij) / sizeof(int);
	vector<int> v(rij, rij + rijlengte);

	for_each(v.begin(), v.end(), print);
	cout << endl;

	// Functie object
	MaakNegatief neg;
	for_each(v.begin(), v.end(), neg);

	for_each(v.begin(), v.end(), print);
	cout << endl;
}