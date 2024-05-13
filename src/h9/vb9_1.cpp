// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <iomanip>
using namespace std;

struct Spaarbus {
	int aantal20ct;
	int aantal50ct;

	void print() {
		cout << aantal20ct << " munten van 20 cent en "
			<< aantal50ct << " van 50 cent = "
			<< setprecision(2) << showpoint << fixed
			<< berekenInhoud() << endl;
	}

	double berekenInhoud() {
		return aantal20ct * 0.2 + aantal50ct * 0.5;
	}
};


void main_vb_9_1() {
	Spaarbus bus1, bus2;
	bus1.aantal20ct = 12;
	bus1.aantal50ct = 13;

	bus2.aantal20ct = 2;
	bus2.aantal50ct = 17;

	bus1.print();
	bus2.print();
}