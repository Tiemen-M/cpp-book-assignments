// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.19 Schrijven naar een stringstream
#include <iostream>
#include <sstream>
using namespace std;

namespace vb_19 {
	class Persoon {
	private:
		string naam;
		int nummer;
	public:
		Persoon(const string& n = "", int nr = 0)
			: naam(n), nummer(nr) {
		}

		string toString() {
			ostringstream os;
			os << nummer << ". " << naam << endl;
			return os.str();
		}
	};
}

using namespace vb_19;

void main_vb_19() {
	Persoon p1("Danielle", 1), p2("Welmer", 2);
	cout << p1.toString();
	cout << p2.toString();
}