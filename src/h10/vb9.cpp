// Created by Tiemen Molenaar in 2023
// Voorbeeld 10.9 Coversie van klasse naar standaardtype
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

namespace vb_9 {
	class Clublid {
	private:
		string lidnaam;
		int lidnr;
	public:
		Clublid(const char* naam = "Geen naam", int nr = 0)
			: lidnaam(naam), lidnr(nr) {}
		operator int() const {
			return lidnr;
		}
	};
}

using namespace vb_9;

void main_vb_9() {
	Clublid oma("An", 80),
		opa("Cees", 81);

	cout << "Oma is " << static_cast<int>(oma);
	cout << " en opa " << static_cast<int>(opa) << " jaar." << endl;

	/*
	* Te ingewikeld om werkend te krijgen.
	ostringstream os;
	os.operator<<("Oma is")
		.operator<<(static_cast<int>(oma))
		.operator<<(" en opa ").operator<<(static_cast<int>(opa)).operator<<(" jaar.")
		.operator<<(endl);
	cout << os.str();
	*/
}