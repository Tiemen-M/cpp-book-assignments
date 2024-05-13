// Created by Tiemen Molenaar in 2023
// Voorbeeld 178.6 Excepties afgeleid van de basis-klasse Uitzondering
#include <iostream>
#include <sstream>
using namespace std;

namespace vb_6 {
	const int MAXINT = numeric_limits<int>::max();

	// Baissklasse voor excepties
	class BerekeningsExceptie {
	public:
		virtual string foutmelding() const {
			return string("Fout in berekening");
		}
	};

	// Afgeleide exceptie-klasse
	class TeGrootPos : public BerekeningsExceptie {
	private:
		int x, y;
	public:
		TeGrootPos(int x, int y)
			: x(x), y(y) {
		}
		virtual string foutmelding() const {
			return string("Te groot positief getal");
		}
	};

	// afgeleide exceptie-klasse
	class TeGrootNeg : public BerekeningsExceptie {
	private:
		int x, y;
	public:
		TeGrootNeg(int x, int y)
			: x(x), y(y) {
		}
		virtual string foutmelding() const {
			ostringstream os;
			os << x << " en " << y
				<< " leveren een te groot negatief getal";
			return os.str();
		}
	};

	int telOp(int a, int b);
	void tryOptellen(int a, int b);
}
using namespace vb_6;

void main_vb_6() {
	tryOptellen(1, 2);
	tryOptellen(MAXINT, 10);
	tryOptellen(-MAXINT, -10);
}

void vb_6::tryOptellen(int a, int b) {
	int resultaat;
	try {
		resultaat = telOp(a, b);
		cout << resultaat << endl;
	}
	catch (const BerekeningsExceptie& exc) {
		cerr << exc.foutmelding() << endl;
	}
}

int vb_6::telOp(int a, int b) {
	if (a > 0 && b > 0 && a < MAXINT - b)
		throw TeGrootPos(a, b);
	if (a < 0 && b < 0 && a < -MAXINT - 1 - b)
		throw TeGrootNeg(a, b);
	return a + b;
}