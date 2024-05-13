// Created by Tiemen Molenaar in 2023
// Voorbeeld 13.10 Toepassing van enkele lidfuncties van list
#include <iostream>
#include <list>
using namespace std;

namespace vb_10 {
	void print(string s, list<int>::iterator first, list<int>::iterator last) {
		cout << s << ':' << endl;
		for (list<int>::iterator pos = first; pos != last; ++pos)
			cout << *pos << " ";
		cout << endl << endl;
	}
}

using namespace vb_10;

void main_vb_10() {
	// Begin met twee lege lijsten
	list<int> lijstA, lijstB;
	// Voeg drie getallen toe aan lijstA
	lijstA.push_back(5);
	lijstA.push_back(1);
	lijstA.push_back(10);

	// Voeg drie getallen toe aan lijstB
	lijstB.push_back(6);
	lijstB.push_back(15);
	lijstB.push_back(2);

	print("Lijst A", lijstA.begin(), lijstA.end());
	print("Lijst B", lijstB.begin(), lijstB.end());

	// Sorteer de lijsten
	lijstA.sort();
	lijstB.sort();

	// Meng de twee lijsten
	lijstA.merge(lijstB);
	print("Lijst A na het mengen", lijstA.begin(), lijstA.end());
	print("Lijst B", lijstB.begin(), lijstB.end());

}