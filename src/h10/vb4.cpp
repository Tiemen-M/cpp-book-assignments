// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <sstream>

using namespace std;

namespace vb_4 {
	class Voorraad {
	private:
		int klein;
		int groot;
	public:
		Voorraad(int k = 0, int g = 0)
			: klein(k), groot(g) {}
		Voorraad som(const Voorraad& x) const;
		string toString() const;
	};
}

using namespace vb_4;

void main_vb_4() {
	Voorraad v1(1, 2), v2(10, 20), totaal;

	totaal = v1.som(v2);
	cout << "Totale voorraad is " << totaal.toString() << endl;
}

Voorraad Voorraad::som(const Voorraad& x) const {
	Voorraad resultaat;
	resultaat.klein = klein + x.klein;
	resultaat.groot = groot + x.groot;
	return resultaat;
}

string Voorraad::toString() const {
	ostringstream os;
	os << klein << " klein en " << groot << " groot.";
	return os.str();
}