// Created by Tiemen Molenaar in 2023
#ifndef TEMPLATE_ARRAY_CPP
#define TEMPLATE_ARRAY_CPP
#include <iostream>
#include "template_array.h"
using namespace std;
using namespace template_array;

// Implementatie van klasse TemplateArray<T>
template<typename T>
TemplateArray<T>::TemplateArray(unsigned size)
	: size(size), p(new T[size]) {
}

template<typename T>
TemplateArray<T>::TemplateArray(const TemplateArray<T>& x)
	: size(size), p(new T[size]) {
	for (unsigned i = 0; i < size; ++i)
		p[i] = x.p[i];
}

template<typename T>
TemplateArray<T>& TemplateArray<T>::operator=(const TemplateArray<T>& x) {
	// Vraag nieuw geheugen aan
	delete[] p;
	size = x.size;
	p = new T[size];

	// kopieer de nieuwe inhoud
	for (unsigned i = 0; i < size; ++i)
		p[i] = x.p[i];
}

template<typename T>
T& TemplateArray<T>::operator[](int k) {
	if (k < 0 || k > static_cast<int>(size)) {
		cerr << "Out of range!!!" << endl;
		exit(1);
	}
	return p[k];
}

template<typename T>
TemplateArray<T>::~TemplateArray() {
	delete[] p;
}

template<typename T>
unsigned TemplateArray<T>::getSize() const {
	return size;
}
#endif