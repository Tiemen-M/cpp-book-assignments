// Created by Tiemen Molenaar in 2023
// opdracht 5
#include <iostream>
using namespace std;

namespace opd_5 {
	class DoubleArray {
	private:
		unsigned aantal;
		double* p;
	public:
		DoubleArray(unsigned n = 1);
		DoubleArray(const DoubleArray& x);
		DoubleArray& operator=(const DoubleArray& x);
		double& operator[](int k);
		~DoubleArray();
	};
}

using namespace opd_5;

void main_opd_5() {
	DoubleArray a(10);
	a[5] = 10.21;
	a[2] = 2023.9;
	cout << "a[5]=" << a[5] << endl;
	DoubleArray b(a);
	cout << "b[2]=" << b[2] << endl;
	b[30] = 10; // geeft een error
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

double& DoubleArray::operator[](int k) {
	// check of de index goed is gekozen
	if (k < 0 || k >= aantal) {
		cout << "Error: index exceeds array range!" << endl;
		exit(1);
	}
	// geef waarde terug
	return p[k];
}