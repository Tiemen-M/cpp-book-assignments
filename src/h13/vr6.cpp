// Created by Tiemen Molenaar in 2023
// UIterking vraag 13.10.6
#include <iostream>
#include <list>
using namespace std;

void main_vr_6() {
	list<string> l;
	l.push_back("Een");
	l.push_back("Twee");
	l.push_back("Drie");

	list<string>::iterator pos, end = l.end();

	for (pos = l.begin(); pos != end; ++pos)
		cout << *pos << endl;
}