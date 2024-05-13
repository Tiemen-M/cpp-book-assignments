// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.11 De algoritme copy()
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

namespace vb_11 {
	void print(int x) {
		cout << x << ' ';
	}
}

using namespace vb_11;

void main_vb_11() {
	vector<int> van;
	for (int i = 10; i < 20; ++i)
		van.push_back(i);

	// kopieer 5 elementen
	//vector<int> naar(5);
	//copy(van.begin(), van.begin() + 5, naar.begin());
	vector<int> naar;
	copy(van.begin(), van.begin() + 5, back_inserter(naar));

	cout << "Inhoud van kopie: " << endl;
	for_each(naar.begin(), naar.end(), print);

	// front_inserter
	list<int> lijst, lijst2, lijst3;
	copy(van.begin(), van.end(), front_inserter(lijst));
	copy(van.begin(), van.end(), back_inserter(lijst2));
	copy(van.begin(), van.end(), inserter(lijst3, lijst3.begin()));
	cout << endl << "lijst: " << endl;
	for_each(lijst.begin(), lijst.end(), print);
	cout << endl;
	for_each(lijst2.begin(), lijst2.end(), print);
	cout << endl;
	for_each(lijst3.begin(), lijst3.end(), print);
	cout << endl;

	// inhoud printen met ostream
	copy(lijst3.begin(), --lijst3.end(), ostream_iterator<int>(cout, ", "));
	cout << *(--lijst3.end());
	cout << endl;
}