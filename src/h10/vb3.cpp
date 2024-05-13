// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define LAAT_ZIEN

namespace vb_3 {
	class Clublid {
	private:
		string naam;
		int lidnr;
	public:
		Clublid()
			: naam("Geen naam"), lidnr(0) {
			#ifdef LAAT_ZIEN
			cout << "default-constructor" << endl;
			#endif
		}
		Clublid(const char* naam, int nr = 0)
			: naam(naam), lidnr(nr) {
			#ifdef LAAT_ZIEN
			cout << "char*-constructor" << endl;
			#endif
		}
		Clublid(int nr)
			: naam("Geen naam"), lidnr(nr) {
			#ifdef LAAT_ZIEN
			cout << "int-constructor" << endl;
			#endif
		}
		Clublid(const Clublid& c)
			: naam(c.naam), lidnr(c.lidnr) {
			#ifdef LAAT_ZIEN
			cout << "copy-constructor" << endl;
			#endif
		}

		string toString() const {
			ostringstream os;
			os << naam << ", " << lidnr;
			return os.str();
		}
	};
}

using namespace vb_3;

void main_vb_3() {
	Clublid p1, p2, p3;

	p1 = 6;
	p2 = "Bommel";
	p3 = p2;

	cout << endl << "De drie objecten:" << endl;
	cout << p1.toString() << endl;
	cout << p2.toString() << endl;
	cout << p3.toString() << endl;
}