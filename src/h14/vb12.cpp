// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.12 Een bestand maken met copy()
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void main_vb_12() {
	vector<int> v;
	for (int i = 1; i < 30; i += 2)
		v.push_back(i);
	ofstream uit("oneven.txt");
	copy(v.begin(), v.end(), ostream_iterator<int>(uit, " "));
	cout << "Bestand is gemaakt." << endl;
	uit.close();
}