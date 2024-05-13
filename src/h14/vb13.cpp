// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.13 Bestand lezen met copy()
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void main_vb_13() {
	ifstream in("oneven.txt");
	vector<int> v;

	// Lees inhoud en plaats dit in vector v
	copy(istream_iterator<int>(in), istream_iterator<int>(), back_inserter(v));
	in.close();

	// Kopieer inhoud van v naar scherm
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}