// Created by Tiemen Molenaar in 2023
// voorbeel 10.7 De friend-operator
#include <iostream>
#include <sstream>
using namespace std;

namespace vb_7 {
	class Voorraad {
	private:
		int klein, groot;
	public:
		Voorraad(int k = 0, int g = 0)
			: klein(k), groot(g) {}

		Voorraad operator*(int d) const {
			return Voorraad(klein * d, groot * d);
		}

		friend Voorraad operator*(int d, const Voorraad& v) {
			return Voorraad(d * v.klein, d * v.groot);
		}

		string toString() const {
			ostringstream os;
			os << klein << " klein en " << groot << " groot." << endl;
			return os.str();
		}

		friend ostream& operator<<(ostream& uit, const Voorraad& v) {
			return uit << v.klein << " klein en " << v.groot << " groot." << endl;
		}
	};
}

using namespace vb_7;

void main_vb_7() {
	Voorraad v(1, 2), resultaat1, resultaat2;
	resultaat1 = 3 * v;
	resultaat2 = v * 5;
	cout << "De resultaten zijn:" << endl << resultaat1 << resultaat2;
}