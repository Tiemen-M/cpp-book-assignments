// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.5 for_each()
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace vb_5 {
	void print(int x) {
		cout << x << ' ';
	}

	void maakNegatief(int& x) {
		x = -x;
	}

	void kwadrateer(int& x) {
		x *= x;
	}
}

using namespace vb_5;

void main_vb_5() {
	vector<int> v;
	for (int i = 1; i <= 10; ++i)
		v.push_back(i);
	
	for_each(v.begin(), v.end(), print);
	cout << endl;

	for_each(v.begin(), v.end(), maakNegatief);
	cout << endl;

	for_each(v.begin(), v.end(), print);
	cout << endl;

	for_each(v.begin(), v.end(), kwadrateer);
	cout << endl;

	for_each(v.begin(), v.end(), print);
	cout << endl;
}