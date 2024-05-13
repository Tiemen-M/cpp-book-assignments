// Created by Tiemen Molenaar in 2023
// Voorbeeld 13.9 Toepassing van enkele lidfuncties van list
#include <iostream>
#include <list>
using namespace std;

namespace vb_9 {
	void print(string s, list<string>::iterator first, list<string>::iterator last) {
		cout << s << ':' << endl;
		for (list<string>::iterator pos = first; pos != last; ++pos)
			cout << *pos << " ";
		cout << endl << endl;
	}
}

using namespace vb_9;

void main_vb_9() {
	// Begin met een lege lijst
	list<string> lijst;

	// voeg drie diren toe
	lijst.push_back("slak");
	lijst.push_back("zwaan");
	lijst.push_back("mier");
	print("start", lijst.begin(), lijst.end());

	// sorteer lijst
	lijst.sort();
	print("Gesorteerd", lijst.begin(), lijst.end());

	// keer de lijst om
	lijst.reverse();
	print("Omgekeerd", lijst.begin(), lijst.end());

	// voeg 3 slakken toe
	lijst.insert(lijst.begin(), 3, "slak");
	print("Drie slakken erbij", lijst.begin(), lijst.end());

	// alleen unieke elementen
	lijst.sort();
	lijst.unique();
	print("Een slak over", lijst.begin(), lijst.end());
}