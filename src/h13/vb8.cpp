// Created by Tiemen Molenaar in 2023
//Voorbeeld 13.8 list
#include <iostream>
#include <list>
using namespace std;

void main_vb_8() {
	list<string> beestenlijst; // maag een lege lijst
	beestenlijst.push_back("olifant"); // achteraan toevoegen
	beestenlijst.push_back("paard");
	beestenlijst.push_back("zebra");

	beestenlijst.push_front("cavia");
	beestenlijst.push_front("baviaan");
	beestenlijst.push_front("anaconda");

	list<string>::iterator pos, einde = beestenlijst.end();

	for (pos = beestenlijst.begin(); pos != einde; ++pos)
		cout << *pos << endl;

}