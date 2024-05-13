// Created by Tiemen Molenaar in 2023
// Voorbeeld 15.5 Een vector met figuren
#include <iostream>
#include <vector>
#include <list>
using namespace std;
#include "vb4.h"
using namespace vb_4;

void main_vb_5() {
	// vector
	vector<Figuur*> v;

	Figuur* f = new Rechthoek(6, 2);
	f->setSymbool('a');
	v.push_back(f);

	f = new Driehoek(5);
	f->setSymbool('b');
	v.push_back(f);

	f = new Rechthoek(6, 3);
	f->setSymbool('c');
	v.push_back(f);

	vector<Figuur*>::iterator pos, einde = v.end();
	for (pos = v.begin(); pos != einde; ++pos)
		(*pos)->teken();

	// list
	cout << endl << endl;
	list<Figuur*> l;

	f = new Rechthoek(6, 2);
	f->setSymbool('a');
	l.push_back(f);

	f = new Driehoek(5);
	f->setSymbool('b');
	l.push_back(f);

	f = new Rechthoek(6, 3);
	f->setSymbool('c');
	l.push_back(f);

	list<Figuur*>::iterator pos2, einde2 = l.end();
	for (pos2 = l.begin(); pos2 != einde2; ++pos2)
		(*pos2)->teken();
}