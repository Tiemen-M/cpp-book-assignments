// Created by Tiemen Molenaar in 2023
// voorbeel 10.6 vermenigvuldiging object met een int
#include <iostream>
#include <sstream>
using namespace std;

namespace vb_6 {
	class Voorraad {
	private:
		int klein, groot;
	public:
		Voorraad(int k=0,int g=0)
			: klein(k),groot(g) {}
		
		Voorraad operator*(int d) {
			return Voorraad(klein * d, groot * d);
		}

		string toString() const {
			ostringstream os;
			os << klein << " klein en " << groot << " groot." << endl;
			return os.str();
		}
	};
}

using namespace vb_6;

void main_vb_6() {
	Voorraad v(1, 2), resultaat;

	resultaat = v * 3;
	cout << "Het resultaat is " << resultaat.toString();
}