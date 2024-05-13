// Created by Tiemen Molenaar in 2023
// Voorbeeld 17.4 Exceptie-klassen met inhoud
#include <iostream>
using namespace std;

namespace vb_4 {
	const int MAXINT = numeric_limits<int>::max();

	// Definieer twee exceptie-klassen met attributen
	class TeGrootPos {
	public:
		int x, y;
		TeGrootPos(int x, int y)
			: x(x), y(y) {
		}
	};

	class TeGrootNeg {
	public:
		int x, y;
		TeGrootNeg(int x, int y)
			: x(x), y(y) {
		}
	};

	int telOp(int a, int b);
}
using namespace vb_4;

void main_vb_4() {
	int resultaat;
	try {
		resultaat = telOp(168, 4);
		cout << resultaat << endl;

		resultaat = telOp(-MAXINT, -10);
		cout << resultaat << endl;
	}
	catch (TeGrootPos exc) {
		cerr << "De som van de getallen "
			<< exc.x << " en " << exc.y
			<< " is te groot." << endl;
	}
	catch (TeGrootNeg exc) {
		cerr << "De som van de getallen "
			<< exc.x << " en " << exc.y
			<< " is te negatief." << endl;
	}
}

int vb_4::telOp(int a, int b) {
	if (a > 0 && b > 0 && a > MAXINT - b)
		throw TeGrootPos(a, b);
	if (a < 0 && b < 0 && a < -MAXINT - 1 - b)
		throw TeGrootNeg(a, b);
	return a + b;
}