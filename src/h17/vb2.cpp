// Created by Tiemen Molenaar in 2023
// Voorbeeld 17.2 Twee verschillende int-excepties
#include <iostream>
using namespace std;

namespace vb_2 {
	const int MAXINT = numeric_limits<int>::max();
	int telOp(int a, int b);
}

using namespace vb_2;

void main_vb_2() {
	int totaal;
	try {
		totaal = telOp(10, 20);
		cout << totaal << endl;
		cout << telOp(MAXINT, 5);
	}
	catch (int fout) {
		switch (fout) {
		case 1:
			cerr << "Te groot positief resultaat";
			break;
		case 2:
			cerr << "Te groot negatief resultaat";
			break;
		}
		cout << endl;
	}
}

int vb_2::telOp(int a, int b) {
	if (a > 0 && b > 0 && a > MAXINT - b)
		throw 1;
	if (a < 0 && b < 0 && a < -MAXINT - 1 - b)
		throw 2;
	return a + b;
}
