// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace vb_2 {
	class Clublid {
	private:
		string naam;
		int lidnr;
	public:
		Clublid(const char* naam, int nr = 0)
			: naam(naam), lidnr(nr) {
			cout << "char*-constructor" << endl;
		}
		Clublid(int nr)
			: naam("Geen naam"), lidnr(nr) {
			cout << "int-constructor" << endl;
		}
		Clublid(const Clublid& c)
			: naam(c.naam), lidnr(c.lidnr) {
			cout << "copy-constructor" << endl;
		}

		string toString() const {
			ostringstream os;
			os << naam << ", " << lidnr;
			return os.str();
		}
	};
}

using namespace vb_2;

void main_vb_2() {
	cout << "De drie initialisaties worden uitgevoerd door:" << endl;
	Clublid lid2 = "Nina",
		lid3 = 3,
		lid5 = lid3;

	cout << endl << "De drie objecten:" << endl;
	cout << lid2.toString() << endl;
	cout << lid3.toString() << endl;
	cout << lid5.toString() << endl;
}