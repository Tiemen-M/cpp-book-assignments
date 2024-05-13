// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <sstream>

using namespace std;

namespace oef_1 {
	class Voertuig {
	private:
		string soort;
		int aantal_wielen;
	public:
		Voertuig(string soort = "Onbekend", int aantal_wielen = 0);
		Voertuig(int aantal_wielen);
		string toString() const;
	};
}

using namespace oef_1;

void main_oef_1() {
	Voertuig
		v1("Auto", 4),
		v2("Fiets", 2),
		v3("kinderfiets", 4),
		v4("Driewieler", 3),
		v5("boot"),
		v6("scoeter", 2),
		v7 = v1,
		v8(v5);

	cout << "De volgende voertuigen zijn gedeclareerd:" << endl;
	cout << v1.toString() << endl;
	cout << v2.toString() << endl;
	cout << v3.toString() << endl;
	cout << v4.toString() << endl;
	cout << v5.toString() << endl;
	cout << v6.toString() << endl;
	cout << v7.toString() << endl;
	cout << v8.toString() << endl;
}

Voertuig::Voertuig(string soort, int aantal_wielen)
	: soort(soort), aantal_wielen(aantal_wielen) {}

Voertuig::Voertuig(int aantal_wielen)
	: aantal_wielen(aantal_wielen), soort("Onbekend") {}

string Voertuig::toString() const {
	ostringstream uit;
	uit << "(Soort: " << soort << ", Aantal_wielen: " << aantal_wielen << ")";
	return uit.str();
}

