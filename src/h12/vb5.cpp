// Created by Tiemen Molenaar in 2023
// Voorbeeld 12.5 Copy-constructor en toekenningsoperatoren enindexoperater overgeladen
#include <iostream>
using namespace std;

namespace vb_5 {
	class IntArray {
	private:
		unsigned aantal;
		int* p;
	public:
		IntArray(unsigned n = 1);				// constructor en default-constructor
		IntArray(const IntArray& ix);			// copy-constructor
		IntArray& operator=(const IntArray& ix);// toekenningsoperator
		~IntArray();							// destructor
		int& operator[](unsigned k);			// overloading indexoperator
		void verander(unsigned nr, int waarde);
		void invoer();
		void print(const string& naam) const;
	};
}

using namespace vb_5;

void main_vb_5() {
	cout << "Hoeveel getallen wil je intikken? ";
	unsigned aantal;
	cin >> aantal;

	IntArray ia(aantal);
	ia.invoer();
	IntArray ib = ia;
	ib.verander(aantal - 1, 1234);
	IntArray ic;
	ic = ib;
	ic.verander(aantal - 1, 543);

	ia.print("ia");
	ib.print("ib");
	ic.print("ic");
}

void main_vb_5_auto() {
	cout << "Hoeveel getallen wil je intikken? ";
	unsigned aantal = 3;
	cout << aantal << endl;

	IntArray ia(aantal);
	ia[0] = 10;
	ia[1] = 20;
	ia[2] = 30;
	IntArray ib = ia;
	ib[aantal - 1] = 1234;
	IntArray ic;
	ic = ib;
	ic[aantal - 1] = 543;

	ia.print("ia");
	ib.print("ib");
	ic.print("ic");
}

// Default constructor
IntArray::IntArray(unsigned n)
	: aantal(n) , p(new int[aantal]) {
	for (unsigned i = 0; i < aantal; p[i++] = 0);
}

// Copy-constructor
IntArray::IntArray(const IntArray& ix)
	: aantal(ix.aantal), p(new int[aantal]) {
	for (unsigned i = 0; i < aantal; p[i] = ix.p[i++]);
}

// Toekenningsoperator
IntArray& IntArray::operator=(const IntArray& ix) {
	delete[] p;
	aantal = ix.aantal;
	p = new int[aantal];
	for (unsigned i = 0; i < aantal; p[i] = ix.p[i++]);
	return *this;
}

// Destructor
IntArray::~IntArray() {
	delete[] p;
}

// Overige lidfuncties
void IntArray::invoer() {
	for (unsigned i = 0; i < aantal; i++) {
		cout << "Tik het " << i + 1 << "e getal in ";
		cin >> p[i];
	}
	cin.get();
}

void IntArray::verander(unsigned nr, int waarde) {
	if (nr < aantal)
		p[nr] = waarde;
}

void IntArray::print(const string& naam) const {
	if (naam != "")
		cout << endl << naam << ':' << endl;
	for (unsigned i = 0; i < aantal; i++)
		cout << i << "e=" << p[i] << endl;
}

// overloading index operator
int& IntArray::operator[](unsigned k) {
	if (k < aantal)
		return p[k];
	else
		cout << "Error: Buiten array grenzen!" << endl;
	return p[0];
}