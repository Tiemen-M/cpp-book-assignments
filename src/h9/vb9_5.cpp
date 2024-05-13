// Created by Tiemen Molenaar in 2023
// Voorbeeld 9.5 Som van twee objecten
#include <iostream>
#include <iomanip>
using namespace std;

namespace vb_9_5 {
	class Spaarbus {
	private:
		int aantal20ct;
		int aantal50ct;
	public:
		Spaarbus(int aantal20ct = 0, int aantal50ct = 0) :
			aantal20ct(aantal20ct), aantal50ct(aantal50ct) {}
		double berekenInhoud();
		void print();
		void som(const Spaarbus& s1, const Spaarbus& s2);
	};
}

void main_vb_9_5() {
	vb_9_5::Spaarbus bus1(5, 7), bus2(10, 8), totaal;

	totaal.som(bus1, bus2);
	totaal.print();
}

double vb_9_5::Spaarbus::berekenInhoud() {
	return aantal20ct * 0.2 + aantal50ct * 0.5;
}

void vb_9_5::Spaarbus::print() {
	cout << aantal20ct << " van 20 cent en "
		<< aantal50ct << " van 50 cent = "
		<< setprecision(2) << showpoint << fixed
		<< berekenInhoud()
		<< endl;
}

void vb_9_5::Spaarbus::som(const Spaarbus& s1, const Spaarbus& s2) {
	aantal20ct = s1.aantal20ct + s2.aantal20ct;
	aantal50ct = s1.aantal50ct + s2.aantal50ct;
}