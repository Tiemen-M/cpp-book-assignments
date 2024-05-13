// Created by Tiemen Molenaar in 2023
#include <iostream>
#include "double_array.h"
using namespace std;
using namespace double_array;

// Implementatie van klasse DoubleArray
DoubleArray::DoubleArray(unsigned n)
	: aantal(n), p(new double[n]) {
}

DoubleArray::DoubleArray(const DoubleArray& x)
	: aantal(x.aantal), p(new double[x.aantal]) {
	for (unsigned i = 0; i < aantal; ++i)
		p[i] = x.p[i];
}

DoubleArray& DoubleArray::operator=(const DoubleArray& x) {
	delete[] p;
	aantal = x.aantal;
	p = new double[aantal];
	for (unsigned i = 0; i < aantal; ++i)
		p[i] = x.p[i];
	return *this;
}

double& DoubleArray::operator[](int k) {
	if (k < 0 || k > (int) aantal) {
		cerr << "Out of range!!";
		exit(1);
	}
	return p[k];
}

DoubleArray::~DoubleArray() {
	delete[] p;
}

ostream& double_array::operator<<(ostream& uit, const DoubleArray& x) {
	uit << x.aantal << ';';
	for (unsigned i = 0; i < x.aantal; ++i)
		uit << x.p[i] << ';';
	return uit;
}

namespace double_array {
	int getInt(istream& in) {
		char ch;
		string number;
		while (in >> ch && isdigit(ch)) {
			number += ch;
		}
		return atoi(number.c_str());
	}

	double getDouble(istream& in) {
		char ch;
		string number;
		while (in >> ch && (isdigit(ch) || ch == '.')) {
			number += ch;
		}
		return atof(number.c_str());
	}
}

istream& double_array::operator>>(istream& in, DoubleArray& x) {
	// Vraag een nieuwe geheugen ruimte aan voor nieuwe groote
	delete[] x.p;
	x.aantal = getInt(in);
	x.p = new double[x.aantal];

	// Vul de nieuwe geheuigen ruimte
	for (unsigned i = 0; i < x.aantal; ++i)
		x[i] = getDouble(in);

	return in;
}

unsigned DoubleArray::getAantal() const {
	return aantal;
}