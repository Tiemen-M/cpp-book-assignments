// Created by Tiemen Molenaar in 2023
// Voorbeeld 17.10 Invoer 4 getallen tussen 1 en 10
#include <iostream>
#include <vector>
using namespace std;

namespace vb_10 {
	void leesIn(vector<int>& v, int nr) throw(int);
}
using namespace vb_10;

void main_vb_10() {
	vector<int> vec;
	int nr = 0;
	do {
		try {
			leesIn(vec, nr + 1);
			++nr;
		}
		catch (int) {
			cerr << "Ongeldig getal, probeer opnieuw." << endl;
		}
	} while (nr < 4);

	cout << "De ingevoerdse getallen zijn:" << endl;
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
}

void vb_10::leesIn(vector<int>& v, int nr) throw(int) {
	cout << "Voer " << nr << "e getal in (tussen 1 en 10):" << endl;
	int getal;
	cin >> getal;
	cin.clear(); // I added this to prevent forever loop when user enter non numeric values
	cin.get();
	if (getal < 1 || getal > 10)
		throw int();
	v.push_back(getal);
}