// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

namespace oef_3 {
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
		friend ostream& operator<<(ostream& uit, const Voorraad& x);

		Voorraad operator-() const {
			return Voorraad(-klein, -groot);
		}

		Voorraad operator-(const Voorraad& x) const {
			return Voorraad(klein - x.klein, groot - x.groot);
		}

		Voorraad operator*(double d) const {
			return Voorraad(
				static_cast<int>(static_cast<double>(klein) * d),
				static_cast<int>(static_cast<double>(groot) * d)
			);
		}

		friend Voorraad operator*(double d, const Voorraad& x) {
			return Voorraad(
				static_cast<int>(static_cast<double>(x.klein) * d),
				static_cast<int>(static_cast<double>(x.groot) * d)
			);
		}
	};
}

using namespace oef_3;

void main_oef_3() {
	Voorraad
		v1(1, 2),
		v2(10, 20),
		v3(100, 200),
		totaal, totaal2,totaal3;
	totaal = v1 + v2 + v3;
	cout << "Totale voorraad is " << totaal.toString() << endl;
	cout << setw(30) << setw(30) << v1 << setw(30) << v2 << setw(30) << v3 << endl;

	((totaal2 += v1) += v2) += v3;
	cout << "Totale voorraad is " << totaal2.toString() << endl;
	cout << setw(30) << setw(30) << v1 << setw(30) << v2 << setw(30) << v3 << endl;

	totaal3 += v1 += v2 += v3;
	cout << "Totale voorraad is " << totaal3.toString() << endl;
	cout << setw(30) << setw(30) << v1 << setw(30) << v2 << setw(30) << v3 << endl;

	cout << endl << "test nieuwe gedefineerde operatoren:" << endl;
	Voorraad a, b(2, 2), c(3, 3);
	cout << "a:" << a << " b:" << b << " c:" << c << endl;
	a = -b;
	cout << "a = -b dus a:" << a << endl;
	a = b - c;
	cout << "a = b - c dus a:" << a << endl;
	a = b * 1.5;
	cout << "a = b * 1.5 dus a:" << a << endl;
	a = 1.5 * b;
	cout << "a = 1.5 * b dus a:" << a << "(Werkt ook nu!)" << endl;
}

Voorraad Voorraad::operator+(const Voorraad& x) const {
	return Voorraad(klein + x.klein, groot + x.groot);
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

ostream& oef_3::operator<<(ostream& uit, const Voorraad& x) {
	return uit << "(" << x.klein << ", " << x.groot << ")";
}