// Created by Tiemen Molenaar in 2023
// opdracht 12.10.1 en opdracht 2
#include <iostream>
#include <iomanip>
#include "opd_1_en_2.h"
using namespace std;
using namespace opd_1_en_2;

void main_opd_1_en_2() {
	Container c(50);
	c.voegtoe(1);
	c.voegtoe(9);
	c.voegtoe(1);
	c.voegtoe(4);
	c.voegtoe(1);
	c.voegtoe(2);
	c.voegtoe(3);
	c.voegtoe(5);
	c.print();
	cout << "1 komt " << c.zoek(1) << " keer voor." << endl;

	Container b(c);
	b.print();

	Container a;
	a = b;
	a.print();
}

// Implementatie van Container
Container::Container(int max)
	: maxAantal(max), aantal(0) {
	p = new int[max];
}

Container::~Container() {
	delete[] p;
	cout << "Destructor van Container" << endl;
}

void Container::voegtoe(int a) {
	// Als er nog ruimte is in de array
	if (aantal < maxAantal) {
		// voeg nieuwe int aan het einde van de array
		p[aantal++] = a;

		// laat de nieuwe int zinken zodat de array gesorteerd blijft van laag naar hoog
		for (unsigned i = aantal - 1; i > 1; i--) {
			int swap;
			int &a = p[i];
			int &b = p[i - 1];
			if (a < b) {
				swap = b;
				b = a;
				a = swap;
			}
			else break;
		}
	}
	else cout << "Sorry, de Container object is vol" << endl;
}

int Container::zoek(int a) const {
	int occurence = 0;
	// Ga de array langs totdat de element waarde groter is dan het te zoeken getal.
	// Als de te zoeken getal gevonden is bepaal hoevaak het voorkomt en stop daarna met zoeken.
	for (unsigned i = 0; i < aantal; i++) {
		if (p[i] == a)
			occurence++; 
		else if (p[i] > a)
			break;
		else
			continue;
	}
	return occurence;
}

void Container::print(int width) const {
	for (unsigned i = 0; i < aantal; i++)
		cout << right << setw(width) << p[i];
	cout << endl;
}

// Implementatie uitbreiding Container volgens opdracht 2
Container::Container(const Container& obj)
	: maxAantal(obj.maxAantal) , aantal(obj.aantal) {
	// deep copy van array
	p = new int[maxAantal];
	for (unsigned index = 0; index < aantal; index++)
		p[index] = obj.p[index];
}

Container& Container::operator=(const Container& right) {
	// verwijder de oude array en maak een nieuwe aan met de groote van de te kopieëren object
	delete[] p;
	p = new int[right.maxAantal];
	maxAantal = right.maxAantal;
	aantal = right.aantal;
	// Kopieer de array inhoud van right naar eigen array
	for (unsigned index = 0; index < aantal; index++)
		p[index] = right.p[index];
	// return this object so that it can be used in more complex statements
	return *this;
}