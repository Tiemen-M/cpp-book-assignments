// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.2 Algoritme zoek() voor een vector
#include <iostream>
#include <vector>
using namespace std;

namespace vb_2 {
	vector<int>::iterator zoek4(
		vector<int>::iterator first,
		vector<int>::iterator last,
		int i)
	{
		vector<int>::iterator pos = first;
		while (pos != last && *pos != i) ++pos;
		return pos;
	}
}

using namespace vb_2;

void main_vb_2() {
	vector<int> v;
	for (int i = 1; i < 10; ++i)
		v.push_back(i * 3);

	vector<int>::iterator pos15 = zoek4(v.begin(), v.end(), 15);

	if (pos15 != v.end())
		*pos15 = 9999999;

	vector<int>::iterator pos, einde = v.end();
	for (pos = v.begin(); pos != einde; ++pos)
		cout << *pos << endl;
}