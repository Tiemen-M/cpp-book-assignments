// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.9 I/O van objecten met behulp van lidfuncties
#include <iostream>
using namespace std;

namespace vb_9 {
	class Punt {
	private:
		int x, y;
	public:
		Punt(int x = 0, int y = 0)
			: x(x), y(y) {
		}

		void lees() {
			cin >> x >> y;
			cin.get();
		}

		void schrijf() {
			cout << '(' << x << ',' << y << ')';
		}
	};
}

using namespace vb_9;

void main_vb_9() {
	Punt A, B(-4, 5), C(10, 10);
	cout << "Voer de coordinaten van punt A in: " << endl;
	A.lees();

	A.schrijf();
	cout << endl;
	B.schrijf();
	cout.operator<<(endl);
	C.schrijf();
}