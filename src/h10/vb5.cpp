// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <sstream>

using namespace std;

namespace vb_5 {
	class Voorraad {
	private:
		int klein;
		int groot;
	public:
		Voorraad(int k = 0, int g = 0)
			: klein(k), groot(g) {}
		Voorraad operator+(const Voorraad& x) const;
		string toString() const;
		Voorraad& operator+=(const Voorraad& x);
	};
}

using namespace vb_5;

void main_vb_5() {
	Voorraad
		v1(1, 2),
		v2(10, 20),
		v3(100, 200),
		totaal, totaal2;
	totaal = v1 + v2 + v3;
	cout << "Totale voorraad is " << totaal.toString() << endl;
	totaal2 += v1 += v2 += v3;
	cout << "Totale voorraad is " << totaal2.toString() << endl;
}

Voorraad Voorraad::operator+(const Voorraad& x) const {
	return Voorraad(klein+x.klein,groot+x.groot);
}

string Voorraad::toString() const {
	ostringstream os;
	os << klein << " klein en " << groot << " groot.";
	return os.str();
}

Voorraad& Voorraad::operator+=(const Voorraad& x) {
	klein += x.klein;
	groot += x.groot;
	return *this;
}