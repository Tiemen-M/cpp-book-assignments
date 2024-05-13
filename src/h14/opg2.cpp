// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 14.12.2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace opg_2 {
	class IsEven {
	private:
		bool searchForEven;
	public:
		IsEven(bool searchForEven)
			: searchForEven(searchForEven) {
		}

		bool operator()(int x) {
			bool even = ((x % 2) == 0);
			return searchForEven ? even : !even;
		}
	};

	void print(int x) {
		cout << x << " ";
	}
}

using namespace opg_2;

void main_opg_2() {
	int rij[] = { 3,7,11,13,15,23,24,35,40,63,121,132,144 };
	vector<int> v(rij, rij + sizeof(rij) / sizeof(int));
	vector<int> vEven,vOneven, vTest;

	vector<int>::iterator pos = v.begin();
	do {
		pos = find_if(pos, v.end(), IsEven(true));
		if (pos != v.end()) {
			vEven.push_back(*pos);
			++pos;
		}
	} while (pos != v.end());

	pos = v.begin();
	do {
		pos = find_if(pos, v.end(), IsEven(false));
		if (pos != v.end()) {
			vOneven.push_back(*pos);
			++pos;
		}
	} while (pos != v.end());

	for_each(v.begin(), v.end(), print);
	cout << endl;

	for_each(vEven.begin(), vEven.end(), print);
	cout << endl;

	for_each(vOneven.begin(), vOneven.end(), print);
	cout << endl;
}