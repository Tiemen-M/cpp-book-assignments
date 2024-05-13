// Created by Tiemen Molenaar in 2023
// Voorbeeld 17.7 Standaardexceptie
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

void main_vb_7() {
	vector<int> v;
	for (int i = 0; i < 5; i++)
		v.push_back(i);

	try {
		cout << v.at(-1) << endl;
	}
	catch (exception& exc) {
		cout << exc.what();
	}
}