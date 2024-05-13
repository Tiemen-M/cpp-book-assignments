// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.10 I/O van objecten met friend-operatoren >> en <<
#include <iostream>
using namespace std;

namespace vb_10 {
	class Punt {
	private:
		int x, y;
	public:
		Punt(int x = 0, int y = 0) 
			: x(x), y(y) {
		}
		friend ostream& operator<<(ostream& uit, const Punt& p);
		friend istream& operator>>(istream& in, Punt& p);
	};
}

using namespace vb_10;

// Implementatie van de operatoren
ostream& vb_10::operator<<(ostream& uit, const Punt& p) {
	return uit << '(' << p.x << ',' << p.y << ')';
}

istream& vb_10::operator>>(istream& in, Punt& p) {
	return in >> p.x >> p.y;
}

void main_vb_10() {
	Punt A, B(-4, 5);
	cout << "Voer de coordinaten van punt A in:" << endl;
	cin >> A;
	cin.get();

	cout << A << endl;
	cout << B << endl;
}