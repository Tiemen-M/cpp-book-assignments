// Created by Tiemen Molenaar in 2023
// Uiterking vraag 13.10.8
#include <iostream>
#include <list>
using namespace std;

void main_vr_8() {
	int rij[] = { 3,7,11,13,15,23,24,35,40,63,121,132,144 };

	int* begin = rij, * einde = rij + (sizeof(rij) / sizeof(int));
	list<int> l(begin, einde);

	list<int>::iterator pos, end = l.end();
	for (pos = l.begin(); pos != end; ++pos) {
		cout << *pos << endl;
	}
}