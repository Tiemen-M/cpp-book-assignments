// Created by Tiemen Molenaar in 2023
// Voorbeeld 17.9 Invoer 4 getallen (zonder controle)
#include <iostream>
#include <vector>
using namespace std;

namespace vb_9 {
	void leesIn(vector<int>& v, int nr);
}
using namespace vb_9;

void main_vb_9() {
	vector<int> vec;
	int nr = 0;
	do {
		leesIn(vec, nr + 1);
		++nr;
	} while (nr < 4);

	cout << "De ingevoerdse getallen zijn:" << endl;
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
}

void vb_9::leesIn(vector<int>& v, int nr) {
	cout << "Voer " << nr << "e getal in (tussen 1 en 10):" << endl;
	int getal;
	cin >> getal;
	cin.get();
	v.push_back(getal);
}