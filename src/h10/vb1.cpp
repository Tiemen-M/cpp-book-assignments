// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace vb_1 {
	class Clublid {
	private:
		string naam;
		int lidnr;
	public:
		Clublid() : naam("Geen naam"), lidnr(0) {}
		Clublid(const string& naam) : naam(naam), lidnr(0) {}
		explicit Clublid(int nr) : naam("Geen naam"), lidnr(nr) {}
		Clublid(const string& naam, int nr) : naam(naam), lidnr(nr) {}

		string toString() const {
			ostringstream os;
			os << naam << ", " << lidnr;
			return os.str();
		}
	};
}

using namespace vb_1;

void main_vb_1() {
	Clublid
		lid1,
		lid2("Heleen"),
		lid3(3),
		lid4("Nikki", 4),
		lid5(lid4),
		lid6 = string("Tiemen");

	cout << lid1.toString() << endl;
	cout << lid2.toString() << endl;
	cout << lid3.toString() << endl;
	cout << lid4.toString() << endl;
	cout << lid5.toString() << endl;
	cout << lid6.toString() << endl;
}