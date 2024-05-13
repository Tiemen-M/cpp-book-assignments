// Created by Tiemen Molenaar in 2023
#pragma once
#include <iostream>
using namespace std;

namespace double_array {
	class DoubleArray {
	private:
		unsigned aantal;
		double* p;
	public:
		DoubleArray(unsigned n = 1);
		DoubleArray(const DoubleArray& x);
		DoubleArray& operator=(const DoubleArray& X);
		double& operator[](int k);
		~DoubleArray();
		friend ostream& operator<<(ostream& uit, const DoubleArray& x);
		friend istream& operator>>(istream& in, DoubleArray& x);
		unsigned getAantal() const;
	};
}