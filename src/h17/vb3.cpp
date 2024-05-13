// Created by Tiemen Molenaar in 2023
// Voorbeeld 17.3 Twee exceptie-klassen
#include <iostream>
using namespace std;

namespace vb_3 {
	// Definieer twee lege klassen voor excepties:
	class TeGrootPos {};
	class TeGrootNeg {};

	const int MAXINT = numeric_limits<int>::max();
	int telOp(int a, int b);
}
using namespace vb_3;

void main_vb_3() {
	int totaal;
	try {
		totaal = telOp(MAXINT, 100);
		cout << totaal << endl;
	}
	catch (TeGrootPos) {
		cerr << "Te groot positief resultaat" << endl;
	}
	catch (TeGrootNeg) {
		cerr << "Te groot negatief resultaat" << endl;
	}
}

int vb_3::telOp(int a, int b) {
	if (a > 0 && b > 0 && a > MAXINT - b)
		throw TeGrootPos();
	if (a < 0 && b < 0 && a < -MAXINT - 1 - b)
		throw TeGrootNeg();
	return a + b;
}