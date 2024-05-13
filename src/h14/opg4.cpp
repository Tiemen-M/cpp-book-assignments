// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 14.12.4
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>
using namespace std;

namespace opg_4 {
	void genereerCijferlijst(int aantal, const string& bestandsnaam) {
		ofstream uit(bestandsnaam);

		default_random_engine engine;
		uniform_int_distribution<int> cijfer(1, 10);
		for (int i = 0; i < aantal; ++i) {
			uit << cijfer(engine) << " ";
		}

		uit.close();
	}

	void print(int x) {
		cout << x << ' ';
	}

	template<typename InputIterator, typename Target>
	int tel(InputIterator first, InputIterator last, Target target) {
		int count = 0;
		for (InputIterator pos = first; pos != last; ++pos) {
			if (*pos == target)
				count++;
		}
		return count;
	}
}

using namespace opg_4;

void main_opg_4() {
	genereerCijferlijst(30, "cijferlijst_l1.txt");
	genereerCijferlijst(25, "cijderlijst_l2.txt");

	// lees de cijferlijst van l1 in
	ifstream inl1("cijferlijst_l1.txt");
	vector<int> l1;
	copy(istream_iterator<int>(inl1), istream_iterator<int>(), back_inserter(l1));
	inl1.close();

	// print de cijfers van l1
	cout << "De cijfers van klas l1 zijn:" << endl;
	for_each(l1.begin(), l1.end(), print);
	cout << endl;

	// lees de cijferlijst van l2 in
	ifstream inl2("cijderlijst_l2.txt");
	vector<int> l2;
	copy(istream_iterator<int>(inl2), istream_iterator<int>(), back_inserter(l2));
	inl2.close();

	// print de cijfers van l2
	cout << "De cijders van klas l2 zijn:" << endl;
	for_each(l2.begin(), l2.end(), print);
	cout << endl;

	// Voeg vector l1 en l2 samen in een nieuwe vector
	vector<int> samen;
	copy(l1.begin(), l1.end(), back_inserter(samen));
	copy(l2.begin(), l2.end(), back_inserter(samen));

	// Maak een overzicht over heo vakk elke cijfer voorkomt
	for (int cijfer = 10; cijfer >= 1; --cijfer) {
		cout << "Cijfer " << setw(3) << cijfer << " komt "
			<< setw(4) << tel(samen.begin(), samen.end(), cijfer)
			<< " keer voor." << endl;
	}
}