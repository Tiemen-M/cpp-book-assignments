// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 16.14.6
// Doel met behulp van << een DoubleArray object weer inlezen van een bestand.
#include <iostream>
#include <fstream>
#include "double_array.h"
using namespace std;
using namespace double_array;

void main_opg_6() {
	DoubleArray arr;
	ifstream("bestand7.txt") >> arr;

	for (unsigned i = 0; i < arr.getAantal(); ++i) {
		cout << arr[i] << endl;
	}
}