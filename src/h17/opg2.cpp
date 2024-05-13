// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 17.11.2
// Doel: programma van opgave 5 uit hoofstuk 12 met exceptions te voorzien (opd5.cpp)
#pragma warning( disable : 4290)
#include <iostream>
using namespace std;

namespace opg_2 {
	class DoubleArray {
	private:
		unsigned aantal;
		double* p;
	public:
		class IndexException {
			int index;
		public:
			IndexException(int index) : index(index) {}
			void what() {
				cerr << "Error: " << index << " is een ongeldige index." << endl;
			}
		};
		DoubleArray(unsigned n = 1);
		DoubleArray(const DoubleArray& x);
		DoubleArray& operator=(const DoubleArray& x);
		double& operator[](int k) throw(IndexException);
		~DoubleArray();
	};
}

using namespace opg_2;

void main_opg_2() {
	try {
		DoubleArray a(10);
		a[5] = 10.21;
		a[2] = 2023.9;
		cout << "a[5]=" << a[5] << endl;
		DoubleArray b(a);
		cout << "b[2]=" << b[2] << endl;
		b[30] = 10; // geeft een error
	}
	catch (DoubleArray::IndexException& exc) {
		exc.what();
	}
}

// Implementatie van DoubleArray
DoubleArray::DoubleArray(unsigned n)
	: aantal(n), p(new double[n]) {
}

DoubleArray::~DoubleArray() {
	delete[] p;
}

DoubleArray::DoubleArray(const DoubleArray& x)
	: aantal(x.aantal), p(new double[x.aantal]) {
	for (unsigned index = 0; index < aantal; index++) {
		p[index] = x.p[index];
	}
}

DoubleArray& DoubleArray::operator=(const DoubleArray& x) {
	aantal = x.aantal;
	for (unsigned index = 0; index < aantal; index++) {
		p[index] = x.p[index];
	}
	return *this;
}

double& DoubleArray::operator[](int k) throw(DoubleArray::IndexException) {
	// check of de index goed is gekozen
	if (k < 0 || k >= static_cast<int>(aantal)) throw(DoubleArray::IndexException(k));
		
	// geef waarde terug
	return p[k];
}