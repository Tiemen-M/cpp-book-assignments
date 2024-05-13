// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <iomanip>
using namespace std;

class Spaarbus {
private:
	int aantal20ct;
	int aantal50ct;
public:
	void vul(int a20, int a50) {
		aantal20ct = a20;
		aantal50ct = a50;
	}

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


void main_vb_9_2() {
	Spaarbus bus1, bus2;
	bus1.vul(12, 13);
	bus2.vul(2,17);

	bus1.print();
	bus2.print();
}