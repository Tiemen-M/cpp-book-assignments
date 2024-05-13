// Created by Tiemen Molenaar in 2023
#include <iostream>
#include "opd_1_en_2.h"
using namespace std;
using namespace opd_1_en_2;

namespace opd_4 {
	class Verzameling : public Container {
	public:
		Verzameling(unsigned size=10);
		void voegtoe(int value);
	};
}

using namespace opd_4;

void main_opd_4() {
	Verzameling v;
	v.voegtoe(1);
	v.voegtoe(2);
	v.voegtoe(3);
	v.voegtoe(1);
	v.voegtoe(3);

	v.print();
}

// Implementatie van Verzameling
Verzameling::Verzameling(unsigned size)
	: Container(size) {}

void Verzameling::voegtoe(int k) {
	if (zoek(k) == 0) {
		Container::voegtoe(k);
	}
	else {
		cout << "This element is already in container!" << endl;
	}
}