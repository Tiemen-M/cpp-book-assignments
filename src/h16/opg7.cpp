// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 16.14.7
#include <iostream>
#include <fstream>
#include "template_array.h"
using namespace std;
using namespace template_array;

namespace opg_7 {
	class Int {
	private:
		int i;
	public:
		Int(int i=0) : i(i) {}
		Int(char* str) : i(atoi(str)) {}
		Int(const char* str) : i(atoi(str)) {}
		operator int() {
			return i;
		}
	};
}
using namespace opg_7;

void main_opg_7a() {
	// create array
	TemplateArray<Int> arr(10);
	int q = 1;
	for (unsigned i = 0; i < arr.getSize(); ++i) {
		arr[i] = q;
		q *= 9;
	}

	// write to file
	ofstream("bestand8.txt") << arr << endl;
}

void main_opg_7b() {
	// read array from file
	TemplateArray<Int> arr;
	ifstream("bestand8.txt") >> arr;

	// print on screen
	for (unsigned i = 0; i < arr.getSize(); ++i)
		cout << arr[i] << endl;
}