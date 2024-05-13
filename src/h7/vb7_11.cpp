// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>&);

void main_7_11() {
	vector<int> v(200,97);

	cout << "Begincapaciteit: " << v.capacity() << endl;
	cout << "Aantal elementen: " << v.size() << endl;

	for (unsigned int i = 0; i < 5; i++)
		v.push_back(2 * i);

	cout << "Inhoud :";
	print(v);

	cout << "Aantal elementen: " << v.size() << endl;
	cout << "Capaciteit is nu: " << v.capacity() << endl;
}