// Created by Tiemen Molenaar in 2023
#ifndef TEMPLATE_ARRAY_H
#define TEMPLATE_ARRAY_H
#include <iostream>
#include <cctype>
using namespace std;

namespace template_array {
	template<typename T>
	class TemplateArray {
	private:
		unsigned size;
		T* p;
	public:
		// default constructor
		TemplateArray(unsigned size = 1);
		// copy-constructor
		TemplateArray(const TemplateArray<T>& x);
		// assignment-operator
		TemplateArray<T>& operator=(const TemplateArray<T>& x);
		// index-operator
		T& operator[](int k);
		// destructor
		~TemplateArray();
		// getSize
		unsigned getSize() const;
		// stream out operator<<
		template<typename T> friend ostream& operator<<(ostream& out, const TemplateArray<T>& x);
		// stream in operator>>
		template<typename T> friend istream& operator>>(istream& in, TemplateArray<T>& x);
	};

	template<typename T>
	ostream& operator<<(ostream& out, const TemplateArray<T>& x) {
		out << x.size << endl;
		for (unsigned i = 0; i < x.size; ++i) {
			out << x.p[i] << endl;
		}
		return out;
	}

	template<typename T>
	istream& operator>>(istream& in, TemplateArray<T>& x) {
		string item;
		
		// get array size
		in >> item;
		unsigned size = atoi(item.c_str());

		// read the contents into obj
		T* p = new T[size];
		for (unsigned i = 0; i < size; ++i) {
			in >> item;
			p[i] = T(item.c_str());
		}

		// delete old contents
		delete[] x.p;
		x.p = p;
		x.size = size;

		return in;
	}
}
#include "template_array.cpp"

#endif