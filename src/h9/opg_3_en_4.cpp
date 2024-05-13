// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <iomanip>

using namespace std;

namespace opg_3_en_4 {
	class Punt {
	private:
		double x;
		double y;
	public:
		Punt(double xcoord = 0, double ycoord = 0);
		void print(bool) const;
		void som(const Punt&, const Punt&, bool = false);
	};

	Punt::Punt(double xcoord, double ycoord )
		: x(xcoord), y(ycoord) {}

	void Punt::print(bool end = true) const {
		cout << "( " << fixed << setprecision(1) << showpoint << x << ", "
			<< fixed << setprecision(1) << showpoint << y << " )";
		if (end)
			cout << endl;
	}

	void Punt::som(const Punt& a, const Punt& b, bool verbose) {
		x = a.x + b.x;
		y = a.y + b.y;
		if (verbose) {
			a.print(false);
			cout << " + ";
			b.print(false);
			cout << " = ";
			print();
		}
	}
}

using namespace opg_3_en_4;

void main_opg_3_en_4() {
	Punt p1(3.5, 4.2), p2(2.0, 6.0), antwoord;
	antwoord.som(p1, p2, true);
}