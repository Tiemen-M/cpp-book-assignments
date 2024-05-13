// Created by Tiemen Molenaar in 2023
// Voorbeeld 9.7 Getters en setters
#include <iostream>
#include <iomanip>
using namespace std;

namespace vb_9_7 {
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

		int getAantal20ct() const {
			return aantal20ct;
		}

		int getAantal50ct() const {
			return aantal50ct;
		}

		void setAantal20ct(int a20) {
			aantal20ct = a20;
		}

		void setAantal50ct(int a50) {
			aantal50ct = a50;
		}

	};
};

void main_vb_9_7() {
	vb_9_7::Spaarbus bus1, bus2(10, 8);

	bus1.setAantal20ct(20);

	cout << "Bus1 bevat "
		<< (bus1.getAantal20ct() > bus2.getAantal20ct() ? "meer" : "minder")
		<< " munten van 20ct dan bus2." << endl;
	//cin.get();
}

double vb_9_7::Spaarbus::berekenInhoud() const {
	return aantal20ct * 0.2 + aantal50ct * 0.5;
}

void vb_9_7::Spaarbus::print() const {
	cout << aantal20ct << " van 20 cent en "
		<< aantal50ct << " van 50 cent = "
		<< setprecision(2) << showpoint << fixed
		<< berekenInhoud()
		<< endl;
}

vb_9_7::Spaarbus vb_9_7::Spaarbus::som(const Spaarbus& k) {
	vb_9_7::Spaarbus temp;
	temp.aantal20ct = aantal20ct + k.aantal20ct;
	temp.aantal50ct = aantal50ct + k.aantal50ct;
	return temp;
}