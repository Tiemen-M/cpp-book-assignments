// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.8 Functie-Object
#include <iostream>
using namespace std;

namespace vb_8 {
	class MaakNegatief {
	public:
		void operator()(int& x) const {
			x = -x;
		}
	};
}

using namespace vb_8;

void main_vb_8() {
	int a = 100;
	MaakNegatief neg;
	neg(a);
	cout << "a = " << a << endl;
}