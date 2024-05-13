// Created by Tiemen Molenaar in 2023
// Voorbeeld 9.6 object als functiewaarde
#include <iostream>
#include <iomanip>
using namespace std;

namespace vb_9_6 {
	class Spaarbus {
	private:
		int aantal20ct;
		int aantal50ct;
	public:
		Spaarbus(int aantal20ct = 0, int aantal50ct = 0) :
			aantal20ct(aantal20ct), aantal50ct(aantal50ct) {}
		double berekenInhoud() const;
		void print() const;
		Spaarbus som(const Spaarbus& k);
	};
};

void main_vb_9_6() {
	vb_9_6::Spaarbus bus1(5, 7), bus2(10, 8), totaal;

	totaal = bus1.som(bus2);
	totaal.print();
}

double vb_9_6::Spaarbus::berekenInhoud() const {
	return aantal20ct * 0.2 + aantal50ct * 0.5;
}

void vb_9_6::Spaarbus::print() const {
	cout << aantal20ct << " van 20 cent en "
		<< aantal50ct << " van 50 cent = "
		<< setprecision(2) << showpoint << fixed
		<< berekenInhoud()
		<< endl;
}

vb_9_6::Spaarbus vb_9_6::Spaarbus::som(const Spaarbus& k) {
	vb_9_6::Spaarbus temp;
	temp.aantal20ct = aantal20ct + k.aantal20ct;
	temp.aantal50ct = aantal50ct + k.aantal50ct;
	return temp;
}